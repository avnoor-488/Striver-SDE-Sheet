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
    int height(TreeNode* root)
    {
        if(root==NULL)return 0;
	return max((1 + height(root->right)), (1 + height(root->left)));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        	if (root == NULL)return 0;

	int option1 = height(root->left) + height(root->right);
	int option2 = diameterOfBinaryTree(root->right);
	int option3 = diameterOfBinaryTree(root->left);

	return max(option2, max(option1, option3));
    }
};
