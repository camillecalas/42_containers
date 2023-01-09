#ifndef EQUAL_HPP
# define EQUAL_HPP

# include "ft_containers.hpp"
# include "Iterator.hpp"

NAME_SPACE_START

template< class InputIt1, class InputIt2 >
bool
equal (	InputIt1 first1, InputIt1 last1,
    	InputIt2 first2 )
{
	while (first1!=last1) 
	{
		if (!(*first1 == *first2))
			return (false);
		++first1; ++first2;
	}
	return true;
}

NAME_SPACE_END
#endif