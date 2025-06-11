/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        if(head==nullptr)   return false;
        while(true){
            if(fast->next==nullptr or slow->next==nullptr)  return false;
            if(fast->next->next==nullptr)  return false;
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)  return true;
        }

        return false;
    }
};