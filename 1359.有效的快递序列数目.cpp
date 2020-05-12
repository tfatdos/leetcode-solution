/*
 * @lc app=leetcode.cn id=1359 lang=cpp
 *
 * [1359] 有效的快递序列数目
 */

// @lc code=start
class Solution {
public:
    int countOrders(int n) {
        long long preNum = 1;
        long long ans = 1;
        for(int i=1;i<=n;i++){
            long long combine = (i - 1) * 2 + 1 ;
            long long gap = (2 * ( i - 1 ) + 1) * (2 * (i - 1)) / 2;
            ans = ans * (combine + gap) % 1000000007;
            preNum = ans;
        }
        return ans;
    }
};
// @lc code=end

