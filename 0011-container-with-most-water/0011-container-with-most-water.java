class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        
        int i = 0, j = n-1;
        int max_area = 0;
        while(i < j){
            int len = Math.min(height[i], height[j]);
            int wid = (j-i);
            int area = len*wid;
            
            max_area = Math.max(max_area, area);
            
            if(height[i] < height[j]){
                i++;
            }
            else if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return max_area;
        
    }
}