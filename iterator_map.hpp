#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP

# include "ft_containers.hpp"


NAME_SPACE_START

template <class T, class Node>
class iterator_map
{
	// =============================================================================
	// TYPEDEF =====================================================================
public:
	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;
	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
	typedef	Node 		node_type;
	typedef Node *		node_ptr;
	typedef Node &		node_ref;
	

	// =============================================================================
	// ATTRIBUTS ===================================================================
private:
	node_ptr	_current;
	node_ptr	_root;
	node_ptr	_end;

	// =============================================================================
	// CONSTRUCTORS ================================================================
public:
	iterator_map() : _current(ft::nullptr), _root(ft::nullptr), _end(ft::nullptr)
	{}

	iterator_map(const node_ptr &current, const node_ptr &root, const node_ptr &end)
		: _current(current), _root(root), _end(end)
	{}

	iterator_map(const iterator_map & copy)
		: _current(copy._current), _root(copy._root), _end(copy._end)
	{}
		
	// =============================================================================
	// DESTRUCTORS =================================================================
	~iterator_map()
	{}

	// =============================================================================
	// OVERLOADS ===================================================================
	iterator_map&
	operator=(const iterator_map& x)
	{
		if (this == &x)
			return (*this);

		_current = x._current;
		_root = x._root;
		_end = x._end;
		return (*this);
	}

	operator iterator_map<const T, Node>(void) const
	{
		return (iterator_map<const T, Node>(_current, _root, _end));
	}

	bool
	operator==(const iterator_map & x) const
	{
		return (_current == x._current);
	}

	bool 
	operator!=(const iterator_map & x) const
	{
		return (_current != x._current);
	}

	reference
	operator*() const
	{
		return (_current->data);
	}

	pointer 
	operator->() const
	{
		return (&(_current->data));
	}

	iterator_map &
	operator++()
	{
		_increment();
		return (*this);
	}

	iterator_map
	operator++(int)
	{
		iterator_map tmp(*this);
		_increment();
		return (tmp);
	}

	iterator_map &
	operator--()
	{
		_decrement();
		return (*this);
	}

	iterator_map
	operator--(int)
	{
		iterator_map tmp(*this);
		_decrement();
		return (tmp);
	}


private:
	void
	_increment()
	{
		if (_current == _end)
		{
			_current = _max(_root);
			return ;
		}
		node_ptr tmp_current = _current;
		if (tmp_current->right != _end)
			_current = _min(tmp_current->right);
		else
		{
			node_ptr tmp_parent = tmp_current->parent;
			for (; tmp_parent != ft::nullptr && tmp_current == tmp_parent->right; tmp_parent = tmp_current->parent)
				tmp_current = tmp_parent;

			if (tmp_parent == ft::nullptr)
				_current = _end;
			else
				_current = tmp_parent;
		}
	}

	void
	_decrement() 
	{
		if (_current == _end)
		{
			_current = _max(_root);
			return ;
		}
		if (_current->left != _end)
			_current = _max(_current->left);
		else
		{
			node_ptr tmp_parent = _current->parent;
			while (tmp_parent && tmp_parent != _end && _current == tmp_parent->left)
			{
				_current = tmp_parent;
				tmp_parent = tmp_parent->parent;
			}
			// == + petite key_value
			if (tmp_parent && tmp_parent != _end && _current == tmp_parent->left)
			{
				_current = _root;
				return ;
			}
			_current = tmp_parent;
		}
	}

	node_ptr
	_max(node_ptr x)
	{
		if (!x || x == _end)
			return (_end);
		for (; x->right != _end && x->right; x = x->right);
		return (x);
	}

	node_ptr
	_min(node_ptr x)
	{
		if (!x || x == _end)
			return(_end);
		for (; x->left != _end && x->left; x = x->left);
		return (x);
	}

};

NAME_SPACE_END
#endif