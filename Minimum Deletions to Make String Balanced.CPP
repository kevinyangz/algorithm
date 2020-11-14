class Solution {
public:
    int minimumDeletions(string s) {
        //aababbab
        //bbaaaaabb
        //left and right 
        //left is counting b, right is counting a
        //aababbab
         
        int left = 0 , right = s.size()-1;
        //1.forward scanning, delete all b --> maintain a count 
        //2.backward scanning,make sure no A is after b 
        vector<int>counts(s.size()+1,0);
       
        //counts array maintain number of b in the first I chars 
        for(int i = 1; i <= s.size();i++)
        {
            counts[i] = counts[i-1] + (s[i-1]=='b');       
        }
        //delete all b  from left 
        int result = counts.back();
         int aCount = 0;
        //scan the array from right to left 
        //we have counts[i] --> number of B before I 
        //This time we are interested in number of a, we encounter so far 
        //Delete all the b before it and all the a after it , then the string is balanced 
        
        for(int i = s.size()-1; i >=0 ;i--)
        {
            if(s[i]=='a')
            {
                //delete all be the b before i + all the a after i 
                //--> valid 
                result = min(result, counts[i] + aCount);
                aCount++;
            }
           // result = min(aCount,counts[i+1]);
        }
        result = min(result,aCount);
        return result;
    }
};
