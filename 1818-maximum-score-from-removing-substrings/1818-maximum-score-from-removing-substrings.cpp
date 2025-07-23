class Solution {
public:
    
    int count(string s,stack<char> &st,int choice,int x,int y){
        
        char last,now;
        int n=s.size(),ans=0,i=0;
        
        while(i<n){
            now=s[i];        
            if(!st.empty()) last=st.top();
            st.push(now);
            
            if(!choice){
                if(st.size()>=2 and last=='a' and now=='b'){
                    st.pop();
                    st.pop();
                    ans+=x;
                }
                if(!st.empty()) last=st.top();
            }
            else{
                if(st.size()>=2 and last=='b' and now=='a'){
                    st.pop();
                    st.pop();
                    ans+=y;
                }
                if(!st.empty()) last=st.top();
            }
            i++;
        }
        return ans;
    }

    int maximumGain(string s, int x, int y) {

        int choice=0;
        if(x<y) choice=1;

        stack<char> st;
        int ans=count(s,st,choice,x,y);

        string re="";
        while(!st.empty()){
            re+=st.top();
            st.pop();
        }
        reverse(re.begin(),re.end());
        ans+=count(re,st,!choice,x,y);

        cout<<ans<<endl;
        return ans;
    }
};