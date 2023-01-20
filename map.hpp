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
# include "red_black_tree.hpp"
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
	// =============================================================================
	// TYPEDEF =====================================================================
public:
	typedef Key 															key_type;
	typedef T 																mapped_type;
	typedef ft::pair<const Key, T> 											value_type;
	typedef std::size_t 													size_type;
	typedef std::ptrdiff_t 													difference_type;
	typedef Compare															key_compare;	


//! ================================================================================
// CLASS VALUE COMPARE	============================================================
class value_compare : public std::binary_function<value_type,value_type,bool>
{
	friend class map;

protected:
	key_compare	comp;
	value_compare(key_compare c) : comp(c) {}

public:
	bool
	operator() (const value_type & x, const value_type & y) const
	{
		return (comp(x.first, y.first));
	}
// public:
// 	typedef bool	result_type;
// 	value_type		first_argument_type; 
// 	value_type		second_argument_type;
};
//! ================================================================================


	// =============================================================================
	// TYPEDEF =====================================================================
public:					
	typedef typename ft::RedBlackTree<value_type, value_compare>			red_black_tree;
	typedef Allocator 														allocator_type;
	typedef value_type &													reference;
	typedef const value_type &												const_reference;
	typedef typename Allocator::pointer 									pointer;
	typedef typename Allocator::const_pointer 								const_pointer;
	typedef typename ft::iterator_map<value_type, Node<value_type> >		iterator;
	typedef typename ft::iterator_map<const value_type, Node<value_type> >	const_iterator;
	typedef ft::reverse_iterator<iterator> 									reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;


	// =============================================================================
	// ATTRIBUTS ===================================================================
protected:
	allocator_type	_alloc;
	value_compare 	_comp;
	red_black_tree	_rbt;


	// =============================================================================
	// CONSTRUCTORS ================================================================
	// Allocate return a pointer to the initial element in the block of storage
public:
	// map()
	// {}

	explicit 
	map(const key_compare &comp = key_compare(), const Allocator &alloc = allocator_type())
		: _alloc(alloc), _comp(value_compare(comp)), _rbt(_comp)
	{}

	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type()) 
		: _alloc(alloc), _comp(value_compare(comp)), _rbt(_comp)
	{
		insert(first, last);
	}


	// =============================================================================
	// GETTERS =====================================================================
	key_compare
	key_comp() const
	{
		return (_comp);
	}





	// iterator
	// find(const key_type & k)
	// {

	// }



};

NAME_SPACE_END
#endif
