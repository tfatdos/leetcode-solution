/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int dNum = 0;
        for(auto i : S)
            if(i == 'D')
                dNum++;
        vector<int> ans;
        int ic = 1;
        int dc = 1;
        ans.push_back(dNum);
        for(auto i : S){
            if(i == 'I')
                ans.push_back(dNum + ic++);
            else
                ans.push_back(dNum - dc++);
        }
        return ans;
    }
};
// @lc code=end

