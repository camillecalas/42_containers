#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP

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

	iterator_map(const node_ptr &current, const node_ptr &root, const node_ptr &end) : _current(current), _root(root), _end(end)
	{}

	iterator_map(const iterator_map & copy)
	{
		_current(copy._current);
		_root(copy._root);
		_end(copy._end);
	}
		
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
	operator==(const iterator_map & x)
	{
		return (_current = x._current);
	}

	bool 
	operator!=(const iterator_map & x)
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
		return (*this);
	}



	void
	increment()
	{
		if (_current == _end)
	}


};

NAME_SPACE_END
#endif