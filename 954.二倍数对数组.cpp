/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */

// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int,int>m;
        sort(A.begin(),A.end());
        for(auto i : A){
            m[i]++;
        }
        for(auto i : m){
            if(i.second == 0) continue;
            if(i.first < 0){
                if(i.first % 2 != 0 || i.second > m[i.first/2]) return false;
                m[i.first/2] -= i.second;
                cout<<i.first<<endl;
            }else if(i.first > 0){
                if(m[i.first * 2] < i.second) return false;
                m[i.first*2]-=i.second;
                cout<<i.first<<endl;
            }else{
                if(i.second % 2 !=0) return false;
            }
        }
        return true;
    }
};
// @lc code=end

