#!/bin/bash

make re

echo -e "\n\033[1;36m=== Basic Operations ===\033[0m"
./RPN "2 3 +"           # 5
./RPN "4 3 -"           # 1
./RPN "2 3 *"           # 6
./RPN "6 2 /"           # 3

echo -e "\n\033[1;36m=== Complex Expressions ===\033[0m"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"   # 42
./RPN "7 7 * 7 -"                    # 42
./RPN "1 2 * 2 / 2 * 2 4 - +"       # 0
./RPN "5 1 2 + 4 * + 3 -"           # 14

echo -e "\n\033[1;36m=== Edge Cases ===\033[0m"
./RPN "9"                            # 9 (single number)
./RPN "0 5 *"                        # 0 (multiplication by zero)
./RPN "5 0 /"                        # Error: division by zero
./RPN "1 2 3 4 5 + + + +"            # 15 (multiple additions)

echo -e "\n\033[1;36m=== Error Handling ===\033[0m"
./RPN ""                             # Error: empty input
./RPN "1 +"                          # Error: insufficient operands
./RPN "1 2 3 +"                      # Error: leftover numbers
./RPN "1 2 + 3 * -"                  # Error: invalid operation sequence
./RPN "a 2 +"                        # Error: invalid character
./RPN "(1 + 1)"                      # Error: parentheses not allowed
./RPN "1.5 2 +"                      # Error: decimal numbers not allowed
./RPN "10 2 +"                       # Error: numbers >=10 (input constraint)
./RPN "1 2 + 3 * 1000 -"             # Error: input can't be >=10

echo -e "\n\033[1;32mTests completed!\033[0m"