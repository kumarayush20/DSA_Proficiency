/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void inorder(TreeNode* root){
        if(!root) return;

        if(root->left) parent[root->left] = root;
        inorder(root->left);

        if(root->right) parent[root->right] = root;
        inorder(root->right); 
    }

    void BFS(TreeNode* target, int k, vector<int> &result){
        queue <TreeNode*> que;
        que.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        int curr_level = 0;
        while(!que.empty()){
            int n = que.size();
            if(curr_level++==k) break;
            while(n--){
                TreeNode *curr = que.front();
                que.pop();

                //left
                if(curr->left != NULL && !visited.count(curr->left)){
                    que.push(curr->left);
                    visited.insert(curr->left);
                }

                //right
                if(curr->right != NULL && !visited.count(curr->right)){
                    que.push(curr->right);
                    visited.insert(curr->right);
                }

                //parent
                if(parent.count(curr) && !visited.count(parent[curr])){
                    que.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
        }
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        inorder(root);
        BFS(target, k, result);
        return result;
    }
};