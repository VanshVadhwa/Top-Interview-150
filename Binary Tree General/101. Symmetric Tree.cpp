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
    bool isSame(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((p && !q) || (!p && q)) return false;
        if(p->val != q->val) return false;
        return isSame(p->left,q->right) && isSame(p->right,q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left,root->right);
    }
};
