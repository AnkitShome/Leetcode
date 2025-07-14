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
    int getDecimalValue(ListNode* head) {
        ListNode *cur=head;
        int num=0;
        int count=1;
        int n=0;
        while(cur!=NULL){
            n++;
            cur=cur->next;
        }
        cur=head;
        while(cur!=NULL){
            int val=cur->val;
            if(val)
                num+=(1<<(n-count));
            count++;
            cur=cur->next;
        }
        return num;
    }
};