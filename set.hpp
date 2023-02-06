#ifndef SET_HPP
#define SET_HPP

#define BLACK 0
#define RED 1

# include "ft_containers.hpp"
# include "pair.hpp"
# include "Iterator.hpp"
# include "reverse_iterator.hpp"
# include "nullptr.hpp"
# include "iterator_map.hpp"
# include "red_black_tree.hpp"
# include "lexicographical_compare.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"

# include <iostream>


NAME_SPACE_START

template<class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> > 
class set
{
	// =============================================================================
	// TYPEDEF =====================================================================
public:
	typedef Key 															key_type;
	typedef Key 															value_type;
	typedef Compare															key_compare;
	typedef key_compare														value_compare;
	typedef std::size_t 													size_type;
	typedef std::ptrdiff_t 													difference_type;
	typedef typename ft::RedBlackTree<value_type, value_compare>			red_black_tree;
	typedef Allocator 														allocator_type;
	typedef value_type &													reference;
	typedef const value_type &												const_reference;
	typedef typename Allocator::pointer 									pointer;
	typedef typename Allocator::const_pointer								const_pointer;
	typedef typename ft::iterator_map<const value_type, Node<value_type> >		iterator;
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
	set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _comp(comp), _rbt(_comp), _size(0)
	{} 

	template <class InputIterator>
	set(InputIterator first, InputIterator last,
		const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type()) 
		: _alloc(alloc), _comp(comp), _rbt(_comp), _size(0)
	{
		insert(first, last);
	}

	set(const set & copy)
	:  _alloc(copy._alloc), _comp(copy._comp), _rbt(_comp), _size(copy._size)
	{
		*this = copy;
	}

	// =============================================================================
	// DESTRUCTORS =================================================================
	~set()
	{
		if (_size != 0)
			_rbt.delete_tree();
		_rbt.destroy_tnull();
	}

	// =============================================================================
	// OVERLOADS ===================================================================
public:
	set&
	operator=(const set& x)
	{
		if (this == &x)
			return (*this);
		_comp = x._comp;
		_alloc = x._alloc;
		_rbt.delete_tree();
		insert(x.begin(), x.end());
		_size = x._size;

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

	reverse_iterator
	rbegin()
	{
		return (reverse_iterator(end()));
	}

	const_reverse_iterator 
	rbegin() const
	{
		return (const_reverse_iterator(end()));
	}
	
	reverse_iterator
	rend()
	{
		return (reverse_iterator(begin()));
	}
	
	const_reverse_iterator
	rend() const
	{
		return (const_reverse_iterator(begin()));
	}


	// =============================================================================
	// CAPACITY ====================================================================
	size_type
	size() const
	{
		return (_size);
	}

	bool
	empty() const
	{
		return (_rbt.empty());
	}

	size_type
	max_size() const
	{
		return (_rbt.max_size());
	}


	// =============================================================================
	// OPERATIONS ==================================================================
	iterator
	find(const key_type & k)
	{
		return(iterator(_rbt.find(_rbt.get_root(),k), _rbt.get_root(), _rbt.get_tnull()));
	}

	const_iterator
	find(const key_type & k) const
	{
		return(const_iterator(_rbt.find(_rbt.get_root(), k), _rbt.get_root(), _rbt.get_tnull()));
	}

	size_type 
	count(const key_type& k) const
	{
		const_iterator it = find(k);
		if (it == end())
			return (0);
		return (1);
	}

	iterator
	lower_bound (const key_type& k)
	{
		return (iterator(_rbt.lower_bound_rbt(k), _rbt.get_root(), _rbt.get_tnull()));
	}
	
	const_iterator lower_bound (const key_type& k) const
	{
		return (const_iterator(_rbt.lower_bound_rbt(k), _rbt.get_root(), _rbt.get_tnull()));
	}

	iterator
	upper_bound (const key_type& k)
	{
		return (iterator(_rbt.upper_bound_rbt(k), _rbt.get_root(), _rbt.get_tnull()));
	}
	 
	const_iterator
	upper_bound (const key_type& k) const
	{
		return (const_iterator(_rbt.upper_bound_rbt(k), _rbt.get_root(), _rbt.get_tnull()));
	}

	ft::pair<const_iterator,const_iterator>
	equal_range (const key_type& k) const
	{
		return (ft::make_pair(lower_bound(k), upper_bound(k)));
	}


	ft::pair<iterator,iterator>
	equal_range (const key_type& k)
	{
		return (ft::make_pair(lower_bound(k), upper_bound(k)));
	}



	// =============================================================================
	// MODIFIERS ===================================================================
	ft::pair<iterator, bool>
	insert(const value_type &data)
	{
		if (_rbt.insert(data) == _nullptr)
			return(ft::make_pair(iterator(_rbt.find(_rbt.get_root(), data),  _rbt.get_root(), _rbt.get_tnull()), false));
		_size++;
		return (ft::make_pair(iterator(_rbt.find(_rbt.get_root(), data), _rbt.get_root(), _rbt.get_tnull()), true));
	}

	iterator
	insert (iterator position, const value_type& val)
	{
		(void)position;
		insert(val);
		return (iterator(_rbt.find(_rbt.get_root(), val), _rbt.get_root(), _rbt.get_tnull()));
	}

	template <class InputIterator>  
	void 
	insert (InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			insert(*first);
			first++;
		}
	}

	void
	erase (iterator position)
	{
		if (_size == 0)
			return ;
		if (_rbt.deleteNode(*position))
			_size--;
	}
	
	size_type
	erase (const key_type& k)
	{
		if (_size == 0)
			return (0);
		iterator it = find(k);
		if (it == end())
			return (0);
		erase(it);
		return (1);
	}

	void
	erase (iterator first, iterator last)
	{
		for (; first != last; _size--)
			_rbt.deleteNode(*(first++));
	}

	void
	clear()
	{
		if (_size != 0)
			_rbt.delete_tree();
		_size = 0;

	}

private:
	template <class U> 
	void _swap ( U& a, U& b )
	{
		U tmp = a;
		a = b;
		b = tmp;
	}

public:
	void swap (set& x)
	{
		size_t tmp = x._size;
		x._size = _size;
		_size = tmp;

		_swap(_rbt, x._rbt);
	}
	
	// =============================================================================
	// GETTERS =====================================================================
	key_compare
	key_comp() const
	{
		return (key_compare());
	}

	value_compare
	value_comp() const
	{
		return (_comp);
	}

};


template <class Key, class Compare, class Allocator>
void
swap(ft::set<Key, Compare, Allocator>& x, ft::set<Key, Compare, Allocator>& y)
{
	x.swap(y);
}

template <class Key, class Compare, class Allocator>
bool	operator==(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (!(lhs < rhs) && !(lhs > rhs));
}

template <class Key, class Compare, class Allocator>
bool	operator!=(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class Compare, class Allocator>
bool	operator<(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class Compare, class Allocator>
bool	operator<=(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (!(rhs < lhs));
}

template <class Key, class Compare, class Allocator>
bool	operator>(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (rhs < lhs);
}

template <class Key, class Compare, class Allocator>
bool	operator>=(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (!(lhs < rhs));
}

NAME_SPACE_END
#endif