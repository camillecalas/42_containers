// Implementing Red-Black Tree in C++
#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "node.hpp"
# include "map.hpp"
# include "pair.hpp"
# include "iterator_map.hpp"
# include "nullptr.hpp"
# include <iostream>

//TODO erase later
using namespace std;


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
	pointer			_root;
	value_compare	_comp;
	allocator_type	_alloc;
	// pointer			_end;
	// size_type		_size;

public:
	pointer 		TNULL;
	pointer			root;

	// =============================================================================
	// CONSTRUCTORS ================================================================
public:
	RedBlackTree(const value_compare &comp = value_compare()) 
		: _comp(comp), _alloc(allocator_type())
	{
		// _end = _alloc.allocate(1);
		// _alloc.construct(_end, Node(value_type(), RED));
		// _root = _end;

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
	{
		//delete like in vector 
	}

	// =============================================================================
	// ADDED FUNCTIONS =============================================================
	pointer 
	minimum(pointer node) const
	{
		while (node->left != TNULL)
			node = node->left;
		return node;
	}

	pointer
	maximun(pointer node) const
	{
		while (node->right != TNULL)
			node = node->right;
		return (node);
	}


	// pointer
	// find_intern(pointer node, const value_type & value) const
	// {
	// 	if (value == node->data.first)
	// 		return (node);
	// 	else if (node == TNULL)
	// 		return (TNULL);
	// 	else if (_comp(value, node->data.first))
	// 		return (find_intern(node->left, value));
	// 	else
	// 		return (find_intern(node->right, value));
	// }

	// pointer
	// find(const value_type &value) const
	// {
	// 	return (find_intern(root, value));
	// }

	pointer
	_find_intern(const value_type & value, const pointer node) const
	{
		if (value == node->data)
			return (node);
		else if (node == TNULL)
			return (TNULL);
		else if (_comp(value, node->data))
			return (_find_intern(value, node->left));
		else
			return (_find_intern(value, node->right));
	}

	pointer
	find(const value_type &value) const
	{
		return (_find_intern(value, root));
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
	void preOrderHelper(pointer node) 
	{
		if (node != TNULL) 
		{
			cout << node->data << " ";
			preOrderHelper(node->left);
			preOrderHelper(node->right);
		}
	}

	// Inorder
	void inOrderHelper(pointer node) 
	{
		if (node != TNULL) 
		{
			inOrderHelper(node->left);
			cout << node->data << " ";
			inOrderHelper(node->right);
		}
	}

	// Post order
	void postOrderHelper(pointer node) 
	{
		if (node != TNULL) 
		{
			postOrderHelper(node->left);
			postOrderHelper(node->right);
			cout << node->data << " ";
		}
	}

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
		while (x != _root && x->color == 0) 
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
					x = _root;
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
					x = _root;
				}
			}
		}
		x->color = 0;
	}

	void rbTransplant(pointer u, pointer v) 
	{
		if (u->parent == nullptr)
			_root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}

	void deleteNodeHelper(pointer node, int key) 
	{
		pointer z = TNULL;
		pointer x, y;
		while (node != TNULL)
		{
			if (node->data == key)
				z = node;
			if (node->data <= key)
				node = node->right;
			else
				node = node->left;
		}

		if (z == TNULL) 
		{
			cout << "Key not found in the tree" << endl;
			return;
		}

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
	}

	// For balancing the tree after insertion
	void insertFix(pointer k) 
	{
		pointer u;
		while (k->parent->color == RED) 
		{
			if (k->parent == k->parent->parent->right) 
			{
				u = k->parent->parent->left;
				if (u->color == 1)
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				} 
				else 
				{
					if (k == k->parent->left) 
					{
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			} 
			else 
			{
				u = k->parent->parent->right;

				if (u->color == 1) 
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				} 
				else 
				{
					if (k == k->parent->right) 
					{
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == _root)
				break;
		}
		_root->color = 0;
	}

	void printHelper(pointer root, string indent, bool last) 
	{
		if (root != TNULL) 
		{
			cout << indent;
			if (last) 
			{
				cout << "R----";
				indent += "   ";
			} 
			else 
			{
				cout << "L----";
				indent += "|  ";
			}

			string sColor = root->color ? "RED" : "BLACK";
			cout << root->data << "(" << sColor << ")" << endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}

public:


	void preorder() 
	{
		preOrderHelper(this->_root);
	}

	void inorder() 
	{
		inOrderHelper(this->_root);
	}

	void postorder() 
	{
		postOrderHelper(this->_root);
	}

	pointer searchTree(int k) 
	{
		return searchTreeHelper(this->_root, k);
	}

	// pointer minimum(pointer node) 
	// {
	// 	while (node->left != TNULL)
	// 		node = node->left;
	// 	return node;
	// }

	pointer maximum(pointer node) 
	{
		while (node->right != TNULL)
		node = node->right;
		return node;
	}

	pointer successor(pointer x) 
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

	pointer predecessor(pointer x) 
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

	void leftRotate(pointer x) 
	{
		pointer y = x->right;
		x->right = y->left;
		if (y->left != TNULL)
			y->left->parent = x;
		y->parent = x->parent;

		if (x->parent == nullptr)
			this->_root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	void rightRotate(pointer x) 
	{
		pointer y = x->left;
		x->left = y->right;
		if (y->right != TNULL)
			y->right->parent = x;
		y->parent = x->parent;

		if (x->parent == nullptr)
			this->_root = y;
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


		// _alloc.construct(TNULL, Node(value_type()));
		// node->parent = nullptr;
		// node->data = key;
		// node->left = TNULL;
		// node->right = TNULL;
		// node->color = 1;

		pointer y = ft::nullptr;
		pointer x = this->root;

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

		if (node->parent->parent == nullptr)
			return (node);
		insertFix(node);
		return (node);
	}

	pointer getRoot() 
	{
		return this->root;
	}

	void deleteNode(int data) 
	{
		deleteNodeHelper(this->root, data);
	}

	void printTree()
	{
		if (_root)
			printHelper(this->root, "", true);
	}
};

NAME_SPACE_END
#endif