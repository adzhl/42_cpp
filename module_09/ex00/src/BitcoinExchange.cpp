/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:58:21 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/11 10:21:19 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_database = other._database;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}



bool    BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream data(filename.c_str());
    if (!data) { std::cerr << RED << "Error: Cannot open database file!\n" << RESET; return (false); }

    if (data.peek() == std::ifstream::traits_type::eof()) { std::cerr << RED << "Error: database is empty!\n" << RESET; return (false); }

    std::string header;
    std::getline(data, header);
    if (header != "date,exchange_rate") { std::cerr << RED << "Error: Wrong database header! Must be <date,exchange_rate>\n" << RESET; }

    std::string line;
    while (std::getline(data, line)) {
        std::string date, value;
        std::stringstream ss(line);

        if (!std::getline(ss, date, ',') || !std::getline(ss, value)) { std::cerr << RED << "Error: line in database not following this format <date,exchange_rate>\n" << RESET; return (false); }

        date = trim(date);
        if (!validDate(date)) { std::cerr << RED << "Error: database date invalid!\n" << RESET; return (false); }

        char* endptr;
        float rate = std::strtof(value.c_str(), &endptr);
        if (*endptr != '\0') { std::cerr << RED << "Error: database value not a number!\n" << RESET; return (false); }

        _database[date] = rate;
    }
    return (true);
}

void    BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream data(filename.c_str());
    if (!data) { std::cerr << "Error: Cannot open input file!\n"; return; }

    if (data.peek() == std::ifstream::traits_type::eof()) { std::cerr << RED << "Error: input file is empty!\n" << RESET; return; }

    std::string header;
    std::getline(data, header);
    if (header != "date | value") { std::cerr << RED << "Error: Wrong header! Must be <date | value>\n" << RESET; }

    std::string line;
    while (std::getline(data, line)) {
        std::string date, strValue;
        std::stringstream ss(line);

        if (!std::getline(ss, date, '|') || !std::getline(ss, strValue)) {
            std::cerr << RED << "Error: bad input => " << YELLOW << line << '\n' << RESET;
            continue;
        }

        date = trim(date);
        if (!validDate(date)) continue;

        strValue = trim(strValue);
        float value;
        if (!validValue(strValue, value)) continue;

        float rate = getRate(date);
        std::cout << date << " => " << value << " = " << (rate * value) << '\n';
    }
}

// lower_bound() : returns iterator to the first element
// if date is less than the first element in the map container, the iterator will return .begin()
float   BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

    if ((it != _database.end() && it->first == date) || it == _database.begin()) { return (it->second); }

    --it;
    return (it->second);
}


// Helper functions
std::string BitcoinExchange::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");

    if (start == std::string::npos) return ("");

    return (str.substr(start, end - start + 1));
}

//  Rule of leap year calculation:
//      Rule 1: year is divisible by 4
//      Rule 2: if year is not divisible by 100 => Leap year!
//              if year is divisible by 100 proceed to rule 3
//      Rule 3: if year is divisible by 400 => Leap year!
//
//  Earth’s orbit isn’t exactly 365.25 days (it’s ~365.2422 days).
//  Adding a leap day every 4 years (% 4) overcounts by ~11 minutes per year.
//  After ~400 years, this adds up to 3 extra days.
//  The % 100 and % 400 rules remove these extra days.
bool BitcoinExchange::validDate(std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') { std::cerr << RED << "Error: Wrong date format! Must be <YYYY-MM-DD>\n" << RESET; return (false); }

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;

        if (!std::isdigit(date[i])) { std::cerr << RED << "Error: Non-digits detected in date!\n" << RESET; return (false); }
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31) { std::cerr << RED << "Error: Date does not exist!\n" << RESET; return (false); }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) { std::cerr << RED << "Error: Month only has 30 days!\n" << RESET; return (false); }

    if (month == 2) {
        bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (leapYear ? 29 : 28)) { std::cerr << RED << "Error: February in this year only has " << (leapYear ? "29 " : "28 ") << "days!\n" << RESET; return (false); }
    }

    return (true);
}

bool BitcoinExchange::validValue(std::string& input, float& value) const {
    if (input.empty()) { std::cerr << RED << "Error: no input.\n" << RESET; return (false); }

    char* endptr;
    value = strtof(input.c_str(), &endptr);

    if (*endptr != '\0') { std::cerr << RED << "Error: input not a number.\n" << RESET; return (false); }

    if (value < 0) { std::cerr << RED << "Error: not a positive number.\n" << RESET; return (false); }

    if (value > 1000.0f) { std::cerr << RED << "Error: too large a number.\n" << RESET; return (false); }

    return (true);
}
