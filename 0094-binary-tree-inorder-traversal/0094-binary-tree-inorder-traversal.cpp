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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>a;
        while(root!=NULL)
        {
            if(root->left==NULL)
            {
                a.push_back(root->val);

                root=root->right;
            }
            else
            {
                TreeNode* prev=root->left;
                while(prev->right!=NULL && prev->right!=root)
                prev=prev->right;

                if(prev->right==NULL)
                {
                    prev->right=root;
                    root=root->left;
                }
                else
                {
                    prev->right=NULL;
                    a.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return a;
    }
};



/*

        vector<int>a;
        if(root==NULL)
        return a;
        stack<TreeNode*>st;
        TreeNode* x=root;

        while(true)
        {
            if(x!=NULL)
            {
                st.push(x);
                x=x->left;
            }
            else
            {
                if(st.empty())
                break;

                x=st.top();
                st.pop();
                a.push_back(x->val);
                x=x->right;
            }
        }
        return a;

*/

/*
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>a;
        iot(root,a);
        return a;
    }
    void iot(TreeNode* root,vector<int>& a){
        if(root==NULL)
        return;
        iot(root->left,a);
        a.push_back(root->val);
        iot(root->right,a);
    }
*/