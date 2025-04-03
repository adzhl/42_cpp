/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:19:16 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/03 14:16:05 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

// ifstream : Open and check input file
// peek()   : reads the next character from the input stream without extracting it
//          : returns the next character in the input string
//
// ofstream : Create output file
// c++98 ofstream only accept const char *
// automatically handles opening and closing files
int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./sed <filename> <string to replace> <new string>\n"; return (1); }

    if (!checkS1((std::string)argv[2])) { return (1); };

    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Error: Cannot open file\n"; return (1); }
    if (input.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: Input file is empty\n"; return (1); }

    std::string outputFilename = std::string(argv[1]) + ".replace";
    std::ofstream output(outputFilename.c_str());
    if (!output) {
        std::cerr << "Error: Cannot create output file\n"; return (1); }

    std::string line;
    while (std::getline(input, line)) {
        replaceLine(line, argv[2], argv[3]);
        output << line;
        if (!input.eof())
            output << '\n';
    }

    return (0);
}

// Check s1 (string to replace)
bool    checkS1(std::string s1) {
    if (s1.empty()) {
        std::cerr << "Error: string to replace cannot be empty\n"; return (false); }
    return (true);
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


// ifstream : Reads from files
// open : Opens a file manually
// in C when using open() you must manually close()
// ifstream/ofstream auto closes on object destruction
// std::ifstream file("example.txt") is the same as 
//      std::ifstream file;  
//      file.open("example.txt");
//      file.close();
// Must close before reopening and freeing resources early (Long-running function that keeps file open for a while)


// // Open and check input file
// // peek() : reads the next character from the input stream without extracting it
// //        : returns the next character in the input string
// std::ifstream   handleInput(char *argv) {
//     std::ifstream input(argv);
//     if (!input) {
//         std::cerr << "Error: Cannot open file\n"; return (std::ifstream()); }
//     if (input.peek() == std::ifstream::traits_type::eof()) {
//         std::cerr << "Error: Input file is empty\n"; return (std::ifstream()); }
//     return (input);
// }

// // Create output file
// // c++98 ofstream only accept const char *
// std::ofstream   handleOutput(char *argv) {
//     std::string outputFilename = std::string(argv) + ".replace";
//     std::ofstream output(outputFilename.c_str());
//     if (!output) {
//         std::cerr << "Error: Cannot create output file\n"; return (std::ofstream()); }
//     return (output);
// }
