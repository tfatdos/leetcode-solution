/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.size() == 0) return 0;
        int ans = 0;
        for(unsigned int i = 0 ; i< A[0].size();i++){
            for(unsigned int j = 0 ;j < A.size()-1;j++){
                if(A[j][i]>A[j+1][i]){
                    ans ++;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

