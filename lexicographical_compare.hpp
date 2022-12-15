#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

# include "ft_containers.hpp"
# include "Iterator.hpp"

NAME_SPACE_START

template <class InputIterator1, class InputIterator2>
bool 
lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1)
			return false;
		else if (*first1<*first2)
			return true;
		++first1; ++first2;
	}
  	return (first2!=last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool
lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        if (comp(*first1, *first2))
            return true;
        if (comp(*first2, *first1))
            return false;
    }
    return (first1 == last1) && (first2 != last2);
}

NAME_SPACE_END
#endif