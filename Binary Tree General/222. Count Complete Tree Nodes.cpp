/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int height(TreeNode* root) {
        int ans = 0;
        while(root) {
            ans += 1;
            root = root->left;
        }
        return ans;
    }

public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int left = height(root->left);
        int right = height(root->right);

        if(left==right) {
            return (1 << left) + countNodes(root->right);
        }
        else {
            return (1 << right) + countNodes(root->left);
        }
    }
};
