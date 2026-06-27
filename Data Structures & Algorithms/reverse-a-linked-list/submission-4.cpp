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
      ListNode* prev_node = nullptr;
      ListNode* current_node = head;

      while(current_node != nullptr){
         ListNode* next_node = current_node->next;
         current_node->next = prev_node;
         prev_node = current_node;
         current_node = next_node;
      }
      return prev_node;
   }
};
