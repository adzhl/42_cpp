/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:29:22 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/14 16:11:40 by abinti-a         ###   ########.fr       */
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

        void    whoAmI();
} ;



#endif