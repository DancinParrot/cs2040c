#pragma once
#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree;


class SparseArray;

template <class T>
class TreeNode {
private:
	T _item;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	int _height;
public:
	TreeNode(T x):_item(x) { _left = _right = NULL; _height = 0; };

	friend BinarySearchTree<T>;
    friend SparseArray;

};

template <class T>
class BinarySearchTree {
protected:
	int _size;
	TreeNode<T>* _root;
	void _printTree(int indent, TreeNode<T>*, bool withHeight);

	// The following functions are optional for you to implement. 
	TreeNode<T>* _search(TreeNode<T>* current, T x);
	TreeNode<T>*  _insert(TreeNode<T>* current, T x);
	TreeNode<T>* _rightRotation(TreeNode<T>*);
	TreeNode<T>* _leftRotation(TreeNode<T>*);
	void _destroySubTree(TreeNode<T>*);


public:
	BinarySearchTree() { _root = NULL; _size = 0; }
	~BinarySearchTree();
	int size() { return _size; };
	void insert(T);
	void printTree(bool withHeight = 1);

	bool exist(T x) { return T(); };
	T search(T x) { return T(); };

    friend SparseArray;
};



template <class T>
void BinarySearchTree<T>::insert(T x)
{
	_root = _root ? _insert(_root, x) : new TreeNode<T>(x);
	if (_size == 0) _size++;
}

template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight) {

	if (!node)
		return;

	if (node->_right)
		_printTree(indent + 2, node->_right, withHeight);
	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->_item;
	if (withHeight)
		cout << "(h=" << node->_height << ")";
	cout << endl;
	if (node->_left)
		_printTree(indent + 2, node->_left, withHeight);


};

template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
	_printTree(0, _root, withHeight);
}


template <class T>
void BinarySearchTree<T> ::_destroySubTree(TreeNode<T>* node)
{
	if (node->_left)
		_destroySubTree(node->_left);
	if (node->_right)
		_destroySubTree(node->_right);
	delete node;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()
{
	if (_root)
		_destroySubTree(_root);
}




template <class T>
TreeNode<T>* BinarySearchTree<T>::_search(TreeNode<T>* current, T x) {
	if (!current)
        return nullptr;
    if (current->_item == x)
        return current;
    else if (current->_item < x)
        return _search(current->_right,x);
    else
        return _search(current->_left,x);
}




struct Pair {
	unsigned long long int _idx;
	int _item;
	Pair(unsigned long long int idx, int item) { _idx = idx; _item = item; };
};


class SparseArray {

protected:
	BinarySearchTree<Pair> _tree;

public:
	SparseArray() {};

	void store(unsigned long long idx, int x);
	void printTree() { _tree.printTree(); };
	std::string listString(unsigned long long start, unsigned long long end);

};

std::ostream& operator<<(std::ostream& os, const Pair& obj);