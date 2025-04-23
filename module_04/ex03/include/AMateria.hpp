/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:35:02 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/23 09:55:45 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria {
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(std::string const& type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();

        std::string const&  getType() const;

        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
} ;

#endif

// an interface (pure virtual class) does not need to provide an implementation of a pure virtual function
