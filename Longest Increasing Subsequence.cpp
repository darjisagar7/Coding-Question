#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int start, end, mid, ans = -1;
        for(auto n:nums){
            start = 0;
            end = ans;
            // cout<<"start "<<start<<" end "<<end<<"\n";
            while(start<=end){
                mid = start+(end-start)/2;
                if(dp[mid] >= n) end = mid - 1;
                else start = mid + 1;
            }
            dp[start] = n;
            ans = max(ans, start);
        }
        return ans+1;
    }

int main()
{
    vector<int> vec = {10,22,9,33,21,50,41,60,80};
    int ans = lengthOfLIS(vec);
    cout<<ans;
    return 0;
}
