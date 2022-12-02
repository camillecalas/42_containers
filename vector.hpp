#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ft_containers.hpp"
# include "distance.hpp"

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
		size_type 		_size;		// taille utilisee du vector : size
		

		// =============================================================================
		// CONSTRUCTORS ================================================================
		// Allocate return a pointer to the initial element in the block of storage
	public:
		explicit vector (const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _capacity(0), _start(NULL), _size(0)
		{};

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _capacity(n), _start(_alloc.allocate(n)), _size(n)
		{
			for(size_t i = 0; i < n; i++)
				_alloc.construct(_start + i, val);
		};

		//TODO pas sur pour ce constructeur

		template< class InputIt >
		vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _capacity(ft_distance(first, last)), _start(_alloc.allocate(ft_distance(first, last))), _size(ft_distance(first, last))
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
				_alloc.construct(_start + i, *(x._start + i)); // x._start[i]
			return (*this);
		}


		// =============================================================================
		// ITERATORS ===================================================================
		iterator 
		begin()
		{
			return (_start);
		}
		const_iterator
		begin() const
		{
			return ((const_iterator)_start);
		}

		iterator 
		end()
		{
			return (_start + _size);
		}
		const_iterator 
		end() const
		{
			((const_iterator)(_start + _size));
		}

		reverse_iterator 
		rbegin()
		{
			return (reverse_iterator(_start + _size));
		}
		const_reverse_iterator 
		rbegin() const
		{
			return (const_reverse_iterator(_start + _size));
		}

		reverse_iterator 
		rend()
		{
			return (reverse_iterator(_start));
		}
		const_reverse_iterator 
		rend() const
		{
			return (const_reverse_iterator(_start));
		}


		// =============================================================================
		// CAPACITY ====================================================================
		void 
		reserve (size_type n)
		{
			_capacity = n;
			_start = _alloc.allocate(_capacity);

		}


		// =============================================================================
		// MODIFIERS ===================================================================
		// If a reallocation happens, the storage is allocated using the container's allocator, which may throw exceptions on failure (for the default allocator, bad_alloc is thrown if the allocation request does not succeed).
		void 
		push_back (const value_type& val)
		{
			if ((_size + 1) > _capacity)
			{
				(*this).reserve(_size);
			}
			_alloc.construct(_start + _size, val);
			_size += 1;
		}



};

NAME_SPACE_END
#endif