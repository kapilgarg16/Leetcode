class Solution {
    public int removeDuplicates(int[] nums) {
        
        Integer n = nums.length, i = 0, j = 0, f = 0;
        
        if(n <= 1){
            return n;
        }
    
        while(i < n){
            if(i + 1 < n && nums[i] == nums[i+1] && f == 0){
                nums[j] = nums[i];
                j++;
                f = 1;
            }
            else if(i + 1 < n && nums[i] != nums[i+1]){
                f = 0;
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        // if(nums[n-1] != nums[n-2]){
            nums[j] = nums[n-1];
            j++;
        // }
        return j;
    }
}