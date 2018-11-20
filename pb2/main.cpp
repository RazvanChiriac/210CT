#include<stdlib.h>
#include <iostream>
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
    BinTreeNode(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
        this->root=NULL;
    }
    int value;
    BinTreeNode* root;
    BinTreeNode* left;
    BinTreeNode* right;

};
/*
Title: Binary search tree
Author: Hintea, D.
Date: 2018
Availability: http://moodle.coventry.ac.uk
*/
BinTreeNode* tree_insert(BinTreeNode* tree, int item)
{
    if (tree == NULL)
        tree = new BinTreeNode(item);
    else if (item < tree->value)
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
/*
Title: Binary search tree
Author: Hintea, D.
Date: 2018
Availability: http://moodle.coventry.ac.uk
*/
void in_order(BinTreeNode* tree)
{
    if (tree->left != NULL)
        in_order(tree->left);
    cout << tree->value <<endl;
    if (tree->right != NULL)
        in_order(tree->right);
}

//Author:Razvan Chiriac

// 'tree_min' is a function which is searching for the minimum value in a binary tree
BinTreeNode* tree_min(BinTreeNode* tree)
{
    while(tree->left!=NULL)
        tree=tree->left;
    return tree;
}

//node_delete is for deleting a node in a binary tree
BinTreeNode* node_delete(BinTreeNode* tree, int item)
{
    if(tree==NULL)
        return tree;
    if(tree->value>item)
        tree->left= node_delete(tree->left,item);
    else  if(tree->value<item)
        tree->right= node_delete(tree->right,item);
    //Case 1: No children, the node is a leaf.
    else if(tree->right==NULL && tree->left==NULL)

    {
        delete tree;
        tree=NULL;
    }
    else
     //Case 2: The node has only one children
    {
        BinTreeNode* p ;
        if(tree->right!=NULL&&tree->left==NULL )
        {
            BinTreeNode* p=tree;
            tree=tree->right;
            delete p;
        }
        else if(tree->left!=NULL&&tree->right==NULL)
        {
            BinTreeNode* p=tree;
            tree=tree->left;
            delete p;
        }
        //Case 3: The node has 2 children
        else
        {
            BinTreeNode* p=tree_min(tree->right);
            tree->value=p->value;
            tree->right=node_delete(tree->right,p->value);
        }

    }
    return tree;
}

int main(int argc, char *argv[])
{
    int nodes,node,root,delete_node;
    cout<<"Enter the root:"<<endl;
    cin>>root;
    BinTreeNode* t = tree_insert(0, root);
    cout<<"How many nodes do you want to enter?:"<<endl;
    cin>>nodes;
    cout<<"Enter the nodes:"<<endl;
    for(int i=1; i<=nodes; i++)
    {
        cin>>node;
        tree_insert(t,node);
    }
    cout<<endl;
    cout<<"Enter the node that you want to delete:"<<endl;
    cin>>delete_node;
    node_delete(t,delete_node);
    cout<<"The tree after deletion:"<<endl;
    in_order(t);
    return 0;
}
