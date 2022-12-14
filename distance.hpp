#ifndef DISTANCE_HPP
# define DISTANCE_HPP

# include "ft_containers.hpp"
# include "Iterator.hpp"

NAME_SPACE_START

template< class InputIt >
typename ft::iterator_traits<InputIt>::difference_type
distance(InputIt first, InputIt last)
{
	typename ft::iterator_traits<InputIt>::difference_type increment = 0;
	for (; first != last; ++first)
		increment++;
	return (increment);
}

NAME_SPACE_END
#endif