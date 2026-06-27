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
    if(head)
{      ListNode* current_Node{};
      ListNode* prev_Node = nullptr;
      ListNode* next_Node = head;

      while(next_Node->next != nullptr){
         current_Node = next_Node;
         next_Node = current_Node->next;
         current_Node->next = prev_Node;
         prev_Node = current_Node;
      }
      current_Node = next_Node;
      current_Node->next = prev_Node;
      return current_Node;
      }
      return 0;
      }
};