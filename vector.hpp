#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ft_containers.hpp"

// typedef typename : You are not actually creating a new data type,but rather defining a new name for an existing type.

NAME_SPACE_START
template<class T, class Allocator = std::allocator<T>>
class vector
{
		// =============================================================================
		// ATTRIBUTS ===================================================================
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef Allocator::pointer								pointer;
		typedef Allocator::const_pointer						const_pointer;
		typedef T*												iterator;
		typedef const T*										const_iterator;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const iterator>	const_reverse_iterator;

		// =============================================================================
		// CONSTRUCTORS ================================================================
		explicit vector (const allocator_type& alloc = allocator_type())
		{

		};

		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
		{
			for(; n != 0; n--)
			{
				
			}
		};







};

NAME_SPACE_END
#endif