class Solution {
public:
    int divideConquer(string &s, int start, int end, int k)
    {
        //edge case , empty string
        if(start >= end)
            return 0;
 
        vector<int>counts(26,0);
        //count the occurence of 
        for(int i = start; i< end ;i++)
        {
            counts[s[i]-'a']++;
        }
        
        
        int index1 = start;
        //find the first invalid index, start to index1 is the first good string
        while(index1 < end && counts[s[index1]-'a']>=k)
        {
            index1++;
        }
        //the entire string is a valid string,
        if(index1 >= end)
            return end-start;
        
        int index2 = index1 ;
        //cut the string into two pieces based  on the first invalid Pivot  
        //  k=2, string = ababbc   a:2 , b:2 c:1
        //ababb    c
        //k=3, s = bbaaacbd b:3,a:3,c:1,d:1 --> you only know b is valid in the entire string, but the problem is where, it is also possible , substring contains
        // valid b,but it also contains non-valid char such as c in this case. Key idea is to find the potential valid string and dive deep into it.
        //bbaaa c bd
        //but is b valid in substring bbaaa ? ans: no-> so you keep split
        //bb aaa
        //until you find the longest valid substring in each part
        while(index2<end &&  counts[s[index2]-'a']<k)
        {
            index2++;
        }
        int left  = divideConquer(s,start,index1,k);
        
        int right = divideConquer(s,index2,end,k);

        return max(left,right);
        
    }
    int longestSubstring(string s, int k) {
        return divideConquer(s,0,s.size(),k);
    }
};
