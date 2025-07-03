class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1;
        int n=s.size();
        int i=0;
        int ans=0;
        while(i<n){
            if(s[i]=='a'){
                if(a==-1 and b==-1 and c==-1)   a=i;
                else{
                    int last=min(b,c);
                    ans+=(last+1);
                    a=i;
                }
            }
            if(s[i]=='b'){
                if(a==-1 and b==-1 and c==-1)   b=i;
                else{
                    int last=min(a,c);
                    ans+=(last+1);
                    b=i;
                }
            }
            if(s[i]=='c'){
                if(a==-1 and b==-1 and c==-1)   c=i;
                else{
                    int last=min(a,b);
                    ans+=(last+1);
                    c=i;
                }
            }
            ++i;
        }
        return ans;
    }
};