class Solution {
public:
    const int mod = 1e9 + 7;
    vector<long long> tree;
    vector<int> arr;
    int m;

    void build(int node,int start,int end){
        if(start==end){
            tree[node]=arr[start]%mod;
            return;
        }
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=(tree[2*node]%mod*tree[2*node+1]%mod)%mod;
    }

    long long query(int node,int l,int r,int start,int end){
        if(l>end or r<start)    return 1;

        if(start>=l and end<=r) return tree[node];

        int mid=(start+end)/2;
        long long left=query(2*node,l,r,start,mid);
        long long right=query(2*node+1,l,r,mid+1,end);
        return (left%mod*right%mod)%mod;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) {
                arr.push_back(1 << i);
            }
        }
        sort(arr.begin(),arr.end());
        m=arr.size();
        tree.assign(4*m,1);

        build(1,0,m-1);

        vector<int> ans;
        for(auto q:queries){
            int l=q[0],r=q[1];
            ans.push_back((int)query(1,l,r,0,m-1));
        }
        return ans;
    }
};
