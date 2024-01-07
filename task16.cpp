/*16. Given the root of a binary search tree, and an integer k , return the kth smallest value (1-indexed) of all the values of the nodes in the tree. */

#include<iostream>
#include <stack>
 
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
int kthSmallest(TreeNode* root, int k) {
std::stack<TreeNode*> nodes;
TreeNode* current = root;
 
while (current || !nodes.empty()) {
while (current) {
nodes.push(current);
current = current->left;
}
current = nodes.top();
nodes.pop();
k--;
if (k == 0) {
return current->val;
}
current = current->right;
}
return -1; 
}
};
 
int main() {
TreeNode* root = new TreeNode(5);
root->left = new TreeNode(3);
root->right = new TreeNode(6);
root->left->left = new TreeNode(2);
root->left->right = new TreeNode(4);
root->left->left->left = new TreeNode(1);
 
Solution solution;
int k = 3; 
int result = solution.kthSmallest(root, k);
std::cout << "The " << k << "th smallest element is: " << result << std::endl;
delete root->left->left->left;
delete root->left->left;
delete root->left->right;
delete root->left;
delete root->right;
delete root;
return 0;
}
