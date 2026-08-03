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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode dummy(0, head);
       auto fast = &dummy;
       auto slow = &dummy;

       for(int i = 0; i < n; ++i){
        if(fast->next){
        fast = fast->next;
        }
       }

       while(fast->next){
        slow = slow->next;
        fast = fast->next;
       }
       auto temp = slow->next;
       slow->next = temp->next;
       delete(temp);
       return dummy.next;
    }
};