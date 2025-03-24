/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:47:12 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/20 16:33:58 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
    private:
        std::string _name;

    public:
        Zombie(std::string name);
        ~Zombie();
        void    announce(void);
} ;

void    randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif