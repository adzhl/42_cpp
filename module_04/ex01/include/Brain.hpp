/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:47:46 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 10:07:05 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain& other);
        Brain&  operator=(const Brain& other);
        ~Brain();

        
} ;

#endif