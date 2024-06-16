// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL) 
                res += "#,";
            else {
                res += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            getline(ss, str, ',');
            if(str == "#")
                front->left = NULL;
            else {
                front->left = new TreeNode(stoi(str));
                q.push(front->left);
            }

            getline(ss, str, ',');
            if(str == "#")
                front->right = NULL;
            else {
                front->right = new TreeNode(stoi(str));
                q.push(front->right);
            }
        }
        return root;
    }
};