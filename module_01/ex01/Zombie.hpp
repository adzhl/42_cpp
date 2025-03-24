/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:48:41 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/24 09:11:50 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class   Zombie {
    private:
        std::string _name;
    
    public:
        Zombie();
        ~Zombie();
        void    announce(void);
        void    setName(std::string name);
} ;

Zombie* zombieHorde( int N, std::string name );

#endif