class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int low=0,high=n-1;
        int ind=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid][0]>target){
                high=mid-1;
            }
            else if(matrix[mid][m-1]<target){
                low=mid+1;
            }
            else{
                ind=mid;
                break;
            }
        }
        cout<<ind<<endl;
        if(ind==-1) return false;
        low=0;
        high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[ind][mid]>target){
                high=mid-1;
            }
            else if(matrix[ind][mid]<target){
                low=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};