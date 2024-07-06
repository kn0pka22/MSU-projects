#include <iostream>
//#include <string>
#include "trees.hpp"

int main() {

	TreeNode* tree;
  int parent_id, id;
  long long val;
  std::string tmp, dir;
  
	std::cin >> tmp >> tmp >> id >> val;
  tree = new TreeNode(id, val);

    while (std::cin >> parent_id >> dir >> id >> val) {
        TreeNode* parent = FindById(tree, parent_id);
        if (dir == "L") {
            parent->Left = new TreeNode(id, val);
        } 
        else if (dir == "R") {
            parent->Right = new TreeNode(id, val);
        }
    }
    
    std::cout<<"RESULT: "<<std::endl;
    Process(tree);
		PrintTree(tree);
    return 0;
}

