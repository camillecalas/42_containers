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

//Regular bold text
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

//Regular underline text
# define UBLK "\e[4;30m"
# define URED "\e[4;31m"
# define UGRN "\e[4;32m"
# define UYEL "\e[4;33m"
# define UBLU "\e[4;34m"
# define UMAG "\e[4;35m"
# define UCYN "\e[4;36m"
# define UWHT "\e[4;37m"

//Regular background
# define BLKB "\e[40m"
# define REDB "\e[41m"
# define GRNB "\e[42m"
# define YELB "\e[43m"
# define BLUB "\e[44m"
# define MAGB "\e[45m"
# define CYNB "\e[46m"
# define WHTB "\e[47m"

//High intensty background 
# define BLKHB "\e[0;100m"
# define REDHB "\e[0;101m"
# define GRNHB "\e[0;102m"
# define YELHB "\e[0;103m"
# define BLUHB "\e[0;104m"
# define MAGHB "\e[0;105m"
# define CYNHB "\e[0;106m"
# define WHTHB "\e[0;107m"

//High intensty text
# define HBLK "\e[0;90m"
# define HRED "\e[0;91m"
# define HGRN "\e[0;92m"
# define HYEL "\e[0;93m"
# define HBLU "\e[0;94m"
# define HMAG "\e[0;95m"
# define HCYN "\e[0;96m"
# define HWHT "\e[0;97m"

//Bold high intensity text
# define BHBLK "\e[1;90m"
# define BHRED "\e[1;91m"
# define BHGRN "\e[1;92m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"

//Reset
// # define reset "\e[0m"
# define CRESET "\e[0m"
# define COLOR_RESET "\e[0m"


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
	{}

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


private:
	void
	_delete_intern(pointer node)
	{
		if (node == TNULL)
			return ;
		_delete_intern(node->left);
		_delete_intern(node->right);

		_alloc.destroy(node);
		_alloc.deallocate(node, 1);
	}

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

public:
	void
	delete_tree()
	{
		_delete_intern(root);
		root = TNULL;
	}

	void
	destroy_tnull()
	{
		_alloc.destroy(TNULL);
		_alloc.deallocate(TNULL, 1);
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
			if (k == root)
				break;
		}
		root->color = 0;
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
		preOrderHelper(this->root);
	}

	void inorder() 
	{
		inOrderHelper(this->root);
	}

	void postorder() 
	{
		postOrderHelper(this->root);
	}

	pointer searchTree(int k) 
	{
		return searchTreeHelper(this->root, k);
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
			this->root = y;
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
		if (root)
			print_tree(this->root, "", true);
	}




	void print_tree(pointer root, std::string indent, bool last)
	{
	// if (root == ft::_nullptr)
	// 	return ;
	if (root != TNULL)
	{
		std::cout << indent;
		if (last)
		{
			std::cout << "R----";
			indent += "   ";
		}
		else
		{
			std::cout << "L----";
			indent += "|  ";
		}

		if (root->color == RED)
		{
			std::cout << BRED << root->data.first << "(" << "RED" << ")" << "--->" << root->data.second << CRESET<< std::endl;
		}
		else
		{
			std::cout << BBLU << root->data.first << "(" << "BLACK" << ")" << "--->" << root->data.second << CRESET << std::endl;
		}
		print_tree(root->left, indent, false);
		print_tree(root->right, indent, true);
	}
	}
};

NAME_SPACE_END
#endif