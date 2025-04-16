/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:38:56 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/16 08:44:05 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// Inheritance
// derived class (child) : base class (parent)
// inherits attributes and methods from parent
class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        void    attack(const std::string& target);
        void    guardGate();

    protected:
        static const int    DEFAULT_HP = 100;
        static const int    DEFAULT_EP = 50;
        static const int    DEFAULT_AD = 20;
} ;

#endif