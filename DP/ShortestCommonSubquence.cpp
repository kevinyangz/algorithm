class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        if(str1.empty()) return str2;
        if(str2.empty()) return str1;
       int m = str1.size();
       int n = str2.size();
       vector<vector<int>>dp(m+1,vector<int>(n+1,0));
       for(int i = 0 ;i <=m;i++)
       {
           dp[i][0] = i;
       }
        for(int j = 0; j <=n;j++)
        {
            dp[0][j] = j;
        }
        for(int i = 1; i <=m ;i++)
        {
            for(int j = 1; j <=n ;j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        }
        int length = dp[m][n];
        //cout<<length<<endl;
        string result(length,' ');
        int i = m , j = n;
        int index = length - 1;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                result[index]= str1[i-1];
                i--;
                j--;

            }
            //XXXi -> XXX   `                                           XXXi
            //YYj     YYj has a smaller size of subsequence compare to  YY
            else if(dp[i-1][j] < dp[i][j-1])
            {
                result[index]= str1[i-1];
                i--;
            }
            else
            {
                result[index] = str2[j-1];
                j--;
            }
            
            index-=1;
        }
        while(i>0)
        {
            result[index]=str1[i-1];
            index-=1;
            i--;
        }
        while(j>0)
        {
            result[index] = str2[j-1];
            index-=1;
            j--;
        }
        
        return result;
    }
};
