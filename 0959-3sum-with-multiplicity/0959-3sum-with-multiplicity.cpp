class Solution {
public:
    const int mod=1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        long long count=0;
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<r){
                if(arr[l]+arr[r]+arr[i]==target){
                    if(arr[l]!=arr[r]){
                        int left=1,right=1;
                        while(l+1<r and arr[l]==arr[l+1]){
                            left++;
                            l++;
                        }
                        while(r-1>l and arr[r-1]==arr[r]){
                            right++;
                            r--;
                        }
                        count+=(left%mod*right%mod)%mod;
                        l++;
                        r--;
                    }
                    else{
                        int k=(r-l+1);
                        count+=(k*(k-1))/2;
                        count%=mod;
                        break;
                    }
                    
                }
                else if(arr[l]+arr[r]+arr[i]<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return count%mod;
    }
};