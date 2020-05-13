/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,int> m;
    int maxDeep;
    void getDeep(TreeNode* root,int deep){
        if(root == NULL) return ;
        m[root] = deep;
        maxDeep = max(maxDeep,deep);
        getDeep(root->left,deep+1);
        getDeep(root->right,deep+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        maxDeep = -1;
        getDeep(root,0);
        vector<vector<int>> ans(maxDeep+1,vector<int>());
        for(auto i : m){
            ans[i.second].push_back(i.first->val);
        }
        return ans;
    }
};
// @lc code=end

