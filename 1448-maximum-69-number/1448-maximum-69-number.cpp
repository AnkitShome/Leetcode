class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int n=s.size();
        int found=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='6' and found==-1){
                s[i]='9';break;
            }
        }
        int ans=stoi(s);
        return ans;
    }
};