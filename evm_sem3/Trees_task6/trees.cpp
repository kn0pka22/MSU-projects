#include <iostream>
#include "trees.hpp"

TreeNode *FindById(TreeNode *node, int id) {
    if (node == nullptr)
        return nullptr;
    if (node->id == id)
        return node;
    else {
        TreeNode *tmp;
        tmp = FindById(node->Left, id);
        if (tmp != nullptr)
            return tmp;
        tmp = FindById(node->Right, id);
        if (tmp != nullptr)
            return tmp;
    }
    return nullptr;
}




  void CalsSums(TreeNode* root, long long& res)
    {
        if(root)
        {
            res+=root->value;
            CalsSums(root->Left,res);
            CalsSums(root->Right,res);
        }
    }




void PrintTree(TreeNode *node, int n_separators) {
    if (node == nullptr)
        return;
    PrintTree(node->Right, n_separators + 1);
    for (int i = 0; i < n_separators; i++) {
        std::cout << "\t";
    }
    std::cout<<"[" << node->id << "]: " << node->value <</* " (" << node->sum <<")"<<*/ std::endl;
    PrintTree(node->Left, n_separators + 1);
}

long long comparison(TreeNode* root, long long& ans, long long sum){
        if(root)
        {
            int res=root->value+comparison(root->Left,ans,sum)+comparison(root->Right,ans,sum);
            ans=std::max(ans,res*(sum-res));
            return res;
        }
        else
        {
            return 0;
        }
}


int Process(TreeNode* root){
	
	 long long sum=0;
   CalsSums(root,sum);
   long long ans=0;
   comparison(root, ans, sum);
	 std::cout<<"Res:    "<<ans<<std::endl;
   return ans;



	return 0;
}
















