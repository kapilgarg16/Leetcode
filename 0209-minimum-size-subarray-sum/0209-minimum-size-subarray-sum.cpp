class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        int mini = INT_MAX, sum = 0;
        bool f = false;
        
        while(j < n)
        {
            sum = sum + nums[j];
            while(sum >= target && i <= j){
                sum = sum - nums[i];
                mini = min(mini, j - i + 1);
                f = true;
                i++;
            }
            j++;
            
        }
        
        if(f == 0)
        return 0;
        return mini;
            
    }
};