class Solution {
public:
    bool check(string s){
        int i=0;
        int n=s.size();
        while(i<n/2){
            if(s[i]!=s[n-i-1])  return false;
            i++;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                if(check(s.substr(i+1,j-i)))  return true;
                else if(check(s.substr(i,j-i)))  return true;
                else    return false;
            }
        }
        return true;
    }
};