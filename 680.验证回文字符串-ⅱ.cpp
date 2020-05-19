/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s){
        if(s.size() == 0) return true;
        string sResever(s.rbegin(),s.rend());
        if (s == sResever) return true;
        return false;
    }

    bool validPalindrome(string s) {
        if(isPalindrome(s) == true)
            return true;
        int l = 0;
        int r = s.size();
        while(s[l] == s[r-1] && l<=r){
            l++;
            r--;
        }
        if(isPalindrome(s.substr(l,r-l-1)) || isPalindrome(s.substr(l+1,r-l-1)) )
            return true;
        return false;
    }
};
// @lc code=end

