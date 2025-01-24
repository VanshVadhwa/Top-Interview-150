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
    TreeNode* create(vector<int>& pre, vector<int>& in, int& index, int start, int end, unordered_map<int,int>& map) {
        if(start > end) return nullptr;

        int pos = map[pre[index]];
        TreeNode* root = new TreeNode(pre[index++]);

        root->left = create(pre,in,index,start,pos-1,map);
        root->right = create(pre,in,index,pos+1,end,map);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++) map[inorder[i]] = i;
        int index = 0;
        return create(preorder,inorder,index,0,n-1,map);
    }
};
