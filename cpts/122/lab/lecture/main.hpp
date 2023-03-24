template <typename T>
class BinaryTreeNode {
    T m_data;
    BinaryTreeNode<T> *m_left;
    BinaryTreeNode<T> *m_right;
    int m_amount;

    public:

        BinaryTreeNode(T data) : m_data(data), m_left(nullptr), m_right(nullptr), m_amount(1) {}

        BinaryTreeNode(T data, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) 
        : m_data(data), m_left(left), m_right(right), m_amount(1) {}

        ~BinaryTreeNode() {
            delete m_left;
            delete m_right;
        }

        BinaryTreeNode getLeft() {return m_left;}
        BinaryTreeNode getRight() {return m_right;}
        T getData() {return m_data;}
        void setLeft(BinaryTreeNode<T> *left) {m_left = left;}
        void setRight(BinaryTreeNode<T> *right) {m_right = right;}
        void incrementAmount() {++m_amount;}
        void insert(T data);
};

template <typename T>
class BinarySearchTree {
    BinaryTreeNode<T> *m_top;

    public:
        BinarySearchTree() : m_top(nullptr) {}
        BinarySearchTree(T data) : m_top(nullptr) {
            insert(data);
        }
        ~BinarySearchTree() {
            delete m_top;
        }

        void insert(T data);
};
