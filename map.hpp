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
// Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
class value_compare : public std::binary_function<value_type,value_type,bool>
{
	friend class map;

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

	//TODO to erase later
	void
	print_tree()
	{
		_rbt.printTree();
	}

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
	typedef typename ft::reverse_iterator<iterator> 						reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;


	// =============================================================================
	// ATTRIBUTS ===================================================================
protected:
	allocator_type	_alloc;
	value_compare 	_comp;
	red_black_tree	_rbt;
	size_t			_size;


	// =============================================================================
	// CONSTRUCTORS ================================================================
	// Allocate return a pointer to the initial element in the block of storage
public:
	explicit 
	map(const key_compare &comp = key_compare(), const Allocator &alloc = allocator_type())
		: _alloc(alloc), _comp(value_compare(comp)), _rbt(_comp), _size(0)
	{}

	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type()) 
		: _alloc(alloc), _comp(value_compare(comp)), _rbt(_comp), _size(0)
	{
		insert(first, last);
	}

	map(const map & copy)
	{
		*this = copy;
	}

	// =============================================================================
	// DESTRUCTORS =================================================================
	~map()
	{
		if (_size != 0)
			_rbt.delete_tree();
		_rbt.destroy_tnull();
	}

	// =============================================================================
	// OVERLOADS ===================================================================
public:
	map&
	operator=(const map& x)
	{
		if (this == &x)
			return (*this);
		//TODO todo
		return (*this);
	}



	// =============================================================================
	// ITERATORS ===================================================================
	iterator
	begin()
	{
		return (iterator(_rbt.begin(), _rbt.get_root(), _rbt.get_tnull()));
	}

	const_iterator
	begin() const
	{
		return (const_iterator(_rbt.begin(), _rbt.get_root(), _rbt.get_tnull()));
	}

	iterator
	end()
	{
		return (iterator(_rbt.get_tnull(), _rbt.get_root(), _rbt.get_tnull()));
	}

	const_iterator
	end() const
	{
		return (const_iterator(_rbt.get_tnull(), _rbt.get_root(), _rbt.get_tnull()));
	}


	// =============================================================================
	// ELEMENTS ACCESS =============================================================
	mapped_type &
	operator[](const key_type & k)
	{
		iterator it = iterator(_rbt.find(value_type(k.mapped_type(k))), _rbt.get_root(), _rbt.get_tnull());
		if (it == end())
		{
			iterator it2 = iterator(_rbt.insert(value_type(k.mapped_type(k)), _rbt.get_root(), _rbt.get_tnull()));
			retrurn (it2->second);
		}
		return (it->second);
	}

	// iterator
	// find(const key_type & k)
	// {
	// 	if (_size == 0)
	// 		return (end());
	// 	Node<value_type> *node = _rbt.find(value_type(k, mapped_type()));
	// 	if (node == _rbt.get_tnull())
	// 		return (end());
	// 	return(iterator(node, _rbt.get_tnull(), _rbt.get_root()));
	// }

	// const_iterator
	// find(const key_type & k) const
	// {
	// 	if (_size == 0)
	// 		return (end());
	// 	Node<value_type> *node = _rbt.find(value_type(k, mapped_type()));
	// 	if (node == _rbt.get_tnull())
	// 		return (end());
	// 	return(const_iterator(node, _rbt.get_tnull(), _rbt.get_root()));
	// }


	// iterator
	// find(const key_type & k)
	// {
	// 	return(iterator(_rbt.find(value_type(k, mapped_type())), _rbt.get_root(), _rbt.get_tnull()));
	// }

	// const_iterator
	// find(const key_type & k) const
	// {
	// 	return(const_iterator(_rbt.find(value_type(k, mapped_type()), _rbt.get_root(), _rbt.get_tnull())));
	// }


	iterator
	find(const key_type & k)
	{
		return(iterator(_rbt.find(value_type(k, mapped_type())), _rbt.get_root(), _rbt.get_tnull()));
	}

	const_iterator
	find(const key_type & k) const
	{
		return(const_iterator(_rbt.find(value_type(k, mapped_type()), _rbt.get_root(), _rbt.get_tnull())));
	}






	// =============================================================================
	// MODIFIERS ===================================================================
	// The single element versions (1) return a pair, with its member pair::first set to an iterator pointing to either the newly inserted element or to the element with an equivalent key in the map. The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.
	ft::pair<iterator, bool>
	insert(const value_type &data)
	{
		if (_rbt.insert(data) == ft::nullptr)
			return(ft::make_pair(iterator(_rbt.find(data),  _rbt.get_root(), _rbt.get_tnull()), false));
		_size++;
		return (ft::make_pair(iterator(_rbt.find(data), _rbt.get_root(), _rbt.get_tnull()), true));
	}

	// The versions with a hint (2) return an iterator pointing to either the newly inserted element or to the element that already had an equivalent key in the map.
	iterator
	insert (iterator position, const value_type& val)
	{
		(void)position;
		_rbt.insert(val);
		return (iterator(_rbt.find(val), _rbt.get_root(), _rbt.get_tnull()));
	}

	template <class InputIterator>  
	void 
	insert (InputIterator first, InputIterator last)
	{
		for (; first != last; first++)
			_rbt.insert(*first);	
	}

	void
	erase (iterator position)
	{
		if (_size == 0)
			return ;
		if (_rbt.deleteNode(*position))
			_size--;
	}

	// =============================================================================
	// GETTERS =====================================================================
	key_compare
	key_comp() const
	{
		return (_comp);
	}



};




template <class Key, class T, class Compare, class Alloc>
bool	operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename ft::map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
	typename ft::map<Key, T, Compare, Alloc>::const_iterator ite = lhs.end();
	typename ft::map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
	while (it != ite)
	{
		if (*it != *it2)
			return (false);
		it++;
		it2++;
	}
	return (true);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>
void	swap(ft::map<Key, T, Compare, Alloc>& x, ft::map<Key, T, Compare, Alloc>& y)
{
	if (x == y)
		return ;
	x.swap(y);
}



NAME_SPACE_END
#endif
