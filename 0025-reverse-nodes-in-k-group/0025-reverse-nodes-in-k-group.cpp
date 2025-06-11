/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head;

        int n=0;
        vector<ListNode*> ends,starts;
        while(cur){
            n++;
            if(n%k==0){
                ends.push_back(cur);
            }
            if(n%k==1){
                starts.push_back(cur);
            }
            cur=cur->next;
        }

        int r=min(starts.size(),ends.size());

        if(!r)  return head;

        for(int i=0;i<r;i++){
            ListNode* start=starts[i];
            ListNode* end=ends[i];
            ListNode* prev=nullptr;

            while(true){
                ListNode* next=start->next;
                start->next=prev;
                prev=start;
                if(start==end)    break;
                start=next;
            }
        }

        for(int i=0;i<r;i++){
            ListNode* start=starts[i];
            ListNode* prev=nullptr;
            if(i+1<r){
                prev=ends[i+1];
            }
            else if(i+1<starts.size()){
                prev=starts[i+1];
            }
            start->next=prev;
        }

        return ends[0];
    }
};