/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:29:22 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/16 09:39:02 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const  DiamondTrap& other);
        DiamondTrap& operator=(const   DiamondTrap& other);
        ~DiamondTrap();

        void    attack(const std::string& target);
        void    whoAmI();
} ;

#endif

// Diamond Inheritance
//      A
//     / \
//    B   C
//     \ /
//      D
// when two derived classes (child) from the same base class (parent)
// and one grandchild is derived from the two derived classes (child)
// Two copies of the same object will exist
//
// This can be solved using: virtual inheritance
// Ensures only one shared instance of the base class is inherited
// Using a shared virtual base pointer