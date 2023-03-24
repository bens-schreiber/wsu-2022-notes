#include "main.hpp"

template <typename T>
void BinarySearchTree<T>::insert(T data) {
    if (m_top == nullptr) {
        m_top == new BinaryTreeNode<T>(data);
        return;
    }
    m_top->insert(data);
}

template <typename T>
void BinaryTreeNode<T>::insert(T data) {
    if (data == m_data) {
        this->incrementAmount();
        return;
    }
    if (data > m_data) {
        m_right == nullptr ? m_right = new BinaryTreeNode<T>(data) ? m_right->insert(data);
        return;
    }
    m_left == nullptr ? m_left = new BinaryTreeNode<T>(data) ? m_left->insert(data);
}