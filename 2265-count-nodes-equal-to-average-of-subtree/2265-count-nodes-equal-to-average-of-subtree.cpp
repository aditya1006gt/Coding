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
    pair<int,int> FindAvg(int& n, TreeNode* root, int& ans) {
        if(root==NULL) return {0,0};
        auto [l,dl]=FindAvg(n,root->left,ans);
        auto [r,dr]=FindAvg(n,root->right,ans);

        int val=root->val;
        if((l+r+val)/(dl+dr+1)==val) {
            ans++;
        }
        return {l+r+val,dl+dr+1};
    }
    int averageOfSubtree(TreeNode* root) {
        TreeNode* temp=root;
        queue<TreeNode*>q;
        q.push(root);
        int n=0;
        while(!q.empty()) {
            n++;
            TreeNode* tp=q.front();
            q.pop();
            if(tp->left) q.push(tp->left);
            if(tp->right) q.push(tp->right);
        }
        int ans=0;
        FindAvg(n,root,ans);
        return ans;
    }
};