#include <iostream>
#include <fstream>
using namespace std;

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class node
{
public:
    string info;
    int wordcount;
    node *left;
    node *right;
    node(string);
    node();
};

class BSTree
{
private:
    node *root;
    int sentencecount;
    // Recursive preorder
    void TOTALWORDLENGHT(node *r, int &total);
    // Recursive inOrder
    void WORDCOUNTER(node *r, int &total);
    // Recursive postorder
    void UNIQUEWORDS(node *r, int &total);
    void UNIQUEWORD3LETTER(node *r, int &total);
    // Recursive destroy
    void destroy(node *&);
    void WORDUSEDMORE(node *r, int totalWords,bool Exist);
    void PRINTUNIQUEWORD(node *r, char, bool charHead );
    void deleteTree(node *node);

public:
    void incrementCount();
    // constructor
    BSTree();
    // destructor
    ~BSTree();
    // function called by client to distroy the tree
    // Copy constructor
    //   BSTree (const BSTree<T> &);
    // Overloaded =
    //   const BSTree<T> & operator= (const BSTree<T> &);
    // Copy a tree
    //   void copy ( node<T> *&, node<T> *);
    // Check if tree is empty
    // bool isEmpty();
    // Insert an item in the tree
    void insertItem(string item);
    // Delete an item from the tree - client calls

    // Recursive delete item
    //   void deleteItem (node<T> *&, T );
    // Delete node
    //   void deleteNode (node<T> *& );
    // Search item
    // bool searchItem(string item);
    // Print items in preorder - called by client
    int WordCounter();
    // Print items in sorted order - called by client
    int AvgWordLen();
    // Print items in postorder - called by client
    int UniqueWordCount();
    int TotalSentence();
    int AvgSentenceLen();
    int UniqueWord3Letter();
    void WordUsedMore();
    void PrintUniqueWords();
};

#endif