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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or head->next==NULL or k==0)   return head;
        ListNode* cur=head;
        int len=0;
        ListNode* tail=NULL;
        while(cur){
            tail=cur;
            len++;cur=cur->next;
        }
        k=k%len;
        if(k==0)    return head;
        int count=1;
        cur=head;
        while(count<len-k){
            cur=cur->next;
            count++;
        }
        ListNode* temp=cur->next;
        cur->next=NULL;
        tail->next=head;
        return temp;
    } 
};