#include "SinglyLinkedList.hpp"

namespace Utils {
    template <typename T>
    SinglyLinkedList<T>::SinglyLinkedList(T &data) {
        auto node = new ListNode<>(data);
        m_head = node;
        m_tail = node;
        ++m_length;
    }

    template <typename T>
    SinglyLinkedList<T>::~SinglyLinkedList() {
        auto node = m_head;
        while((m_head = m_head.next) != nullptr) {
            delete popFront();
        }
    }

    template <typename T>
    ListNode<T> &SinglyLinkedList<T>::addToFront(T &data) {
        auto n = new ListNode<T>(data);
        n->next = m_head;
        m_head = n;
        ++m_length;
        return n;
    }

    template <typename T>
    ListNode<T> &SinglyLinkedList<T>::addToBack(T &data) {
        auto n = new ListNode<T>(data);
        m_tail->next = n;
        m_tail = n;
        ++m_length;
        return n;
    }

    template <typename T>
    void SinglyLinkedList<T>::popFront() {
        auto n = m_head->next;
        delete m_head;
        m_head = n;
        --m_length;
        return n;
    }

    template <typename T>
    void SinglyLinkedList<T>::popBack() {
        delete m_tail;
        ListNode<T> n = m_head;
        while(n.next != nullptr) {
            n = n.next;
        }
        --m_length;
        m_tail = n;
    }
}