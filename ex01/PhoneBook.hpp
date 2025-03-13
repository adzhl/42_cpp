/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:34:55 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/13 13:13:41 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
    private:
        Contact _array[8];
        int     _index;
        int     _contactCount;
    
    public:
        PhoneBook();
        void    addContact();
        void    displayContacts() const;
};

#endif