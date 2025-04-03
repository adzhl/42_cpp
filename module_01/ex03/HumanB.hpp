/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:25:21 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/03 12:03:59 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
    private:
        std::string _name;
        Weapon*     _weapon;

    public:
        HumanB(std::string name);
        void    attack() const;
        void    setWeapon(Weapon* weapon);
} ;

#endif