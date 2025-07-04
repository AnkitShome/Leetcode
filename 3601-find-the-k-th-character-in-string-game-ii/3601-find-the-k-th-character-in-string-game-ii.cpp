class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n=operations.size();
        int point=0;
        
        int i=0;
        while((1LL<<i)<k){
            i++;
        }
        point=i;

        vector<long long> path;
        path.push_back(k);
        point--;
        while(point>=0){
            long long step=(1LL<<(point));
            if(k>step){
                k-=step;
            }
            path.push_back(k);
            point--;
        }

        reverse(path.begin(),path.end());

        char ans='a';

        for(int i=1;i<path.size();i++){
            int d=i-1;
            long long step=(1LL<<d);
            if(path[i]>step){
                if(operations[d]==1){
                    ans='a'+((ans-'a'+1)%26);
                }
            }
        }
      
        return ans;
    }
};