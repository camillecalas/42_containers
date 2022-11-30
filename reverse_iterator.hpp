#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include "ft_containers.hpp"
# include "Iterator.hpp"

NAME_SPACE_START

template< class Iterator >
class reverse_iterator: public ft::iterator<typename iterator_traits<Iterator>::iterator_category,
											typename iterator_traits<Iterator>::value_type,
											typename iterator_traits<Iterator>::difference_type,
											typename iterator_traits<Iterator>::pointer,
											typename iterator_traits<Iterator>::reference>
{
		// =============================================================================
		// ATTRIBUTS ===================================================================
	public:
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type; 
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

	// current (protected)	the underlying iterator of which base() returns a copy
	protected:
		iterator_type	current;

	public:
		// =============================================================================
		// CONSTRUCTORS ================================================================
		reverse_iterator() : current()
		{}

		explicit reverse_iterator(iterator_type it_to_adapt) : current(it_to_adapt)
		{}

		template< class U >
		reverse_iterator(const reverse_iterator<U>& other)
		{
			current(other.base());
		}

		// =============================================================================
		// OVERLOADS ===================================================================

		// =============================================================================
		// ACCESSES THE UNDERLYING ITERATOR ============================================
		iterator_type base() const
		{
			return (current);
		}


		// =============================================================================
		// ASSIGN ANOTHER ITERATOR ADAPTOR =============================================
		template< class U >
		reverse_iterator& operator=(const reverse_iterator<U>& other)
		{
			if (*this == other)
				return (*this);
			current = other.base();
			return (*this);
		}


		// =============================================================================
		// ACCESSES THE POINTED-TO ELEMENT =============================================
		reference operator*() const
		{
			iterator_type tmp = current;
			return (*--tmp);
		}

		pointer operator->() const
		{
			return (&(operator*()));
		}


		// =============================================================================
		// ADVANCES/DECREMENTS THE ITERATOR ============================================
		reverse_iterator& operator++()
		{
			current--;
			return (*this);
		}

		reverse_iterator& operator--()
		{
			current++;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return (temp);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return (temp);
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(base() - n));
		}

		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator(base() + n));
		}

		reverse_iterator& operator+=(difference_type n)
		{
			current -= n;
			return (*this);
		}

		reverse_iterator& operator-=(difference_type n)
		{
			current += n;
			return (*this);
		}
};

// =============================================================================
// NON-MEMBERS FONCTIONS =======================================================

// =============================================================================
// ADVANCES THE ITERATOR =======================================================
template< class Iter >
reverse_iterator<Iter>
    operator+( typename reverse_iterator<Iter>::difference_type n,
               const reverse_iterator<Iter>& it )
{
	return (reverse_iterator<Iter>(it.base() - n));
}

// =============================================================================
// COMPUTES THE DISTANCE BETWEEN 2 ITERATORS ADAPTORS ==========================
template< class Iterator1, class Iterator2 >
typename reverse_iterator<Iterator1>::difference_type
    operator-( const reverse_iterator<Iterator1>& lhs,
               const reverse_iterator<Iterator2>& rhs )
{
	return (rhs.base() - lhs.base());
}


// =============================================================================
// COMPARES THE UNDERLYING ITERATORS ===========================================
template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() >= rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() <= rhs.base());
}



NAME_SPACE_END
#endif