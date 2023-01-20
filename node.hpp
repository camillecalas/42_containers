#ifndef NODE_HPP
# define NODE_HPP

# include "ft_containers.hpp"
# include "pair.hpp"
# include "nullptr.hpp"

NAME_SPACE_START

#define BLACK 0
#define RED 1
//bool value by default is false = 0. 0 = black

template <typename T>
struct Node
{
	typedef T 				value_type;
	typedef std::size_t		size_t;

	// =============================================================================
	// ATTRIBUTS ===================================================================
	value_type	data;
	size_t		color;
	Node		*parent;
	Node		*left;
	Node		*right;

	// =============================================================================
	// CONSTRUCTORS ================================================================
	Node() : data(), color(BLACK), parent(ft::nullptr), left(ft::nullptr), right(ft::nullptr)
	{}

	Node (const T & data) : data(data), color(RED), parent(ft::nullptr), left(ft::nullptr), right(ft::nullptr)
	{}

	Node (const T & data, Node *ptr_left, Node *ptr_right) : data(data), color(RED), parent(ft::nullptr), left(ptr_left), right(ptr_right)
	{}

};


NAME_SPACE_END
#endif


// //! ================================================================================
// // STRUCTURE NODE	================================================================
// public:
// typedef struct s_node
// {
// 	// =============================================================================
// 	// ATTRIBUTS ===================================================================
// 	ft::pair<const Key, T>	data;
// 	size_t					color;
// 	struct s_node			*parent;
// 	struct s_node			*left;
// 	struct s_node			*right;

// 	// =============================================================================
// 	// CONSTRUCTORS ================================================================
// 	s_node(ft::pair<const Key, T> data) : data(data), color(RED)
// 	{}

// 	// =============================================================================
// 	// GETTERS =====================================================================
// 	const Key &
// 	key() { return (data.first); }

// 	T &
// 	value() { return (data.second); }

// } Node;
// //! ================================================================================