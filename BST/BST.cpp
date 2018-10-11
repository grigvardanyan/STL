#include "BST.h"
#include<iostream>


template<class T>
BinarySearchTree<T>::BinarySearchTree() {};

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	if (root != NULL)
	{
		delete root;
	}
};
template<class T>
void BinarySearchTree<T>::Add(T value)
{
	if (root == NULL)
	{
		root = new Node();
		root->value = value;
		return;

	}

	BinarySearchTree::Node* current = root;
	BinarySearchTree::Node parrent = NULL;

	while (current != NULL)
	{
		parrent = current;
		current = value < current->value ? current->left : current->right;
	}

	if (parrent->left != NULL && value < parrent->value)
	{
		parrent->left = new Node();
		parrent->left->value = value;
	}
	else
	{
		parrent->right = new Node();
		parrent->right->value = value;
	}
};

template<class T>
void BinarySearchTree<T>::Remove(T value)
{
	if (root == NULL)
	{
		return;
	}

	Node* current = root;
	Node* parrent = NULL;

	while (current != NULL)
	{
		parrent = current;
		if (current->value == value)
		{

			break;
		}
		current = current->value > value ? current->left : current->right;
	}

	if (current == NULL)
	{
		return;
	}

	//If current node does not has childrens
	if (current->left == NULL && current->right == NULL)
	{
		if (parrent == NULL)
		{
			root == NULL;
			return;
		}

		if (parrent->left == current)
		{
			parrent->left == NULL;
		}
		else
		{
			parrent->right = NULL;
		}
		return;
	}

	//If current has only one childe
	if (current->left == NULL || current->right == NULL)
	{
		if (parrent == NULL)
		{
			root = current->left != NULL ? current->left : current->right;
			return;
		}

		Node* temporary = current->left != NULL ? current->left : current->right;
		bool isLeft = parrent->left != NULL && parrent->left == current ? true : false;

		if (parrent->left != NULL)
		{
			parrent->left = temporary;
		}
		else
		{
			parrent->right = temporary;
		}
		return;
	}

	//If current has two childes
	if (current->left != NULL && current->right != NULL)
	{
		Node* predParrent = NULL;
		Node* predecessor = current->right;

		while (predecessor->left != NULL)
		{
			parrent = predecessor;
			predecessor = predecessor->left;
		}

		if (current->left != NULL)
		{
			predecessor->left = current->left;
		}
		if (predecessor->right != NULL)
		{
			predParrent->left = predecessor->right;
		}

		if (parrent->left != NULL && parrent->left == current)
		{
			parrent->left = predecessor;
			if (current->right != NULL)
			{
				predecessor->right = current->right;
			}
		}
		current->left = NULL;
		current->right = NULL;
	}
};

template<class T>
BinarySearchTree< T>::Node* BinarySearchTree<T>::Search(T value)
{
	if (root == NULL)
	{
		return false;
	}

	Node* current = root;
	while (current != NULL)
	{
		if (current->value == value)
		{
			return current;
		}
		current = current->value > value ? current->left : current->right;
	}

	return NULL;
};

template<class T>
BinarySearchTree< T>::Node* BinarySearchTree<T>::Predecessor(T value)
{
	Node* element = Search(value);
	Node* predecessor = NULL;

	for (predecessor = element->right; predecessor->left != NULL; predecessor = predecessor->left);
	return predecessor;
};

template<class T>
BinarySearchTree< T>::Node* BinarySearchTree<T>::Successor(T value)
{
	Node* element = Search(value);
	Node* successor = NULL;

	for (successor = element->left; successor->right != NULL; successor = successor->right);
	return successor;
};

template<class T>
BinarySearchTree< T>::Node* BinarySearchTree<T>::Predecessor(Node* node)
{
	Node* predecessor = NULL;

	for (predecessor = node->right; predecessor->left != NULL; predecessor = predecessor->left);
	return predecessor;
};

template<class T>
BinarySearchTree<T>::Node* BinarySearchTree<T>::Successor(Node* node)
{
	Node* successor = NULL;

	for (successor = node->left; successor->right != NULL; successor = successor->right);
	return successor;
};


