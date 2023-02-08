#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ft_containers.hpp"
# include "equal.hpp"
# include "Iterator.hpp"
# include "reverse_iterator.hpp"
# include "distance.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"

# include <iostream>
# include <iterator>

NAME_SPACE_START

template<class T, class Allocator = std::allocator<T> >
class vector
{
	// =============================================================================
	// TYPEDEF =====================================================================
	// typedef typename: You are not actually creating a new data type,but rather defining a new name for an existing type.
public:
	typedef T												value_type;
	typedef Allocator										allocator_type;
	typedef std::size_t										size_type;
	typedef std::ptrdiff_t									difference_type;
	typedef value_type&										reference;
	typedef const value_type&								const_reference;
	typedef typename Allocator::pointer						pointer;
	typedef typename Allocator::const_pointer				const_pointer;
	typedef T*												iterator;
	typedef const T*										const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;


	// =============================================================================
	// ATTRIBUTS ===================================================================
protected:
	allocator_type	_alloc;		// object allocate
	size_type 		_capacity;	// capacity of vector
	pointer			_start;		// point on the beginning of vector 
	size_type 		_size;		// taille utilisee du vector : size


	// =============================================================================
	// CONSTRUCTORS ================================================================
	// Allocate return a pointer to the initial element in the block of storage
public:
	explicit 
	vector (const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _capacity(0), _start(NULL), _size(0)
	{};

	explicit 
	vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _capacity(n), _start(_alloc.allocate(n)), _size(n)
	{
		
		for(size_t i = 0; i < n; i++)
			_alloc.construct(_start + i, val);
	};

	template< class InputIt >
	vector (InputIt first, ENABLE_IF last, const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _capacity(ft::distance(first, last)), _start(_alloc.allocate(ft::distance(first, last))), _size(ft::distance(first, last))
	{
		for (size_t i = 0; first != last; first++, i++)
			_alloc.construct(_start + i, *first);
	};

	vector (const vector& x)
		:  _alloc(x._alloc), _capacity(x._size), _start(_alloc.allocate(x._capacity)), _size(x._size)
	{
		for(size_t i = 0; i < _size; i++)
			_alloc.construct(_start + i, *(x._start + i));
	}


	// =============================================================================
	// DESTRUCTORS =================================================================
	~vector()
	{
		_destroy_vector_args(_start, _size, _capacity);
	}


	// =============================================================================
	// ADDED FUNCTIONS =============================================================
private:
	void	
	_destroy_vector_args(pointer to_erase, size_t size, size_t capacity)
	{
		if (_capacity)
		{
			for (size_t i = 0; i < size; i++)
				_alloc.destroy(to_erase + i);
		}
		_alloc.deallocate(to_erase, capacity);
	}

	void
	_reserve_space(size_t nb_elem)
	{
		if ((_size + nb_elem) >= _capacity * 2)
			reserve(_size + nb_elem);
		else if ((_size + nb_elem) > _capacity)
			reserve(_size * 2);
	}


	// =============================================================================
	// OVERLOADS ===================================================================
public:
	vector&
	operator=(const vector& x)
	{
		if (this == &x)
			return (*this);

		_destroy_vector_args(_start, _size, _capacity);
		if (x._size > _capacity)
			_capacity = x._size;
		_start = _alloc.allocate(_capacity);
		_size = x._size;
		for(size_t i = 0; i < _size; i++)
			_alloc.construct(_start + i, *(x._start + i));
		return (*this);
	}


	// =============================================================================
	// ITERATORS ===================================================================
	iterator 
	begin()
	{
		return (_start);
	}

	iterator 
	end()
	{
		return (_start + _size);
	}

	reverse_iterator 
	rbegin()
	{
		return (reverse_iterator(_start + _size));
	}

	reverse_iterator 
	rend()
	{
		return (reverse_iterator(_start));
	}

	const_iterator
	begin() const
	{
		return (const_iterator(_start));
	}

	const_iterator 
	end() const
	{
		return (const_iterator(_start + _size));
	}

	const_reverse_iterator 
	rbegin() const
	{
		return (const_reverse_iterator(_start + _size));
	}

	const_reverse_iterator 
	rend() const
	{
		return (const_reverse_iterator(_start));
	}


	// =============================================================================
	// ELEMENTS ACCESS =============================================================
	reference 
	operator[] (size_type n)
	{
		return (*(_start + n));
	}

	reference 
	at (size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("vector::at\n");
		return (*(_start + n));
	}

	reference
	front()
	{
		return (*_start);
	}

	reference 
	back()
	{
		return (*(_start + _size - 1));
	}

	const_reference
	operator[] (size_type n) const
	{
		return (const_reference(*(_start + n)));
	}

	const_reference 
	at (size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("vector::at\n");
		return (const_reference(*(_start + n)));
	}

	const_reference 
	front() const
	{
		return (const_reference(*_start));
	}

	const_reference 
	back() const
	{
		return (const_reference(*(_start + _size - 1)));
	}


	// =============================================================================
	// CAPACITY ====================================================================
	size_type
	size() const
	{
		return (_size);
	}

	// return the max number of element that the vector can hold
	size_type
	max_size() const
	{
		return (_alloc.max_size());
	}

	size_type 
	capacity() const
	{
		return (_capacity);
	}

	bool
	empty() const
	{
		if (_size == 0)
			return (true);
		return (false);
	}

	void 
	reserve (size_type n)
	{
		if (n < _capacity)
			return ;
		else if (n > _alloc.max_size())
			throw std::length_error("vector::reserve");

		pointer tmp = _alloc.allocate(n);
		for(size_t i = 0; i < _size; i++)
			_alloc.construct(tmp + i, *(_start + i));
		_destroy_vector_args(_start, _size, _capacity);
		_start = tmp;
		_capacity = n;
	}


	// =============================================================================
	// MODIFIERS ===================================================================
	void
	clear()
	{
		if (_capacity)
		{
			for (size_t i = 0; i < _size; i++)
				_alloc.destroy(_start + i);
		}
		_size = 0;
	}

	void 
	push_back (const value_type& val)
	{
		if (_size >= _capacity)
		{
			if (_capacity == 0)
				reserve(1);
			else
				reserve(_capacity * 2);
		}
		_alloc.construct((_start + _size), val);
		_size += 1;
	}

	void
	pop_back()
	{
		_size -= 1;
		_alloc.destroy(_start + _size);
	}

	iterator
	erase (iterator position)
	{
		iterator	pos_save = position;
		for (; position + 1 != end(); position++)
		{
			_alloc.destroy(position);
			_alloc.construct(position, *(position + 1));
		}
		_alloc.destroy(position);
		_size -= 1;
		return (pos_save);
	}

	iterator 
	erase (iterator first, iterator last)
	{
		for (; first != last; last--)
			erase(first);
		return (first);
	}

	void
	resize (size_type n, value_type val = value_type())
	{
		if (n > max_size())
			throw std::length_error("vector::_M_fill_insert");
		else if (n < size())
			for (; _size > n; _size--)
				_alloc.destroy(_start + (_size - 1));
		else
		{
			if (n <= _capacity);
			else if (n > _size * 2)
				reserve(n);
			else
				reserve(_size * 2);
		}
			for (; _size < n; _size++)
				_alloc.construct((_start + _size), val);
			_size = n;
	}

	// Any elements held in the container before the call are destroyed and replaced by newly constructed elements (no assignments of elements take place). This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
	template <class InputIterator>
	void
	assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
	{
		size_t size_btw = ft::distance(first,last);
		reserve(size_btw);
		if (_capacity)
			for (size_t i = 0; i < _size; i++)
				_alloc.destroy(_start + i);
		for (size_t i = 0; first != last; first++, i++)
			_alloc.construct(_start + i, *first);
		_size = size_btw;
	}

	void
	assign (size_type n, const value_type& val)
	{
		reserve(n);
		if (_capacity)
			for (size_t i = 0; i < _size; i++)
				_alloc.destroy(_start + i);
		for(size_t i = 0; i < n; i++)
			_alloc.construct(_start + i, val);
		_size = n;
	}

	iterator 
	insert (iterator position, const value_type& val)
	{
		ptrdiff_t	pos = position - begin();
		int			x = 1;

		if (_capacity == 0)
			reserve(1);
		else if (_size >= _capacity)
			reserve (_capacity * 2);

		for (long i = _size; i > pos; i--, x++)
		{
			_alloc.construct(begin() + i, *(end() - x));
			_alloc.destroy(end() - x);
		}

		_alloc.construct(begin() + pos, val);
		_size += 1;
		return (begin() + pos);
	}

	void 
	insert (iterator position, size_type n, const value_type& val)
	{
		if (n == 0)
			return ;
		ptrdiff_t	pos = position - begin();
		int			x = 1;

		_reserve_space (n);

		for (long i = _size - 1; i >= pos; i--, x++)
		{
			_alloc.construct(begin() + i + n, *(end() - x));
			_alloc.destroy(end() - x);
		}
	
		for (size_t i = 0; i < n; pos++, i++)
			_alloc.construct(begin() + pos, val);

		_size += n;
	}

	template <class InputIterator>
	void
	insert (iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
	{
		ptrdiff_t	pos = ft::distance(_start, position);
		ptrdiff_t	nb_elem = ft::distance(first, last);
		size_t 		i = 0;

		if ((_size + nb_elem) > _capacity * 2)
			_capacity = (_size + nb_elem);
		else if ((_size + nb_elem) >= _capacity)
			_capacity = (_size * 2);

		pointer test = _alloc.allocate(_capacity);

		for (; i < (size_t)pos; i++)
			_alloc.construct(test + i, *(_start + i));

		for (; first != last; first++, i++)
			_alloc.construct(test + i, *first);

		for (; (size_t)pos < _size; i++, pos++)
			_alloc.construct(test + i, *(_start + pos));

		_destroy_vector_args(_start, _size, _capacity);
		_start = test;
		_size += nb_elem;
	}

	void 
	swap (vector& x)
	{
		allocator_type	tmp_alloc	= _alloc;
		size_type 		tmp_capacity= _capacity;
		pointer			tmp_start	= _start;
		size_type 		tmp_size	= _size;

		_alloc		= x._alloc;
		_capacity	= x._capacity;
		_start		= x._start;
		_size		= x._size;

		x._alloc 	= tmp_alloc;
		x._capacity = tmp_capacity;
		x._start	= tmp_start;	
		x._size		= tmp_size;
	}


	// =============================================================================
	// ALLOCATOR ===================================================================
	allocator_type 
	get_allocator() const
	{
		return (_alloc);
	}
};


// =============================================================================
// NON-MEMBER OVERLOADS ========================================================
template<class T, class Alloc>
bool
operator==(	const ft::vector<T,Alloc>& lhs,
			const ft::vector<T,Alloc>& rhs) 
{
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template< class T, class Alloc >
bool
operator!=( const ft::vector<T,Alloc>& lhs,
            const ft::vector<T,Alloc>& rhs )
{
	return (!(lhs == rhs));
}

template< class T, class Alloc >
bool
operator<(	const ft::vector<T,Alloc>& lhs,
        	const ft::vector<T,Alloc>& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class T, class Alloc >
bool
operator<=( const ft::vector<T,Alloc>& lhs,
            const ft::vector<T,Alloc>& rhs )
{
	return (!(rhs < lhs));
}

template< class T, class Alloc >
bool
operator>(	const ft::vector<T,Alloc>& lhs,
        	const ft::vector<T,Alloc>& rhs )
{
	return (rhs < lhs);
}

template< class T, class Alloc >
bool
operator>=( const ft::vector<T,Alloc>& lhs,
            const ft::vector<T,Alloc>& rhs )
{
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void
swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}

NAME_SPACE_END
#endif