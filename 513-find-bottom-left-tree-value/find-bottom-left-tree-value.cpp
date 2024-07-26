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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        map<int, int> mpp;
        q.push({root, 0});
        mpp[0] = root->val;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int level = it.second;
            if(mpp.find(level) == mpp.end()){
                mpp[level] = node->val;
            } 
            if(node->left){
                q.push({node->left, level + 1});
            }
            if(node->right){
                q.push({node->right, level + 1});
            }
        }

        auto ans = mpp.rbegin();
        int ans1 = ans->second;

        return ans1;
    }
};