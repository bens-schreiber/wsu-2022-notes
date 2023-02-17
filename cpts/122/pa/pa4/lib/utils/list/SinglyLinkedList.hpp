namespace Utils {
    template <typename T>
    struct ListNode {
        T &data;
        ListNode<T> *next{nullptr};
        ListNode(T &data) : data(data);
    };

    template <typename T>
    class SinglyLinkedList {
        private:
            ListNode<T> *m_head{nullptr};
            ListNode<T> *m_tail{nullptr};
            unsigned int m_length{0};
        public:
            SinglyLinkedList();
            SinglyLinkedList(T &data);
            ~SinglyLinkedList();

            ListNode<T> &addToFront(T &data);
            ListNode<T> &addToBack(T &data);
            ListNode<T> &add(T &data) {return addToEnd(data);}

            void popFront();

            // O(n-1)
            void popBack();
    };
}