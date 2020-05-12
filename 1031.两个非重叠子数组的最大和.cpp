/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> lSum(A.size()+1,0);
        for(unsigned int i=1;i<=A.size();i++){
            lSum[i] = lSum[i-1]+A[i-1];
        }
        int ans = 0;
        for(int k = 0 ; k < 2;k++){
            int preSum = 0;
            for(int i=L;i+M<lSum.size();i++){
                preSum = max(preSum,lSum[i]-lSum[i - L]);
                ans = max(ans,preSum+ lSum[i + M] -lSum[i]);
            }
            swap(L,M);
        }
        return ans;
    }
};
// @lc code=end