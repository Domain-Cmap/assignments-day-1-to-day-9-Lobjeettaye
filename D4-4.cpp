/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /**
     * @brief Helper function for standard level-order traversal
     * @param root Root node of the tree
     * @return Vector of vectors containing node values level-wise
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        // Base case: empty tree
        if (root == NULL) {
            return ans;
        }

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            // Process all nodes at the current level
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Add child nodes to the queue
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }

                // Add the node value to the current level
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }

    /**
     * @brief Main function to perform zigzag level-order traversal
     * @param root Root node of the tree
     * @return Vector of vectors with zigzag level order traversal
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Perform standard level-order traversal
        vector<vector<int>> ans = levelOrder(root);

        // Reverse alternate levels for zigzag pattern
        int n = ans.size();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 1) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};