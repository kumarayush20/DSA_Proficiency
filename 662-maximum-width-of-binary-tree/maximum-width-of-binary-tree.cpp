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
    int widthOfBinaryTree(TreeNode* root) {     
        if(!root) return 0;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            int mn=q.front().second;
            int first,last;
            
            for(int i=0;i<size;i++)
            {
                int curr=q.front().second-mn;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=curr;
                if(i==size-1) last=curr;
                if(node->left)
                    q.push({node->left,(long long)curr*2+1});
                if(node->right)
                    q.push({node->right,(long long)curr*2+2});
            }
            /* If you are getting runtime error while submiting the same code on leetcode,no need to worry,just do a minute change in the code,just typecast the value of index while pushing in the queue.
            You may ask since we applied a trick to tackle the integer overflow here,yes we did,but through this method we just ensure that the index we push everytime just comes under INT_MAX,
            and index difference is always under singed 32 bit ,i.e at max below 2^32 as stated in question itself. At everytime we are pushing (2*index+1) or (2*index+2),so its not exactly twice,
            its getting more than that ,thats why we need to typecast with long long.Hope its clear now. */

            ans=max(ans,last-first+1);         
        }
        return ans;      
    }
};