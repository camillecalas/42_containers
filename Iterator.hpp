#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <cstddef>

# include "ft_containers.hpp"

NAME_SPACE_START

// =============================================================================
// DEFINES THE CATEGORY OF AN ITERATOR: each tag is an empty type ==============

// input_iterator_tag corresponds to LegacyInputIterator.
struct input_iterator_tag { };	

// output_iterator_tag corresponds to LegacyOutputIterator.
struct output_iterator_tag { };

// forward_iterator_tag corresponds to LegacyForwardIterator. 
struct forward_iterator_tag : public input_iterator_tag { };

// bidirectional_iterator_tag corresponds to LegacyBidirectionalIterator. 
struct bidirectional_iterator_tag : public forward_iterator_tag { };

// random_access_iterator_tag corresponds to LegacyRandomAccessIterator. 
struct random_access_iterator_tag : public bidirectional_iterator_tag { };


// =============================================================================
// ITERATOR BASE CLASS =========================================================
template <typename Category, typename T, typename Distance = ptrdiff_t,
          typename Pointer = T*, typename Reference = T&>
struct iterator 
{
	typedef T         value_type;
	typedef Distance  difference_type;
	typedef Pointer   pointer;
	typedef Reference reference;
	typedef Category  iterator_category;
};


// =============================================================================
// ITERATOR TRAITS =============================================================
/* std::iterator_traits is the type trait class that provides uniform interface to the properties of LegacyIterator types. This makes it possible to implement algorithms only in terms of iterators. */
template< class Iterator >
struct iterator_traits
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};
		
template< class T >
struct iterator_traits<T*>
{
	typedef ptrdiff_t					difference_type;
	typedef T							value_type;
	typedef T*							pointer;
	typedef T&							reference;
	typedef random_access_iterator_tag	iterator_category;
};
		
template< class T >
struct iterator_traits<const T*>
{
	typedef ptrdiff_t					difference_type;
	typedef T							value_type;
	typedef const T*					pointer;
	typedef const T&					reference;
	typedef random_access_iterator_tag	iterator_category;
};

NAME_SPACE_END
#endif