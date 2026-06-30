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
    bool hasCycle(ListNode* head) {
        if(!head){
            return false;
        }
        auto list1 = head;
        auto list2 = head;

        while(list2->next != nullptr && list2->next->next != nullptr){
            list1 = list1->next;
            list2 = list2->next->next;
            if(list1 == list2){
                return true;
            }
        }
        return false; 
    }
};
