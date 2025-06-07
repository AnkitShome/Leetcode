class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        vector<int> don(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            if(s[i]=='*')   {
                don[i]=1;
                auto it=pq.top();
                pq.pop();
                don[-it.second]=1;
                continue;
            }
            pq.push({s[i]-'a',-i});
        }
     
        string res="";
        for(int i=0;i<n;i++){
            if(don[i])  continue;
            res+=s[i];
        }
        return res;
    }
};
