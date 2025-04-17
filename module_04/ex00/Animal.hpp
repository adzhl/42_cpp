/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:15:42 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/16 15:22:46 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        ~Animal();

        void    makeSound();
} ;

#endif