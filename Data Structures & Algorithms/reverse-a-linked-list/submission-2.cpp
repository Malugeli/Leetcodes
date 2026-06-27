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

struct Solution{
   ListNode* reverseList(ListNode* head){
    if(!head || !head->next){ // das ist wenn head nichts oder 1 ist.
        return head;
    }

      ListNode* prev_Node = nullptr;
      ListNode* next_Node = head;

      while(next_Node->next != nullptr){
         ListNode* current_Node = next_Node;
         next_Node = current_Node->next;
         current_Node->next = prev_Node;
         prev_Node = current_Node;
      }
      next_Node->next = prev_Node;
      return next_Node;
      }
};