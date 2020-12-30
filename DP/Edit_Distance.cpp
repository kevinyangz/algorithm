class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        /*   - h o r s e 
           - 0 1 2 3 4 5 
           r 1
           o 2 
           s 3 
        */
        
        for(int i = 0; i <=m;i++)
        {
            dp[i][0] = i;
        }
        for(int i = 0;i<=n;i++)
        {
            dp[0][i] = i;
        }
        for(int i =1; i <= m;i++)
        {
            for(int j=1; j<=n;j++)
            {
                /*
                    if i-1 == j-1 we do not need to do anything
                    we are looking back to see how many number of operations are needed 
                    for length i-1 and j-1 and use that 
                */
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    //The current char is different for i and j
                    //[i-1][j-1] ->replace current from i-1 to j-1
                    //delete one char for each two cases 
                    dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                }
            }
        }
        
        //backTrack to recover the "modify" sequence 
        int length = dp[m][n];
        int i = m, j=n;
        while(length>0 &&i>0 &&j>0)
        {
            if(word1[i-1]==word2[j-1])
            {
                i--;
                j--;
                cout<<"j"<<endl;
                continue;
            }
            else if(dp[i-1][j-1] <= dp[i-1][j] && dp[i-1][j-1]<=dp[i][j-1])
            {
                  cout<<"replace "<<word1[i-1]<<" "<<word2[j-1]<<endl;
                i--;
                j--;
              
            }
            else if(dp[i-1][j] <= dp[i-1][j-1] && dp[i-1][j] <= dp[i][j-1])
            {
                 cout<<"remove i -> "<<word1[i-1]<<endl;
                i-=1;
               
            }
            else
            {
                  cout<<"remove j -> "<<word2[j-1]<<endl;
                j-=1;
              
            }
            length--;
        }
        
        return dp[m][n];
    }
};
