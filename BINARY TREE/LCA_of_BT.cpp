// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == NULL) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL) return root;
        if(left != NULL) return left;
        return right;
    }
};

// Shorter code

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == NULL) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q), *right = lowestCommonAncestor(root->right, p, q);
        return left && right ? root : left ? left : right;
    }
};