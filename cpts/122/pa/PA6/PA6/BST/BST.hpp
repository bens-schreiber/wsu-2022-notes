//
//  BST.hpp
//  PA6
//
//  Created by Benjamin Schreiber on 3/21/23.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include "BSTNode.hpp"

// Binary Search Tree
template <class T>
class BST {
private:
    BSTNode<T> *m_root;
    unsigned int m_length;
public:
    BST() : m_length(0) {}
    BST(T data) : m_root(new BSTNode<T>(data)), m_length(0) {}
    BST(BST &other) : m_root(other.m_root), m_length (other.m_length) {}
    ~BST() {
        delete m_root;
    }
    
    // Sets root if the root is null
    BSTNode<T> &insert(T data) {
        if (m_length++ == 0) {
            return *(m_root = new BSTNode<T>(data));
        }
        return m_root->addNode((T) data);
    }
    
    // Prints all nodes of the BST
    void print() const {
        m_root->print();
    }
    
    T find(T const &data) const {
       return m_root->find(data);
    }
    
    BSTNode<T> &getRoot() {return *m_root;}
};

#endif /* BST_hpp */
