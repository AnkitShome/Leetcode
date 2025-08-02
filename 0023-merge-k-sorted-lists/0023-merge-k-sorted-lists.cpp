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
    ListNode* divide(vector<ListNode*> &lists,int l,int r){
        if(l==r)    return lists[l];

        int mid=(l+r)/2;
        ListNode* l1=divide(lists,l,mid);
        ListNode* l2=divide(lists,mid+1,r);

        return merge(l1,l2);
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode *head=new ListNode();
        ListNode *cur=head;

        while(l1!=NULL and l2!=NULL){
            if(l1->val < l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        if(l1!=NULL)    cur->next=l1;
        else if(l2!=NULL)    cur->next=l2;
        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)    return nullptr;
        return divide(lists,0,lists.size()-1);
    }
};