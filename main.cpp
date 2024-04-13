#include <iostream>
#include <vector>

using namespace std;

//最长（可不连续）下降子序列问题
//给定一个长度为k的序列，求它的一个最长的子序列的长度，使得这个子序列是下降的。
//例如，给定序列1 7 3 5 9 4 8，一个最长的下降子序列是1 7 5 4，长度为4。
//使用动态规划解决
int longestDecreasingSubsequence(vector<int> nums) {
    int n = nums.size();
    int maxNum = 1;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] >= nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] > maxNum) {
            maxNum = dp[i];
        }
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
