#ifndef NODE_HPP
# define NODE_HPP

# include "ft_containers.hpp"
# include "pair.hpp"
# include "nullptr.hpp"

NAME_SPACE_START

//bool value by default is false = 0. 0 = black

template <typename T>
struct Node
{
	typedef T 	value_type;

	// =============================================================================
	// ATTRIBUTS ===================================================================
	T			key;
	bool		color;
	Node		*parent;
	Node		*left;
	Node		*right;

	// =============================================================================
	// CONSTRUCTORS ================================================================
	Node() : key(), color(0), parent(ft::nullptr), left(ft::nullptr), right(ft::nullptr)
	{}

	Node (const T & new_key) : key(new_key), color(1), parent(ft::nullptr), left(ft::nullptr), right(ft::nullptr)
	{}

	Node (const T & new_key, Node *ptr_left, Node *ptr_right) : key(new_key), color(1), parent(ft::nullptr), left(ptr_left), right(ptr_right)
	{}

};

NAME_SPACE_END
#endif