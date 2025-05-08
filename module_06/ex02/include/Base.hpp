/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:51:06 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/08 13:00:07 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <ctime>
# include <cstdlib>
# include <iostream>

class Base {
    public:
        virtual ~Base();
} ;

class A : public Base {} ;

class B : public Base {} ;

class C : public Base {} ;

Base*   generate();
void    identify(Base* p);
void    identify(Base& p);

#endif
