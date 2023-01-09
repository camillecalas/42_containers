#ifndef PAIR_HPP
# define PAIR_HPP

# include "ft_containers.hpp"
// # include "equal.hpp"
// # include "Iterator.hpp"
// # include "reverse_iterator.hpp"
// # include "distance.hpp"
// # include "enable_if.hpp"
// # include "is_integral.hpp"
// # include "lexicographical_compare.hpp"

// # include <iostream>
// #include <iterator>


NAME_SPACE_START

template< class T1, class T2 > 
struct pair
{

	// =============================================================================
	// TYPEDEF =====================================================================
	typedef T1	first_type;
	typedef T2	second_type;


	// =============================================================================
	// ATTRIBUTS ===================================================================
	first_type	first;
	second_type	second;


	// =============================================================================
	// CONSTRUCTORS ================================================================
	pair()
	{}

	pair( const T1& x, const T2& y ) : first(x), second(y)
	{}

	template< class U1, class U2 >
	pair( const pair<U1, U2>& p ) : first(p.first), second(p.second)
	{}


	// =============================================================================
	// DESTRUCTORS =================================================================
	~pair()
	{}


	// =============================================================================
	// OVERLOADS ===================================================================
	pair& 
	operator=( const pair& other )
	{
		if (this == &other)
			return (*this);
		first = other.first;
		second = other.second;
		return (*this);
	}
};


// =============================================================================
// NON-MEMBER OVERLOADS ========================================================
template <class T1, class T2>  
bool 
operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (lhs.first==rhs.first && lhs.second==rhs.second);
}

template <class T1, class T2>  
bool 
operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(lhs==rhs));
}

template <class T1, class T2>  
bool 
operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
}

template <class T1, class T2>  
bool 
operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(rhs<lhs));
}

template <class T1, class T2>  
bool 
operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (rhs<lhs); 
}

template <class T1, class T2>  
bool 
operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(lhs<rhs));
}


// =============================================================================
// MAKE PAIR ===================================================================
template <class T1,class T2>
pair<T1,T2> 
make_pair (T1 x, T2 y)
{
	return ( pair<T1,T2>(x,y) );
}

NAME_SPACE_END
#endif