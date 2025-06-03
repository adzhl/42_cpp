/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:57:22 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/03 13:49:53 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, float>    _database;

        bool        validDate(std::string& date) const;
        bool        validValue(std::string& date, float& value) const;
        std::string trim(const std::string& str);
        float       getRate(const std::string& date) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange&    operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool    loadDatabase(const std::string& filename);
        void    processInput(const std::string& filename);
} ;

#endif

// std::map is an associative container
// stores elements as key-value pair
//  - Unique keys (no duplicates)
//  - Automatically sorted keys (by default, in ascending order)