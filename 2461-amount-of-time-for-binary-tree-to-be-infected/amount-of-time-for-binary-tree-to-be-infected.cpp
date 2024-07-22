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
    unordered_map<TreeNode*, TreeNode*> parent;

    TreeNode* levelorder(TreeNode* root, int start){
        if(!root) return NULL;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->val==start) res = node;
            q.pop();
            
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    int BFS(TreeNode* target, int &ans){
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            while(size--){
                TreeNode* node = q.front();
                q.pop();

                //left
                if(node->left && !visited.count(node->left)){
                    flag = 1;
                    q.push(node->left);
                    visited.insert(node->left);
                }

                //left
                if(node->right && !visited.count(node->right)){
                    flag = 1;
                    q.push(node->right);
                    visited.insert(node->right);
                }

                //parent
                if(parent.count(node) && !visited.count(parent[node])){
                    flag = 1;
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            if(flag)ans++;
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode *target = levelorder(root, start);
        int ans = 0;
        int maxi = BFS(target, ans);
        return maxi;
    }
};