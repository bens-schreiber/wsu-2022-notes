//
//  BSTNode.hpp
//  PA6
//
//  Created by Benjamin Schreiber on 3/21/23.
//

#ifndef BSTNode_hpp
#define BSTNode_hpp
#include <string>
#include <iostream>

// Node specifically for Binary Search Tree
template <class T>
class BSTNode {
    
private:
    // Data
    T m_data;
    
    // The left tree node
    BSTNode *m_left;
    
    // The right tree node
    BSTNode *m_right;
    
    // Everytime a duplicate value is added, count it here instead of inserting
    unsigned int m_duplicates;
    
public:
    
    // Constructor
    BSTNode(T data) : m_data(data), m_duplicates(0) {}
    
    // Copy constructor
    BSTNode(BSTNode &other) : m_data(other.m_data), m_left(other.m_left), m_right(other.m_right), m_duplicates(other.m_duplicates) {}
    
    // Destructor
    ~BSTNode() {
        deleteNode(true);
    }
    
    // Deletes the node. If we are operating with regard to duplicates (ignoreDupliactes flag), then the node will only be completely deleted when duplicates is 0. Else, delete the node.
    void deleteNode(bool ignoreDuplicates = false) {
        if ( ignoreDuplicates || m_duplicates-- > 0 ) {
            delete m_left;
            delete m_right;
        }
    }
    
    // Inserts a node
    BSTNode<T> &addNode(T data) {
        
        // Check duplicate
        if (data == m_data) {
            ++m_duplicates;
            return *this;
        }
        
        // Insert on left if larger
        if (data > m_data) {
            if (m_left == nullptr) {
                return *(m_left = new BSTNode<T>(data));
            }
            return m_left->addNode(data);
        }

        // Insert on right
        if (m_right == nullptr) {
            return *(m_right = new BSTNode<T>(data));
        }

        return m_right->addNode(data);
    }
    
    void print() const {
        std::cout << m_data << std::endl;
        if (m_left) m_left->print();
        if (m_right) m_right->print();
    }
    
    T find(const T &data) const {
        if (data == m_data) {
            return m_data;
        }
        if (data > m_data) {
            return m_left->find(data);
        }
        return m_right->find(data);
    }
    
    // Getters
    T getData() {return m_data;}
    BSTNode &getLeft() {return *m_left;}
    BSTNode &getRight() {return *m_right;}
    
    // Setters
    void setLeft(BSTNode *left) {m_left = left;}
    void setRight(BSTNode *right) {m_right = right;}
};
#include <stdio.h>

#endif /* BSTNode_hpp */
