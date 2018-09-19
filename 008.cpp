/* A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

   Given the root to a binary tree, count the number of unival subtrees.

   For example, the following tree has 5 unival subtrees:

      0
     / \
    1   0
       / \
      1   0
     / \
    1   1
 */


#include <iostream>
#include <vector>
#include <algorithm>
//#include <stdint.h>

using namespace std;

struct node {
        int value;
        node* parent;
        node* left;
        node* right;
};

class binary_tree {
private:

public:
node* root;

void newnode(int data){
        node *x= new node;
        x->value=data;
        x->parent=NULL;
        x->left=NULL;
        x->right=NULL;

        root=x;
}

void addleft(node* parent, int data){
        node *x = new node;
        x->value=data;
        x->parent=NULL;
        x->left=NULL;
        x->right=NULL;
        parent->left=x;
}

void addright(node* parent, int data){
        node *x = new node;
        x->value=data;
        x->parent=parent;
        x->left=NULL;
        x->right=NULL;
        parent->right=x;
}

bool check_unival_tree(node* N, int& count){
        if (N==NULL || (N->left==NULL && N->right==NULL)) {
                count++;
                return true;
        }
        else{
                if((N->left->value==N->right->value) && (N->left->value==N->value)) {

                        if(check_unival_tree(N->left,count)&&check_unival_tree(N->right,count)) {
                                count++;
                                return true;
                        }
                }
        }
        check_unival_tree(N->left,count)&&check_unival_tree(N->right,count);
        return false;
}
};

int main(){
        binary_tree tree;
        tree.newnode(0);

        tree.addleft(tree.root,1);
        tree.addright(tree.root,0);
        tree.addleft(tree.root->right,1);
        tree.addright(tree.root->right,0);
        tree.addleft(tree.root->right->left,1);
        tree.addright(tree.root->right->left,1);
//tree.addright(tree.root,0);
//tree.addright(tree.root,0);
        int count=0;
        tree.check_unival_tree(tree.root,count);

        cout<<"Number of Unival trees = "<<count<<endl;

}
