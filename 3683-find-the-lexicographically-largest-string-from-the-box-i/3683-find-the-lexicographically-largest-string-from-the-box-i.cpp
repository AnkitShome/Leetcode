class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        if(numFriends==1)    return word;
        int m=n-numFriends+1;
        vector<vector<int>> freq(26);
        string res="";
        for(int i=0;i<n;i++){
            freq[word[i]-'a'].push_back(i);
        }
        int alpha=0;
        for(int i=0;i<26;i++){
            if(freq[i].size())    alpha=i;
        }

        bool x=0;
        for(int it:freq[alpha]){
            int sz=n-it;
            sz=min(sz,m);
            string s=word.substr(it,sz);
            if(!x){x=1;res=s;continue;}
            int mini=min(s.size(),res.size());
            int must=0;
            for(int j=0;j<mini;j++){
                if(s[j]<res[j] and !must)   {must=-1;break;}
                if(s[j]>res[j]){must=1;}
            }
            if(must==0 and s.size()>res.size()) res=s;
            if(must==1) res=s;
        }
        return res;
    }
};