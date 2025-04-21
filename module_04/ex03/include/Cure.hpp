/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:43:43 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/21 09:58:51 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Cure: public AMateria {
    public:
        Cure();
        Cure(const Cure& other);
        Cure&    operator=(const Cure& other);
        virtual ~Cure();

        AMateria*   clone() const;
        void        use(ICharacter& target);
} ;

#endif