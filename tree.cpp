#include <iostream>
#include <iomanip>
#include "tree.h"
#include <cstring>
using namespace std;
node::node(string data)
{
    this->info = data;
    left = 0;
    right = 0;
    wordcount = 1;
}
node::node()
{
    info = "-";
    left = 0;
    right = 0;
    wordcount = 1;
}
void BSTree::deleteTree(node *node)
{
    if (node == NULL)
        return;

    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);

    /* then delete the node */
    // cout << "\n Deleting node: " << node->info;
    delete node;
}
BSTree::BSTree()
{
    root = NULL;
    sentencecount = 1;
}
BSTree::~BSTree() {
    this->deleteTree(root);
}
void BSTree::incrementCount()
{
    sentencecount++;
}
void BSTree::TOTALWORDLENGHT(node *r, int &total)
{
    if (r != NULL)
    {
        TOTALWORDLENGHT(r->left, total);
        total += (r->info.length()*r->wordcount);
        TOTALWORDLENGHT(r->right, total);
    }
}
void BSTree::WORDCOUNTER(node *r, int &total)
{
    if (r != NULL)
    {
        WORDCOUNTER(r->left, total);
        WORDCOUNTER(r->right, total);
        total += r->wordcount;
    }
}
void BSTree::UNIQUEWORDS(node *r, int &total)
{
    if (r != NULL)
    {
        if (r->wordcount == 1)
            total++;
        UNIQUEWORDS(r->left, total);
        UNIQUEWORDS(r->right, total);
    }
}
void BSTree::PRINTUNIQUEWORD(node *r, char c, bool charHead)
{
    if (r != NULL)
    {
        if ((r->info[0] == c || r->info[0] == c + 32) &&
            r->wordcount == 1)
        {
            if (charHead == false)
            {
                charHead = true;
                cout << "******** " << c << " ********" << endl;
            }

            cout << r->info << endl;
        }
        // if(r->left->info[0]>c)
        PRINTUNIQUEWORD(r->right, c, charHead);
        // else
        PRINTUNIQUEWORD(r->left, c, charHead);
    }
}
void BSTree::WORDUSEDMORE(node *r, int totalWords, bool Exist)
{
    if (r != NULL)
    {
        // cout<<"check";
        if (((r->wordcount / totalWords) * 100) >= 5 && r->info.length() > 3)
        {
            // cout<<"ASf"<<endl;
            if (!Exist)
            {
                cout << "WORDS USED TOO OFTEN: (  WORDS OF MORE THAN 3 LETTERS THAT ARE USED MORE THAN 5% OF THE TOTAL NUMBER   OF WORDS OF MORE THAN 3 LETTERS )" << endl;

                Exist = true;
            }
            cout << r->info << "\t\t Used " << ((r->wordcount / totalWords) * 100) << "%" << endl;
        }
        // if( r->info.length()>3)
        // cout<<r->info<<"     "<<r->wordcount <<endl;
        WORDUSEDMORE(r->left, totalWords, Exist);
        WORDUSEDMORE(r->right, totalWords, Exist);
    }
}
void BSTree::insertItem(string data)
{
    node *temp = root;
    node *ptr = new node(data);
    while (temp != NULL)
    {

        if (temp->info == data)
        {
            temp->wordcount++;
            return;
        }
        if (data > temp->info && temp->right != NULL)
            temp = temp->right;
        if (data < temp->info && temp->left != NULL)
            temp = temp->left;
        if (data > temp->info && temp->right == NULL)
        {
            temp->right = ptr;
            // cout << "Inserted at right " << endl;
            return;
        }
        if (data < temp->info && temp->left == NULL)
        {
            temp->left = ptr;
            // cout << "Inserted at left " << endl;
            return;
        }
    }
    if (root == NULL)
        root = ptr;
}

int BSTree::AvgWordLen()
{
    int TotalLen = 0, TotalWords = 0;
    this->TOTALWORDLENGHT(root, TotalLen);
    this->WORDCOUNTER(root, TotalWords);
    return TotalLen / TotalWords;
}
int BSTree::WordCounter()
{
    int TotalWords = 0;
    this->WORDCOUNTER(root, TotalWords);
    return TotalWords;
}
int BSTree::UniqueWordCount()
{
    int TotalUniqueWords = 0;
    this->UNIQUEWORDS(root, TotalUniqueWords);
    return TotalUniqueWords;
}
int BSTree::TotalSentence()
{
    return sentencecount;
}
int BSTree::AvgSentenceLen()
{
    int TotalWords = 0;
    this->WORDCOUNTER(root, TotalWords);
    return TotalWords / this->sentencecount;
}
int BSTree::UniqueWord3Letter()
{
    int TotalWords = 0;
    this->UNIQUEWORD3LETTER(root, TotalWords);
    return TotalWords;
}
void BSTree::UNIQUEWORD3LETTER(node *r, int &total)
{
    if (r != NULL)
    {
        if (r->wordcount == 1 && r->info.length() > 3)
            total++;
        UNIQUEWORD3LETTER(r->left, total);
        UNIQUEWORD3LETTER(r->right, total);
    }
}
void BSTree::WordUsedMore()
{
    int TotalWords = 0;
    this->WORDCOUNTER(root, TotalWords);
    this->WORDUSEDMORE(root, TotalWords, false);
}
void BSTree::PrintUniqueWords()
{

    for (char c = 'A'; c <= 'Z'; c++)
    {
        this->PRINTUNIQUEWORD(root, c, false);
    }
}