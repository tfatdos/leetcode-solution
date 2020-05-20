/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        if(s.size() == 0 ) return 0;
        int dp[s.size()+1][32];
        memset(dp,0,sizeof(dp));
        for(unsigned int i = 0 ; i<s.size();i++){
            if(s[i] == 'a'){dp[i][1] = 1;}
            else if(s[i] == 'e'){dp[i][1<<1] = 1;}
            else if(s[i] == 'i'){dp[i][1<<2] = 1;}
            else if(s[i] == 'o'){dp[i][1<<3] = 1;}
            else if(s[i] == 'u'){dp[i][1<<4] = 1;}
            else {dp[i][0] = 1;}
            for(int j = 0 ; j <= 31 ; j++){
                if(i == 0) continue;
                if(s[i] == 'a')     {if(dp[i-1][j^1] != 0) dp[i][j] = max(dp[i][j],dp[i-1][j^1] + 1);}
                else if(s[i] == 'e'){if(dp[i-1][j^2] != 0) dp[i][j] = max(dp[i][j],dp[i-1][j^2] + 1);}
                else if(s[i] == 'i'){if(dp[i-1][j^4] != 0) dp[i][j] = max(dp[i][j],dp[i-1][j^4] + 1);}
                else if(s[i] == 'o'){if(dp[i-1][j^8] != 0) dp[i][j] = max(dp[i][j],dp[i-1][j^8] + 1);}
                else if(s[i] == 'u'){if(dp[i-1][j^16] != 0) dp[i][j] = max(dp[i][j],dp[i-1][j^16] + 1);}
                else {
                    if(dp[i-1][j] != 0)
                    dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<s.size();i++)
            if(ans < dp[i][0])
                ans = dp[i][0];
        return ans;
    }
};
// @lc code=end

