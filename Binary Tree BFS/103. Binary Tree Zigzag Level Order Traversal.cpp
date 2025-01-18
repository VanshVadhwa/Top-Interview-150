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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        deque<TreeNode*> dq;
        dq.push_back(root);
        bool level = true;

        while(!dq.empty()) {
            int n = dq.size();
            vector<int> temp(n);
            for(int i=0;i<n;i++) {
                if(level) {
                    TreeNode* curr = dq.back();
                    dq.pop_back();
                    temp[i] = curr->val;
                    if(curr->left) dq.push_front(curr->left);
                    if(curr->right) dq.push_front(curr->right);
                }
                else {
                    TreeNode* curr = dq.front();
                    dq.pop_front();
                    temp[i] = curr->val;
                    if(curr->right) dq.push_back(curr->right);
                    if(curr->left) dq.push_back(curr->left);
                }
            }
            level = !level;
            ans.push_back(temp);
        }
        return ans;
    }
};
