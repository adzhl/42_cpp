/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:56:59 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/09 12:24:26 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "Original array:\n";
    iter(arr, 5, printElement);

    iter(arr, 5, incrementElement);
    std::cout << "\nAfter incrementing:\n";
    iter(arr, 5, printElement);

    std::string strArr[] = {"hello", "world", "cpp"};
    std::cout << "\nString array:\n";
    iter(strArr, 3, printElement);

    return (0);
}
