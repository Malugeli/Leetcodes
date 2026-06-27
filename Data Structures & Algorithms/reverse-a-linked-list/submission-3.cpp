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
      ListNode* current_Node{};
      ListNode* prev_node = nullptr;
      ListNode* next_node = head;

      while(next_node != nullptr){
         current_Node = next_node;
         next_node = current_Node->next;
         current_Node->next = prev_node;
         prev_node = current_Node;
      }
      return current_Node;
   }
};
