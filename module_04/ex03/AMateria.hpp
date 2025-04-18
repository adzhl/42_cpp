/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:35:02 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 15:40:25 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria {
    protected:

    public:
        AMateria();
        AMateria(std::string const& type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        ~AMateria();

        std::string const&  getType() const;

        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
} ;

#endif