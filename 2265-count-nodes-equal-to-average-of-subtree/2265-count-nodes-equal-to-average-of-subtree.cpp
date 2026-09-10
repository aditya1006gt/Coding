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
    pair<int,int> FindAvg(TreeNode* root, int& ans) {
        if(root==NULL) return {0,0};
        auto [l,dl]=FindAvg(root->left,ans);
        auto [r,dr]=FindAvg(root->right,ans);

        int val=root->val;
        if((l+r+val)/(dl+dr+1)==val) {
            ans++;
        }
        return {l+r+val,dl+dr+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        FindAvg(root,ans);
        return ans;
    }
};