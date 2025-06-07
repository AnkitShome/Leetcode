class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        vector<int> don(n);
        vector<set<int>> ind(26);
        vector<int> freq;
        for(int i=0;i<n;i++){
            if(s[i]=='*')   {freq.push_back(i);continue;}
            ind[s[i]-'a'].insert(i);
        }
        for(auto i:freq){
            don[i]=1;
            for(int j=0;j<26;j++){
                auto it=ind[j].upper_bound(i);
                if(it==ind[j].begin()){continue;}
                it--;
                int idx =*it;
                don[idx]=1;
                ind[j].erase(it);
                break;
            }
        }
        string res="";
        for(int i=0;i<n;i++){
            if(don[i])  continue;
            res+=s[i];
        }
        return res;
    }
};
