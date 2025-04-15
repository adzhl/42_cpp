/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:16:27 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/14 16:10:08 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const  FragTrap& other);
        FragTrap& operator=(const   FragTrap& other);
        ~FragTrap();

        virtual void    attack(const std::string& target);
        void            highFivesGuys(void);
} ;

#endif