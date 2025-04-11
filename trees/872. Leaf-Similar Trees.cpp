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

/*
What we do here is create a helper function and perform dfs. We can check if a node is a leaf by checking
if the right and left are nullptrs. If they are, we add them to a array and check if the two arrays are the same.
*/
 
class Solution {
    public:
        void dfs(TreeNode* root, vector<int>& res){
            if(!root) return;
            if(root->left == nullptr && root->right == nullptr){
                res.push_back(root->val);
            }
            dfs(root->left, res);
            dfs(root->right, res);
        }
    
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            vector<int> res1, res2;
            dfs(root1, res1);
            dfs(root2, res2);
            if(res1 == res2) return true;
            else return false;
        }
};