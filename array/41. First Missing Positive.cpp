/*
  1.Naive Thought is to use sort NlogN and binary search on Index
  2.Second naive though is to use HashMap and iterate from lowest element and see where we stuck
  3.Cyclic Sort O(N) which takes the advantage of "First Missing positive number" and we do not care about number larger than the size or smaller and equal to ZERO
  
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
            return 1;
        for(int i = 0; i < nums.size();i++)
        {
            int cur = nums[i];
            while(cur-1 < nums.size() && cur-1 >=0 && nums[cur-1]!=cur)
            {
                int temp = nums[cur-1];
                nums[cur-1] = cur;
                cur = temp;
            }
        }
        
        for(int i =0;i < nums.size();i++)
        {
            if(nums[i]!= i+1) return i+1;
        }
        
        return nums.size() + 1;
    }
};
