#ifndef MAP_HPP
#define MAP_HPP

#define BLACK 0
#define RED 1

# include "ft_containers.hpp"
# include "pair.hpp"
# include "Iterator.hpp"
# include "reverse_iterator.hpp"
# include "nullptr.hpp"
# include "iterator_map.hpp"
// # include "distance.hpp"
// # include "enable_if.hpp"
// # include "is_integral.hpp"
// # include "lexicographical_compare.hpp"

# include <iostream>

//TODO erase later
# include <map>
std::map<int, int> salut;

NAME_SPACE_START
template <class Key, class T, class Compare = std::less<Key>,
		  class Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
//! ================================================================================
// STRUCTURE NODE	================================================================
public:
typedef struct s_node
{
	// =============================================================================
	// ATTRIBUTS ===================================================================
	ft::pair<const Key, T>	data;
	size_t					color;
	struct s_node			*parent;
	struct s_node			*left;
	struct s_node			*right;

	// =============================================================================
	// CONSTRUCTORS ================================================================
	s_node(ft::pair<const Key, T> data) : data(data), color(RED)
	{}

	// =============================================================================
	// GETTERS =====================================================================
	const Key &
	key() { return (data.first); }

	T &
	value() { return (data.second); }

} Node;
//! ================================================================================


	// =============================================================================
	// TYPEDEF =====================================================================
public:
	typedef Key 									key_type;
	typedef T 										mapped_type;
	typedef ft::pair<const Key, T> 					value_type;
	typedef std::size_t 							size_type;
	typedef std::ptrdiff_t 							difference_type;
	typedef Compare									key_compare;
	//TODO alloc with RedBlack TREE
	typedef Allocator 								allocator_type;
	typedef value_type &							reference;
	typedef const value_type &						const_reference;
	typedef typename Allocator::pointer 			pointer;
	typedef typename Allocator::const_pointer 		const_pointer;
	// TODO check on iterator on map
	typedef T *										iterator;
	typedef const T *								const_iterator;
	typedef ft::reverse_iterator<iterator> 			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;


//! ================================================================================
// CLASS VALUE COMPARE	============================================================
class value_compare : public std::binary_function<value_type,value_type,bool>
{
	// friend class map;

protected:
	key_compare	comp;
	value_compare(key_compare c) : comp(c) {}

public:
	typedef bool	result_type;
	value_type		first_argument_type; 
	value_type		second_argument_type;

	bool
	operator() (const value_type & x, const value_type & y) const
	{
		return (comp(x.first, y.first));
	}
};
//! ================================================================================




	// =============================================================================
	// ATTRIBUTS ===================================================================
protected:
	allocator_type	_alloc;
	key_compare 	_comp;
	pointer			_root;


	// =============================================================================
	// CONSTRUCTORS ================================================================
	// Allocate return a pointer to the initial element in the block of storage
public:
	map()
	{}

	explicit 
	map(const Compare &comp, const Allocator &alloc = Allocator()) : _alloc(alloc), _comp(comp), pointer(NULL)
	{}

// 	template <class InputIterator>
// 	map(InputIterator first, InputIterator last,
// 		const key_compare &comp = key_compare(),
// 		const allocator_type &alloc = allocator_type())
// 	{}
};

NAME_SPACE_END
#endif
