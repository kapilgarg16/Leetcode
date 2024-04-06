class Solution {
    public int removeDuplicates(int[] nums) {
        
        Integer n = nums.length, i = 0, j = 0;
        Boolean f = false;
        
        if(n <= 1){
            return n;
        }
    
        while(i < n){
            if(i + 1 < n && nums[i] == nums[i+1] && !f){
                nums[j++] = nums[i];
                f = true;
            }
            else if(i + 1 < n && nums[i] != nums[i+1]){
                f = false;
                nums[j++] = nums[i];
            }
            i++;
        }
            nums[j++] = nums[n-1];
        
        return j;
    }
}