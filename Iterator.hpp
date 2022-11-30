#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <cstddef>
# include "ft_containers.hpp"

NAME_SPACE_START

//! ITERATOR CATEGORIES:	
//For every LegacyIterator type It, a typedef std::iterator_traits<It>::iterator_category must be defined to be an alias to one of these tag types, to indicate the most specific category that It is in. Iterator category tags carry information that can be used to select the most efficient algorithms for the specific requirement set that is implied by the category.
//! ITERATOR CONCEPT:		
//For every input_iterator type It, either It::iterator_concept (if std::iterator_traits<It> is generated from primary template) or std::iterator_traits<It>::iterator_concept (if std::iterator_traits<It> is specialized) may be declared as an alias to one of these tags, to indicate the strongest iterator concept that It intends to model. 


// ITERATOR CATEGORIES:	input_iterator_tag corresponds to LegacyInputIterator.
// ITERATOR CONCEPT:	input_iterator_tag corresponds to input_iterator. 
struct input_iterator_tag { };	

// ITERATOR CATEGORIES: output_iterator_tag corresponds to LegacyOutputIterator.
// ITERATOR CONCEPT:	forward_iterator_tag corresponds to forward_iterator.
struct output_iterator_tag { };

// ITERATOR CATEGORIES:	forward_iterator_tag corresponds to LegacyForwardIterator.
// ITERATOR CONCEPT:	bidirectional_iterator_tag corresponds to bidirectional_iterator. 
struct forward_iterator_tag : public input_iterator_tag { };

// ITERATOR CATEGORIES:	bidirectional_iterator_tag corresponds to LegacyBidirectionalIterator. 
// ITERATOR CONCEPT:	random_access_iterator_tag corresponds to random_access_iterator.
struct bidirectional_iterator_tag : public forward_iterator_tag { };

// ITERATOR CATEGORIES:	random_access_iterator_tag corresponds to LegacyRandomAccessIterator.
// ITERAROT CONCEPT:	contiguous_iterator_tag corresponds to contiguous_iterator. 
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

//TODO Usefull ?
//! ITERATOR BASE CLASS:
// This is a base class template that can be used to derive iterator classes from it. It is not an iterator class and does not provide any of the functionality an iterator is expected to have.This base class only provides some member types, which in fact are not required to be present in any iterator type (iterator types have no specific member requirements), but they might be useful, since they define the members needed for the default iterator_traits class template to generate the appropriate instantiation automatically (and such instantiation is required to be valid for all iterator types).

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

//! ITERATOR TRAITS: 
// std::iterator_traits is the type trait class that provides uniform interface to the properties of LegacyIterator types. This makes it possible to implement algorithms only in terms of iterators. 
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