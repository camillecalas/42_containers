#ifndef DISTANCE_HPP
# define DISTANCE_HPP

# include "ft_containers.hpp"
# include "Iterator.hpp"

NAME_SPACE_START

template< class InputIt >
typename std::iterator_traits<InputIt>::difference_type
distance(InputIt first, InputIt last)
{
	typename std::iterator_traits<InputIt>::difference_type increment = 0;
	for (; first != last; first++)
		increment++;
	return (increment);
}

NAME_SPACE_END
#endif