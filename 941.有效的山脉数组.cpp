/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        if(a.size()<3) return false;
        bool f = false;
        bool g = false;
        for(unsigned int i=0;i<a.size()-1;i++){
            if(a[i]==a[i+1]) return false;
            if(g == false){
                if(a[i] > a[i+1])
                    return false;
                else{
                    g = true;
                }
            }else{
                if(f == false){
                    if(a[i] > a[i+1])
                        f = true;
                }else{
                    if(a[i]<a[i+1])
                        return false;
                }
            }
        }
        if(g && f)
            return true;
        return false;
    }
};
// @lc code=end

