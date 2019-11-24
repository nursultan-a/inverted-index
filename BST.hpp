#ifndef BST_HPP
#define BST_HPP

#include <iostream>

#include "BSTNode.hpp"

template <class T>
class BST
{
public: // DO NOT CHANGE THIS PART.
    BST();
    BST(const BST<T> &obj);

    ~BST();

    BSTNode<T> *getRoot();

    void insert(const T &data);
    void remove(const T &data);
    BSTNode<T> *find(const T &data);
    void printInorder();

    BST<T> &operator=(const BST<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    void printInorder(BSTNode<T> *node);

    void insertHelper(const T &data, BSTNode<T> *&current);
    void removeHelper(const T &data, BSTNode<T> *&current);

    BSTNode<T> *findMin(BSTNode<T> *current) const;
    BSTNode<T> *findHelper(const T &data, BSTNode<T> *current) const;

    void makeEmpty(BSTNode<T> *current);

    BSTNode<T> *clone(BSTNode<T> *current) const;

    BSTNode<T> *copyConstructorHelper(BSTNode<T> *node);

private: // DO NOT CHANGE THIS PART.
    BSTNode<T> *root;
};

#endif //BST_HPP

template <class T>
BST<T>::BST()
{
    /* TODO */
    this->root = NULL;
}

template <class T>
BST<T>::BST(const BST<T> &obj)
{
    /* TODO */
    //std::cout << "copy constructor is called" << std::endl;
    this->root = copyConstructorHelper(obj.root);
}
template <class T>
BSTNode<T> *BST<T>::copyConstructorHelper(BSTNode<T> *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else
    {
        this->root = clone(node);
    }
    return this->root;
}
template <class T>
BST<T>::~BST()
{
    /* TODO */
    this->makeEmpty(this->root);
}

template <class T>
void BST<T>::makeEmpty(BSTNode<T> *current)
{
    if (current != NULL)
    {
        makeEmpty(current->left);
        makeEmpty(current->right);
        delete current;
    }
    current = NULL;
}
template <class T>
BSTNode<T> *BST<T>::getRoot()
{
    /* TODO */
    return this->root;
}

template <class T>
void BST<T>::insert(const T &data)
{
    /* TODO */
    if (this->root == NULL)
    {
        this->root = new BSTNode<T>(data, NULL, NULL);
    }
    else
    {
        insertHelper(data, this->root);
    }
}

template <class T>
void BST<T>::insertHelper(const T &data, BSTNode<T> *&current)
{
    if (current == NULL)
    {
        current = new BSTNode<T>(data, NULL, NULL);
    }
    else if (data < current->data)
    {
        insertHelper(data, current->left);
    }
    else if (data > current->data)
    {
        insertHelper(data, current->right);
    }
    else
    {
        ;
    }
}

template <class T>
void BST<T>::remove(const T &data)
{
    /* TODO */
    removeHelper(data, this->root);
}

template <class T>
void BST<T>::removeHelper(const T &data, BSTNode<T> *&current)
{
    if (current == NULL)
    {
        return;
    }
    if (data < current->data)
    {
        removeHelper(data, current->left);
    }
    else if (data > current->data)
    {
        removeHelper(data, current->right);
    }
    else if (current->left != NULL && current->right != NULL)
    {
        current->data = findMin(current->right)->data;
        removeHelper(current->data, current->right);
    }
    else
    {
        BSTNode<T> *oldNode = current;
        current = (current->left != NULL) ? current->left : current->right;
        delete oldNode;
    }
}

template <class T>
BSTNode<T> *BST<T>::findMin(BSTNode<T> *current) const
{
    if (current == NULL)
    {
        return NULL;
    }
    if (current->left == NULL)
    {
        return current;
    }
    return findMin(current->left);
}

template <class T>
BSTNode<T> *BST<T>::find(const T &data)
{
    /* TODO */
    //std::cout<<">>BST:find: looking for "<< data<<std::endl;
    return findHelper(data, this->root);
}

template <class T>
BSTNode<T> *BST<T>::findHelper(const T &data, BSTNode<T> *current) const
{
    if (current == NULL)
    {
        return NULL;
    }
    else if (data < current->data)
    {
        findHelper(data, current->left);
    }
    else if (data > current->data)
    {
        findHelper(data, current->right);
    }
    else if (data == current->data)
    {
        return current;
    }
}

template <class T>
void BST<T>::printInorder()
{

    if (root == NULL)
    {
        std::cout << "{}" << std::endl;
    }
    else
    {
        std::cout << "{" << std::endl;
        printInorder(root);
        std::cout << std::endl
                  << "}" << std::endl;
    }
}

template <class T>
void BST<T>::printInorder(BSTNode<T> *node)
{

    if (node == NULL)
        return;

    printInorder(node->left);
    if (node->left)
    {
        std::cout << "," << std::endl;
    }
    std::cout << "\t" << node->data;
    if (node->right)
    {
        std::cout << "," << std::endl;
    }
    printInorder(node->right);
}

template <class T>
BST<T> &BST<T>::operator=(const BST<T> &rhs)
{
    /* TODO */
    if (this != &rhs)
    {
        makeEmpty(this->root);
        root = clone(rhs.root);
    }
}

template <class T>
BSTNode<T> *BST<T>::clone(BSTNode<T> *current) const
{
    if (current == NULL)
    {
        return NULL;
    }

    return new BSTNode<T>(current->data, clone(current->left), clone(current->right));
}
