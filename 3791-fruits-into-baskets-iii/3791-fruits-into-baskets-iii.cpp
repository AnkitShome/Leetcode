class Solution {
public:
    int tree[400005];
    vector<int> baskets;

    void build(int node,int start,int end){
        if(start==end){
            tree[node]=baskets[start];
            return;
        }

        int mid=(start+end)/2;
        build(node*2,start,mid);
        build(node*2+1,mid+1,end);
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }

    int query(int node,int start,int end,int l,int r){
        if(end<l or start>r)    return INT_MIN;

        if(l<=start and end<=r){
            return tree[node];
        }

        int mid=(start+end)/2;

        int left=query(2*node,start,mid,l,r);
        int right=query(2*node+1,mid+1,end,l,r);

        return max(left,right);
    }

    void update(int node,int start,int end,int ind,int val){
        if(start==end){
            tree[node]=val;
            return;
        }
        int mid=(start+end)/2;
        if(ind<=mid){
            update(2*node,start,mid,ind,val);
        }
        else{
            update(2*node+1,mid+1,end,ind,val);
        }
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        this->baskets=baskets;
        int n=baskets.size();
        int count=0;

        build(1,0,n-1);

        for(int i=0;i<n;i++){
            int left=0,right=n-1,res=-1;

            while(left<=right){
                int mid=(left+right)/2;
                if(query(1,0,n-1,0,mid)>=fruits[i]){
                    res=mid;
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            if(res!=-1 and baskets[res]>=fruits[i]){
                update(1,0,n-1,res,INT_MIN);
            }
            else{
                count++;
            }
        }
        return count;
    }
};