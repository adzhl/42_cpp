/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:37:44 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/21 09:58:57 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Ice: public AMateria {
    public:
        Ice();
        Ice(const Ice& other);
        Ice&    operator=(const Ice& other);
        virtual ~Ice();

        AMateria*   clone() const;
        void        use(ICharacter& target);
} ;

#endif