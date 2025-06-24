class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        int n=word.size();
        for(auto i:word)  freq[i-'a']++;

        int ans=1e9;

        for(int i=0;i<26;i++){
            if(!freq[i])    continue;
            int sum=0;
            bool can=1;
            for(int j=0;j<26;j++){
                if(!freq[j])    continue;
                if(freq[j]<freq[i]) {sum+=freq[j];continue;} 
                int r=abs(freq[i]-freq[j]);
                if(r>k) sum+=r-k;
            }
            if(can)
                ans=min(ans,sum);
        }

        return ans;
    }
};