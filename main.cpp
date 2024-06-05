#include <iostream>
#include <vector>

using namespace std;

//最长（可不连续）下降子序列问题
//使用动态规划解决
int longestDecreasingSubsequence(vector<int> nums) {
    int n = nums.size();
    int maxNum = 1;
    vector<int> dp(n, 1);
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(nums[i]>=nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxNum=max(maxNum,dp[i]);

    }
    return maxNum;
}

int main() {
    int k;
    cin >> k;
    vector<int> nums(k);
    for (int i = 0; i < k; i++) {
        cin >> nums[i];
    }
    cout << longestDecreasingSubsequence(nums) << endl;
    return 0;
}
