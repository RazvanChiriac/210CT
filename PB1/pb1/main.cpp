#include<string.h>
#include <iostream>
#include<cstdlib>
#include <fstream>
using namespace std;

/*
Title: Binary search tree
Author: Hintea, D.
Date: 2018
Availability: http://moodle.coventry.ac.uk
*/

class BinTreeNode
{
public:
    BinTreeNode(char value[20])
    {
        strcpy(this->value, value);
        this->left = NULL;
        this->right = NULL;

    }
    char value[20];
    BinTreeNode* left;
    BinTreeNode* right;


};

BinTreeNode* tree_insert(BinTreeNode* tree, char item[20])
{
    if (tree == NULL)
        tree = new BinTreeNode(item);
    else if (strcmp(item,tree->value)<0)
        if (tree->left == NULL)
            tree->left = new BinTreeNode(item);
        else
            tree_insert(tree->left, item);
    else if (tree->right == NULL)
        tree->right = new BinTreeNode(item);
    else
        tree_insert(tree->right, item);
    return tree;

}

//Author: Razvan Chiriac Eduard
//Date: 2018

int number_nodes=0;


int frecventa(BinTreeNode* tree,char word[20])
{
    if(tree==NULL)
        return number_nodes;

    if(strcmp(tree->value,word)==0)
        number_nodes++;

    frecventa(tree->left,word);
    frecventa(tree->right,word);

}

void in_order(BinTreeNode* tree)
{
    int nr;
    if (tree->left != NULL)
        in_order(tree->left);
    cout << tree->value <<" ";

    if (tree->right != NULL)
        in_order(tree->right);
}

void pre_order(BinTreeNode* tree, BinTreeNode* copy_root)
{
    int nr;
    if(tree!=NULL)
    {

        cout << tree->value <<" ";
        nr=frecventa(copy_root,tree->value);
        cout<<nr<<endl;
        number_nodes=0;
        pre_order(tree->left,copy_root);
        pre_order(tree->right,copy_root);
    }
}
int nr=0;
void find_word(BinTreeNode* tree, char word[20])
{
    if(tree!=NULL)
    {
        if(strcmp(tree->value,word)==0)
        {
            cout<<tree->value<<endl<<"yes";
            nr=1;

        }

        else if(nr!=1)
        {
            cout<<tree->value<<" ";
            find_word(tree->right,word);
            find_word(tree->left,word);
        }
    }
}

int main()
{
    char file[100];
    char word[50];
    char word_find[50];
    ifstream f;
    cin.getline(file,100);
    f.open(file);
    if(!f.is_open())
    {
        exit(EXIT_FAILURE);
    }
    f>>word;
    BinTreeNode* t = tree_insert(0, word);

    while(f.good())
    {
        f>>word;

        tree_insert(t, word);

    }
    BinTreeNode* copy_root=t;
    pre_order(t, copy_root);
    cout<<"Enter the word that you want to find: "<<endl;
    cin>>word_find;
    cout<<"The path is: ";
    find_word(t,word_find);
    if(nr==0)
        cout<<endl<<"no";

    return 0;
}

