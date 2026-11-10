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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        q.push(root);
        while(!q.empty())
        {
            int l=q.size();
            vector<int>a;
            for(int i=0;i<l;i++)
            {
                TreeNode* x=q.front();
                q.pop();
                if(x->left!=NULL) q.push(x->left);
                if(x->right!=NULL) q.push(x->right);
                a.push_back(x->val);
            }
            ans.push_back(a);
        }
        return ans;
    }
};


/*
    void lo(TreeNode* root,int i,map<int,vector<int>>& ans){
        if(root==NULL)
        return;
        
        ans[i].push_back(root->val);
        lo(root->left,i+1,ans);
        lo(root->right,i+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int,vector<int>>ans;
        lo(root,0,ans);
        
        vector<vector<int>>a;
        for(auto i:ans)
        {
            a.push_back(i.second);
        }
        return a;
    }
*/