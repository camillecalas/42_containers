#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>

# include "ft_containers.hpp"
# include "Iterator.hpp"

NAME_SPACE_START

template< typename Iterator >
class reverse_iterator
{
	// =============================================================================
	// ATTRIBUTS ===================================================================
	// _current (protected)	the underlying iterator of which base() returns a copy
protected:
	Iterator	_current;
	typedef reverse_iterator<Iterator> traits_type;


	// =============================================================================
	// TYPEDEF =====================================================================
	//TODO not sure why no ft::iterator_traits ?
public:
	typedef Iterator												iterator_type;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::reference			reference;


	// =============================================================================
	// CONSTRUCTORS ================================================================
public:
	reverse_iterator() : _current()
	{}

	explicit 
	reverse_iterator(iterator_type it_to_adapt) : _current(it_to_adapt)
	{}

	template< class U >
	reverse_iterator(const reverse_iterator<U>& other) : _current(other.base())
	{}
	

	// =============================================================================
	// OVERLOADS ===================================================================

	// =============================================================================
	// ACCESSES THE UNDERLYING ITERATOR ============================================
	iterator_type
	base() const
	{
		return (_current);
	}


	// =============================================================================
	// ASSIGN ANOTHER ITERATOR ADAPTOR =============================================
	//TODO careful no = in 98?
	template<class U>
	reverse_iterator& 
	operator=(const reverse_iterator<U>& other)
	{
		if (*this == other)
			return (*this);
		_current = other.base();
		return (*this);
	}


	// =============================================================================
	// ACCESSES THE POINTED-TO ELEMENT =============================================
	reference
	operator*() const
	{
		Iterator tmp = _current;
		return (*--tmp);
	}

	pointer
	operator->() const
	{
		return (&(operator*()));
	}

	reference
	operator[](difference_type n) const 
	{
		return *(*this + n);
	}


	// =============================================================================
	// ADVANCES/DECREMENTS THE ITERATOR ============================================
	


	reverse_iterator& 
	operator++()
	{
		_current--;
		return (*this);
	}

	reverse_iterator&
	operator--()
	{
		_current++;
		return (*this);
	}

	reverse_iterator
	operator++(int)
	{
		reverse_iterator temp = *this;
		_current--;
		return (temp);
	}

	reverse_iterator
	operator--(int)
	{
		reverse_iterator temp = *this;
		_current++;
		return (temp);
	}

	reverse_iterator
	operator+(difference_type n) const
	{
		return (reverse_iterator(base() - n));
	}

	reverse_iterator
	operator-(difference_type n) const
	{
		return (reverse_iterator(base() + n));
	}

	reverse_iterator& 
	operator+=(difference_type n)
	{
		_current -= n;
		return (*this);
	}

	reverse_iterator&
	operator-=(difference_type n)
	{
		_current += n;
		return (*this);
	}

};


// =============================================================================
// NON-MEMBERS FONCTIONS =======================================================

// =============================================================================
// ADVANCES THE ITERATOR =======================================================
template< class Iter >
typename ft::reverse_iterator<Iter>
operator+( typename reverse_iterator<Iter>::difference_type n,
               const reverse_iterator<Iter>& it )
{
	return (reverse_iterator<Iter>(it.base() - n));
}


// =============================================================================
// COMPUTES THE DISTANCE BETWEEN 2 ITERATORS ADAPTORS ==========================
template< class Iterator1, class Iterator2 >
typename ft::reverse_iterator<Iterator1>::difference_type
operator-(	const reverse_iterator<Iterator1>& lhs,
        	const reverse_iterator<Iterator2>& rhs )
{
	return (rhs.base() - lhs.base());
}


// =============================================================================
// COMPARES THE UNDERLYING ITERATORS ===========================================
template< class Iterator1, class Iterator2 >
bool 
operator==( const reverse_iterator<Iterator1>& lhs,
            const reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator!=( const ft::reverse_iterator<Iterator1>& lhs,
            const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator<(	const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator<=( const ft::reverse_iterator<Iterator1>& lhs,
            const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() >= rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator>(	const ft::reverse_iterator<Iterator1>& lhs,
        	const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator>=( const ft::reverse_iterator<Iterator1>& lhs,
            const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() <= rhs.base());
}

// =============================================================================
template< class Iterator >
bool
operator==( const reverse_iterator<Iterator>&lhs,
			const reverse_iterator<Iterator>&rhs)
{
	return (lhs.base() == rhs.base());
}

template< class Iterator >
bool
operator!=( const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs )
{
	return (lhs.base() != rhs.base());
}

template< class Iterator >
bool
operator<(	const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs )
{
	return (lhs.base() > rhs.base());
}

template< class Iterator >
bool
operator<=( const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs )
{
	return (lhs.base() >= rhs.base());
}

template< class Iterator >
bool
operator>(	const reverse_iterator<Iterator>& lhs,
        	const reverse_iterator<Iterator>& rhs )
{
	return (lhs.base() < rhs.base());
}

template< class Iterator >
bool
operator>=( const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs )
{
	return (lhs.base() <= rhs.base());
}

NAME_SPACE_END
#endif