#include <iostream>



struct TreeNode {

 int id; // id of element (used when initializing a tree)
 long long value; // stored value
 long long sum; // sum of all elements in current sub-tree
 TreeNode* Left;
 TreeNode* Right;

 TreeNode(int id, long long value) :
            id(id),
            value(value),
            //sum(0),
            Left(nullptr),
            Right(nullptr) {}
 ~TreeNode() {
 	if (Left) delete Left;
 	if (Right) delete Right;
 }
};


TreeNode *FindById(TreeNode *node, int id);
void PrintTree(TreeNode *node, int n_separators=0);


 void CalsSums(TreeNode* root, long long& res);

long long comparison(TreeNode* root, long long& ans, long long sum);

int Process(TreeNode* root);


