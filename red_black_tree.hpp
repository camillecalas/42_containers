// Implementing Red-Black Tree in C++
#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "node.hpp"
# include "pair.hpp"
# include "iterator_map.hpp"
# include "nullptr.hpp"
# include <iostream>


NAME_SPACE_START


template <class T, class Compare, class Node = ft::Node<T>, class Allocator = std::allocator<Node> >
class RedBlackTree 
{
	// =============================================================================
	// TYPEDEF =====================================================================
public:
	typedef T							value_type;
	typedef value_type &				reference;
	typedef typename Allocator::pointer	pointer;
	typedef	Node						node_type;
	typedef Compare						key_compare;
	typedef Compare						value_compare;
	typedef	std::size_t					size_type;
	typedef Allocator					allocator_type;
	

	// =============================================================================
	// ATTRIBUTS ===================================================================
private:
	value_compare	_comp;
	allocator_type	_alloc;

public:
	pointer 		TNULL;
	pointer			root;

	// =============================================================================
	// CONSTRUCTORS ================================================================
	RedBlackTree(const value_compare &comp = value_compare()) 
		: _comp(comp), _alloc(allocator_type())
	{
		TNULL = _alloc.allocate(1);
		_alloc.construct(TNULL, Node(value_type()));

		TNULL->parent = ft::nullptr;
		TNULL->left = ft::nullptr;
		TNULL->right = ft::nullptr;
		TNULL->color = BLACK;
		root = TNULL;
	}
	

	// =============================================================================
	// DESTRUCTORS =================================================================
	~RedBlackTree()
	{}

	// =============================================================================
	// ADDED FUNCTIONS =============================================================
	pointer 
	minimum(pointer node) const
	{
		if (node == TNULL)
			return (node);
		while (node->left != TNULL)
			node = node->left;
		return node;
	}

	pointer
	maximun(pointer node) const
	{
		if (node == TNULL)
			return (node);
		while (node->right != TNULL)
			node = node->right;
		return (node);
	}


private:
	void
	_delete_tree(pointer node)
	{
		if (node == TNULL)
			return ;
		_delete_tree(node->left);
		_delete_tree(node->right);

		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
	}

	pointer
	_find(const pointer node, const value_type & val)  const
	{
		if (node == TNULL)
			return (TNULL);
		else if (_comp(val, node->data))
			return (_find(node->left, val));
		else if (_comp(node->data, val))
			return (_find(node->right, val));
		return (node);
	}

	pointer
	_lower_bound_rbt(const value_type &k, pointer node) const
	{
		pointer tmp = TNULL;
		
		if (node == TNULL)
			return (node);
		while (node != TNULL)
		{
			if (_comp(node->data, k) == false)
			{
				tmp = node;
				node = node->left;
			}
			else
				node = node->right;
		}
			return (tmp);
	}

	pointer
	_upper_bound_rbt(const value_type &val, pointer node) const
	{
		if (node == TNULL)
			return (TNULL);

		pointer tmp = node;
		pointer	res = TNULL;

		while(tmp != TNULL)
			if (_comp(val, tmp->data) == true)
			{
				res = tmp;
				tmp = tmp->left;
			}
			else
				tmp = tmp->right;
		return (res);
	}


public:
	size_type
	max_size() const
	{
		return (_alloc.max_size());
	}

	bool
	empty() const
	{
		if (root == TNULL)
			return (1);
		return (0);
	}

	void
	delete_tree()
	{
		_delete_tree(root);
		root = TNULL;
	}

	void
	destroy_tnull()
	{
		_alloc.destroy(TNULL);
		_alloc.deallocate(TNULL, 1);
	}



	pointer
	find(const pointer node, const value_type &val) const
	{
		return (_find(node, val));
	}

	pointer
	lower_bound_rbt(const value_type &val) const
	{
		return (_lower_bound_rbt(val, get_root()));
	}

	pointer
	upper_bound_rbt(const value_type &val) const
	{
		return (_upper_bound_rbt(val, root));
	}


	// =============================================================================
	// GETTERS =====================================================================
	//TODO not sure 
	pointer
	get_tnull() const
	{
		return (TNULL);
	}

	pointer
	get_root() const
	{
		return (root);
	}


	// =============================================================================
	// ITERATORS ===================================================================
	pointer
	begin() const
	{
		return (minimum(root));
	}

	pointer
	end() const
	{
		return (maximum(root));
	}


	void initializeNULLNode(pointer node, pointer parent) 
	{
		node->data = 0;
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = 0;
	}

	// Preorder
	// void preOrderHelper(pointer node) 
	// {
	// 	if (node != TNULL) 
	// 	{
	// 		cout << node->data << " ";
	// 		preOrderHelper(node->left);
	// 		preOrderHelper(node->right);
	// 	}
	// }

	// Inorder
	// void inOrderHelper(pointer node) 
	// {
	// 	if (node != TNULL) 
	// 	{
	// 		inOrderHelper(node->left);
	// 		cout << node->data << " ";
	// 		inOrderHelper(node->right);
	// 	}
	// }

	// Post order
	// void postOrderHelper(pointer node) 
	// {
	// 	if (node != TNULL) 
	// 	{
	// 		postOrderHelper(node->left);
	// 		postOrderHelper(node->right);
	// 		cout << node->data << " ";
	// 	}
	// }

	pointer searchTreeHelper(pointer node, int key) 
	{
		if (node == TNULL || key == node->data)
			return node;
		if (key < node->data)
			return searchTreeHelper(node->left, key);
		return searchTreeHelper(node->right, key);
	}

	// For balancing the tree after deletion
	void deleteFix(pointer x) 
	{
		pointer s;
		while (x != root && x->color == 0) 
		{
			if (x == x->parent->left) 
			{
				s = x->parent->right;
				if (s->color == 1) 
				{
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}

				if (s->left->color == 0 && s->right->color == 0)
				{
					s->color = 1;
					x = x->parent;
				} 
				else 
				{
					if (s->right->color == 0)
					{
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			} 
			else 
			{
				s = x->parent->left;
				if (s->color == 1) 
				{
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == 0 && s->right->color == 0) 
				{
					s->color = 1;
					x = x->parent;
				} 
				else 
				{
					if (s->left->color == 0) 
					{
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
	}

	void rbTransplant(pointer u, pointer v) 
	{
		if (u->parent == nullptr)
			root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}

	// bool
	// _deleteNode(pointer node, value_type key) 
	// {
	// 	pointer z = TNULL;
	// 	pointer x, y;
	// 	while (node != TNULL)
	// 	{
	// 		if (node->data == key)
	// 			z = node;
	// 		if (node->data <= key)
	// 			node = node->right;
	// 		else
	// 			node = node->left;
	// 	}

	// 	if (z == TNULL) 
	// 		return false;

	// 	y = z;
	// 	int y_original_color = y->color;
	// 	if (z->left == TNULL) 
	// 	{
	// 		x = z->right;
	// 		rbTransplant(z, z->right);
	// 	} 
	// 	else if (z->right == TNULL)
	// 	{
	// 		x = z->left;
	// 		rbTransplant(z, z->left);
	// 	} 
	// 	else 
	// 	{
	// 		y = minimum(z->right);
	// 		y_original_color = y->color;
	// 		x = y->right;
	// 		if (y->parent == z)
	// 			x->parent = y;
	// 		else 
	// 		{
	// 			rbTransplant(y, y->right);
	// 			y->right = z->right;
	// 			y->right->parent = y;
	// 		}

	// 		rbTransplant(z, y);
	// 		y->left = z->left;
	// 		y->left->parent = y;
	// 		y->color = z->color;
	// 	}
	// 	delete z;
	// 	if (y_original_color == BLACK)
	// 		deleteFix(x);
	// 	return (true);
	// }


		bool _deleteNode(pointer node, value_type key)
	{
		pointer z = TNULL;
		pointer x, y;

		// Searching the node to delete
		while (node != TNULL)
		{
			if (node->data == key) 
			{
				z = node;
			}
			if (_comp(node->data, key))
				node = node->right;
			else
				node = node->left;
		}

		// The searched node is not in the tree
		if (z == TNULL)
			return (false);

		y = z;
		int y_original_color = y->color;
		if (z->left == TNULL)
		{
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == TNULL)
		{
			x = z->left;
			rbTransplant(z, z->left);
		}
		else
		{
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z)
				x->parent = y;
			else 
			{
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 0)
			deleteFix(x);
		return (true);
	}

	// For balancing the tree after insertion
	void 
	_insertFix(pointer k) 
	{
		pointer u;
		while (k->parent->color == RED) 
		{
			if (k->parent == k->parent->parent->right) 
			{
				u = k->parent->parent->left;
				if (u->color == RED)
				{
					u->color = BLACK;
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					k = k->parent->parent;
				} 
				else 
				{
					if (k == k->parent->left) 
					{
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					leftRotate(k->parent->parent);
				}
			} 
			else 
			{
				u = k->parent->parent->right;

				if (u->color == 1) 
				{
					u->color = BLACK;
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					k = k->parent->parent;
				} 
				else 
				{
					if (k == k->parent->right) 
					{
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = BLACK;
					k->parent->parent->color = RED;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root)
				break;
		}
		root->color = BLACK;
	}

	// void
	// printHelper(pointer root, string indent, bool last) 
	// {
	// 	if (root != TNULL) 
	// 	{
	// 		cout << indent;
	// 		if (last) 
	// 		{
	// 			cout << "R----";
	// 			indent += "   ";
	// 		} 
	// 		else 
	// 		{
	// 			cout << "L----";
	// 			indent += "|  ";
	// 		}

	// 		string sColor = root->color ? "RED" : "BLACK";
	// 		cout << root->data << "(" << sColor << ")" << std::endl;
	// 		printHelper(root->left, indent, false);
	// 		printHelper(root->right, indent, true);
	// 	}
	// }

public:


	void 
	preorder() 
	{
		preOrderHelper(this->root);
	}

	void 
	inorder() 
	{
		inOrderHelper(this->root);
	}

	void 
	postorder() 
	{
		postOrderHelper(this->root);
	}

	pointer 
	searchTree(int k) 
	{
		return searchTreeHelper(this->root, k);
	}

	// pointer minimum(pointer node) 
	// {
	// 	while (node->left != TNULL)
	// 		node = node->left;
	// 	return node;
	// }

	// pointer 
	// maximum(pointer node) 
	// {
	// 	while (node->right != TNULL)
	// 		node = node->right;
	// 	return node;
	// }

	pointer 
	successor(pointer x) 
	{
		if (x->right != TNULL) 
		return minimum(x->right);

		pointer y = x->parent;
		while (y != TNULL && x == y->right)
		{
		x = y;
		y = y->parent;
		}
		return y;
	}

	pointer 
	predecessor(pointer x) 
	{
		if (x->left != TNULL)
			return maximum(x->left);

		pointer y = x->parent;
		while (y != TNULL && x == y->left) 
		{
			x = y;
			y = y->parent;
		}
		return y;
	}

	void 
	leftRotate(pointer x) 
	{
		pointer y = x->right;
		x->right = y->left;
		if (y->left != TNULL)
			y->left->parent = x;
		y->parent = x->parent;

		if (x->parent == nullptr)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	void 
	rightRotate(pointer x) 
	{
		pointer y = x->left;
		x->left = y->right;
		if (y->right != TNULL)
			y->right->parent = x;
		y->parent = x->parent;

		if (x->parent == nullptr)
			this->root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

// Inserting a node
	pointer
	insert(value_type key) 
	{
		pointer node = _alloc.allocate(1);
		_alloc.construct(node, Node(key, TNULL, TNULL));

		pointer y = ft::nullptr;
		pointer x = root;

		while (x != TNULL) 
		{
			y = x;
			if (_comp(node->data, x->data))
				x = x->left;
			else if (_comp(x->data, node->data))
				x = x->right;
			else
			{
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				return (ft::nullptr);
			}
		}

		node->parent = y;
		if (y == nullptr)
			root = node;
		else if (_comp(node->data, y->data))
			y->left = node;
		else
			y->right = node;

		if (node->parent == ft::nullptr)
		{
			node->color = BLACK;
			return (node);
		}

		if (node->parent->parent == ft::nullptr)
			return (node);
		_insertFix(node);
		return (node);
	}

	pointer getRoot() 
	{
		return this->root;
	}

	bool
	deleteNode(value_type data) 
	{
		return (_deleteNode(root, data));
	}

// void printTree()
// {
// 	if (root)
// 		print_tree(this->root, "", true);
// }

// 	void print_tree(pointer root, std::string indent, bool last)
// 	{
// 	// if (root == ft::_nullptr)
// 	// 	return ;
// 	if (root != TNULL)
// 	{
// 		std::cout << indent;
// 		if (last)
// 		{
// 			std::cout << "R----";
// 			indent += "   ";
// 		}
// 		else
// 		{
// 			std::cout << "L----";
// 			indent += "|  ";
// 		}

// 		if (root->color == RED)
// 		{
// 			std::cout << BRED << root->data.first << "(" << "RED" << ")" << "--->" << root->data.second << CRESET<< std::endl;
// 		}
// 		else
// 		{
// 			std::cout << BBLU << root->data.first << "(" << "BLACK" << ")" << "--->" << root->data.second << CRESET << std::endl;
// 		}
// 		print_tree(root->left, indent, false);
// 		print_tree(root->right, indent, true);
// 	}
// 	}

};

NAME_SPACE_END
#endif