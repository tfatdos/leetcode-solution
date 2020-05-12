/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        int ans = 0;
        for(unsigned int i = 0;i<nums.size();i++){
            int cnt =  0;
            if(used[i] == false){
                int t = i;
                while(used[t] == false){
                    cnt ++;
                    used[t] = true;
                    t = nums[t];
                }
                if (ans < cnt)
                    ans = cnt;
            }
        }
        return ans;
    }
};
// @lc code=end

