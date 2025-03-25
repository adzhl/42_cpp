/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:19:16 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/25 15:44:13 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
void replaceLine(std::string &line, const std::string &s1, const std::string &s2);


int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./sed <filename> <string to replace> <new string>\n"; return (1); }

    // Check s1 (string to replace)
    std::string s1 = argv[2];
    if (s1.empty()) {
        std::cerr << "Error: string to replace cannot be empty\n"; return (1); }

    // Open input file
    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Error: Cannot open file\n"; return (1); }
    if (input.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: Input file is empty\n"; return (1); }

    // Create output file
    // c++98 ofstream only accept const char *
    std::string outputFilename = std::string(argv[1]) + ".replace";
    std::ofstream output(outputFilename.c_str());
    if (!output) {
        std::cerr << "Error: Cannot create output file\n"; return (1); }

    // Extract and replace strings
    std::string line;
    while (std::getline(input, line)) {
        replaceLine(line, argv[2], argv[3]);
        output << line;
        if (!input.eof())
            output << '\n';
    }

    return (0);
}

/**
 * find() : returns the index/position of string found
 *        : returns npos if string is not found
 * 
 * <substring created> <replaced word> <substring created>
 */
void    replaceLine(std::string &line, const std::string &s1, const std::string &s2) {
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
        pos += s2.length();
    }
}
