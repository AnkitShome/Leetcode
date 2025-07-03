class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> freq(26);
        int left=0,right=0;
        int maxCount=0;
        int ans=0;

        while(right<n){
            freq[s[right]-'A']++;
            int window=right-left+1;

            maxCount=max(maxCount,freq[s[right]-'A']);


            if(window>maxCount+k){
                freq[s[left]-'A']--;
                left++;           
            }    
            
            ans=max(ans,right-left+1);

            right++;
        }

        return ans;
    }
};