#include "BST.h"

template <typename T>
BST<T>::BST() : root{nullptr} 
{}

template <typename T>
BST<T>::BST(const T value) {
    root = new Node(value);  
}

template <typename T>
BST<T>::BST(const BST<T>& rhs) {
    if (rhs->root == nullptr) {
        clear();
        return;
    }
    copy_maker(this->root, rhs->root);
}

template <typename T>
void BST<T>::copy_maker(Node*& lhs, const Node* rhs) {
    if (!rhs) {
        return;
    }
    lhs = new Node(rhs->key);
    copy_maker(lhs->left, rhs->left);
    copy_maker(lhs->right, rhs->right);
}

template <typename T>
BST<T>::BST(BST<T>&& src) {
    clear();
    if (src->root != nullptr) {
        this->root = src->root;
        src->root = nullptr;
    }
}

template <typename T>
BST<T>::~BST() {
    if (this->root != nullptr) {
        clear();
    }
}

template <typename T>
T BST<T>::get_root()const {
    return this->root->key;
}

template <typename T>
void BST<T>::insert(const T value) {
    if (this->root == nullptr) {
        this->root = new Node(value);
        return;
    }
    insert_maker(this->root, value);
}

template <typename T>
void BST<T>::insert_maker(Node*& src, const T value) {
    if (!src) {
        src = new Node(value);
        return;
    }
    if (value < src->key) {
        insert_maker(src->left, value);
        return;
    }
    insert_maker(src->right, value);
    
}

template <typename T>
void BST<T>::clear() {
    if (this->root != nullptr) {
        cleaner(this->root);
    }
}

template <typename T>
void BST<T>::cleaner(Node*& node) {
    if (node != nullptr) {
        cleaner(node->left);
        cleaner(node->right);
        delete node;
        node = nullptr;
    }
}

template <typename T>
void BST<T>::levelorder()const {
    if (this->root != nullptr) {
        std::cout << this->root->key << '|';
        levelorder_maker(this->root);
    }
}

template <typename T>
void BST<T>::levelorder_maker(const Node* node)const {
    if (!node) {
        return;
    }
    if (node->left != nullptr) {
        std::cout << node->left->key << '|';
    }
    if (node->right != nullptr) {
        std::cout << node->right->key << '|';
    }
    levelorder_maker(node ->left);
    levelorder_maker(node->right);
}

template <typename T>
typename BST<T>::Node* BST<T>::find(const T value) {
    if (this->root == nullptr) {
        return root;
    }
    return finder(this->root, value);
}

template <typename T>
typename BST<T>::Node* BST<T>::finder( Node* node, const T value) {
    if (node == nullptr) {
        return node;
    }
    if (node->key == value) {
        return node;
    }
    return (node->key > value ? finder(node->left, value) : finder(node->right, value));
}

template <typename T>
bool BST<T>::contains(const T value) {
    return (this->find(value) != nullptr);
}

template <typename T>
int BST<T>::get_high() const {
    if (this->root != nullptr) {
        return high_getter(this->root);
    }
    return 0;
}

template <typename T>
int BST<T>::high_getter(const Node* node) const {
    
    return ((node->right) == nullptr ? node->key : high_getter(node->right));
}

template <typename T>
void BST<T>::preorder() const {
    if (this->root != nullptr) {
        print_preorder(this->root);
    }
}

template <typename T>
void BST<T>::print_preorder(const Node* node) const {
    if (node != nullptr) {
        std::cout << node->key << '|';
        print_preorder(node->left);
        print_preorder(node->right);
    }
}

template <typename T>
void BST<T>::postorder() const {
    if (this->root != nullptr) {
        print_postorder(this->root);
    }
}

template <typename T>
void BST<T>::print_postorder(const Node* node) const {
    if (node != nullptr) {
        print_postorder(node->left);
        print_postorder(node->right);
        std::cout << node->key << '|';
    }
}

template <typename T>
void BST<T>::inorder() const {
    if (this->root != nullptr) {
        print_inorder(this->root);
    }
}

template <typename T>
void BST<T>::print_inorder(const Node* node) const {
   
    if (!node) {
        return;
    }
    T val;
    if (node->left != nullptr) {
        print_inorder(node->left);
    }
    if (node->right != nullptr) {
        std::cout << node->key << '|';
        val = node->key;
        print_inorder(node->right);
    }
    if (val != node->key) {
        std::cout << node->key << '|';
    }
}