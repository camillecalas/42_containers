#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ft_containers.hpp"
# include "reverse_iterator.hpp"
# include "distance.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"

//TODO erase later
# include <vector>
std::vector<int> res;


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
	typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
	typedef typename ft::reverse_iterator<const iterator>	const_reverse_iterator;


	// =============================================================================
	// ATTRIBUTS ===================================================================
protected:
	allocator_type	_alloc;		// object allocate
	size_type 		_capacity;	// capacity of vector
	pointer			_start;		// point on the beginning of vector 
	pointer			_ptr;
	size_type 		_size;		// taille utilisee du vector : size


	// =============================================================================
	// CONSTRUCTORS ================================================================
	// Allocate return a pointer to the initial element in the block of storage
public:
	explicit 
	vector (const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _capacity(0), _start(NULL), _ptr(NULL),_size(0)
	{};

	explicit 
	vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _capacity(n), _start(_alloc.allocate(n)), _ptr(NULL), _size(n)
	{
		for(size_t i = 0; i < n; i++)
			_alloc.construct(_start + i, val);
	};

	//TODO pas sur pour ce constructeur
	template< class InputIt >
	vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _capacity(ft_distance(first, last)), _start(_alloc.allocate(ft_distance(first, last))), _ptr(NULL), _size(ft_distance(first, last))
	{};


	vector (const vector& x)
	{
		*this = x;
	}


	// =============================================================================
	// DESTRUCTORS =================================================================
	~vector()
	{
		destroy_vector();
	}

private:
	void
	destroy_vector()
	{
		if (_capacity)
		{
			for (size_t i = 0; i < _size; i++)
				_alloc.destroy(_start + i);
			_alloc.deallocate(_start, _capacity);
		}
	}


	// =============================================================================
	// OVERLOADS ===================================================================
public:
	vector&
	operator= (const vector& x)
	{
		if (this == &x)
			return (*this);
		destroy_vector();
		_capacity = x._capacity;
		_start = _alloc.allocate(x._capacity);
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
		return ((const_iterator)_start);
	}

	const_iterator 
	end() const
	{
		((const_iterator)(_start + _size));
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
		return ((*(_start + n)));
	}

	reference 
	at (size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("vector::at\n");
		return ((*(_start + n)));
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
		return ((*(_start + n)));
	}

	const_reference at (size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("vector::at\n");
		return ((*(_start + n)));
	}

	const_reference 
	front() const
	{
		return (*_start);
	}

	const_reference 
	back() const
	{
		return (*(_start + _size - 1));
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
			throw std::length_error("vector::reserve\n");

		pointer tmp = _alloc.allocate(n);
		for(size_t i = 0; i < _size; i++)
			_alloc.construct(tmp + i, *(_start + i));
		destroy_vector();
		_start = tmp;
		_capacity = n;
	}


	// =============================================================================
	// MODIFIERS ===================================================================
	void
	clear()
	{
		destroy_vector();
		_size = 0;
	}

	// If a reallocation happens, the storage is allocated using the container's allocator, which may throw exceptions on failure (for the default allocator, bad_alloc is thrown if the allocation request does not succeed).
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
		if (_size == 0)
			return ;
		_size -= 1;
		_alloc.destroy(_start + _size);
	}

	//TODO check for desallocate probably same than for assign!
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
	
		if (n < _size)
			(*this).erase(begin() + n, end());
		else
		{
			if (n > _capacity)
			{
				if (_capacity * 2 > n)
					reserve(_capacity * 2);
				else
					reserve(n);
			}
			for (; _size < n; _size++)
				_alloc.construct((_start + _size), val);
		}
	}

	//TODO not sure about the allocation
	//Any elements held in the container before the call are destroyed and replaced by newly constructed elements (no assignments of elements take place). This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
	//! DO NOT desallocate, only destroy
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

		//TODO not working because reallocation happens only if too small, if not it's destroy but not desallocate
		// destroy_vector();
		// _capacity = n;
		// _start = _alloc.allocate(n);
		// _size = n;
		// for(size_t i = 0; i < _size; i++)
		// 	_alloc.construct(_start + i, val);
	}


	void swap (vector& x)
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

template <class T, class Alloc>
void
swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	vector<T,Alloc> tmp;

	tmp = x;
	x = y;
	y = tmp; 
}

NAME_SPACE_END
#endif