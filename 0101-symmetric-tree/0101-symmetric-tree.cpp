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
    bool Symchecker(TreeNode* rootl,TreeNode* rootr) {
        if(rootl==rootr && rootl==NULL) return 1;

        if(rootl==NULL || rootr==NULL) return 0;

        if(rootl->val==rootr->val && Symchecker(rootl->left,rootr->right) && Symchecker(rootl->right,rootr->left)) return 1;

        return 0;
    }
    bool isSymmetric(TreeNode* root) {
        return Symchecker(root,root);
    }
};