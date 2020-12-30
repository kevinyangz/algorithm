https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        if(m==0 || n ==0) return 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i =1; i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //Current char is same, what does not it mean
                // we are looking back to find the longest common subsequence for 
                //text1's first I characters and text2's first J characters 
                // to see what is the longest common subsequence for them and add one to it 
                //going back to dp[i-1][j-1] -> longest common subsquence
                //
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;   
                }
                //else 
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        
        return dp[m][n];
    }
};
