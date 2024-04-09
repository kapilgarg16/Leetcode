class Solution {
    public boolean isPalindrome(String s) {
        int n = s.length();
        String ans = "";
        for(char ch : s.toCharArray()){
            if((ch >= 'a' && ch <= 'z') ||(ch >= '0' && ch <= '9') ){
                ans += ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ans += (char)(ch+32);
            }
        }
        int i = 0, j = ans.length()-1;
        while(i <= j){
            if(ans.charAt(i) != ans.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
}