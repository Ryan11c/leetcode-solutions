#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//We perform a DFS on the tree and return 1 plus the maximum depth of the left and right subtrees.

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == nullptr) return 0;
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
};