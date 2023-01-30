#ifndef BST_H
#define BST_H

#include <iostream>

template <typename T>
class BST {
private:
    struct Node {
        T key;
        Node* left;
        Node* right;
        Node() : key{0}, left{nullptr}, right{nullptr} {};
        Node(const T data) : key{data}, left{nullptr}, right{nullptr} {};
    } *root;
public:
    BST();
    BST(const T);
    BST(const BST&);
    BST(BST&&);
    ~BST();
public:
    void insert(const T);
    void clear();
    void preorder()const;
    void inorder()const;
    void postorder()const;
    void levelorder()const;
    T get_root()const;
    int get_high()const;
    bool contains(const T);
    Node* find(const T);
private:
    void copy_maker(Node*&, const Node*);
    void insert_maker(Node*&, T);
    void levelorder_maker(const Node*) const;
    Node* finder(Node*, const T);
    void cleaner(Node*&);
    int high_getter(const Node*) const;
    void print_preorder(const Node*)const;
    void print_postorder(const Node*)const;
    void print_inorder(const Node*)const;
};

#endif // BST_H