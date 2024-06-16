// https://leetcode.com/problems/validate-binary-search-tree

// Another Approach - check if inorder traversal is sorted or not

// Solution 1

class Solution {
public:
    bool helper(TreeNode* root, long min, long max) {
        if(root == NULL) return true;

        if(root->val <= min || root->val >= max) return false;

        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

// Solution 2

class Solution {
public:
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(root == NULL) return true;
        if((min == NULL || root->val > min->val) && (max == NULL || root->val < max->val))
            return helper(root->left, min, root) && helper(root->right, root, max);
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};