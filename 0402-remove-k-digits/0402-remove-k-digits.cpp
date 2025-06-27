class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        vector<int> NSE(n,n);

        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() and num[st.top()]>=num[i])   st.pop();
            if(!st.empty()) NSE[i]=st.top();
            st.push(i);
        }
        
        for(auto i:NSE) cout<<i<<" ";cout<<endl;

        int i=0;
        string res="";
        while(i<n){
            int next=NSE[i];
            cout<<i<<" "<<next<<" "<<k<<endl;
            if((next-i)<=k) {k-=(next-i);i=next;continue;}
            res+=num[i];
            i++;  
        }
        reverse(res.begin(),res.end());
        while(!res.empty() and res.back()=='0')  res.pop_back();
        reverse(res.begin(),res.end());
        if(res.size()==0)   return "0";
        return res;

    }
};