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

    int util(TreeNode* root, int &maxSum){
        if(root == nullptr) return 0;
        int left = util(root->left, maxSum);
        int right = util(root->right, maxSum);

        int maxChild = max(left, right);
        int maxIncludingRoot = max(maxChild + root->val, root->val);
        int pathViaRoot = max(maxIncludingRoot, left + right + root->val);

        maxSum =max(maxSum, pathViaRoot);
        return maxIncludingRoot;
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        util(root, maxSum);
        return maxSum;

        
    }
};