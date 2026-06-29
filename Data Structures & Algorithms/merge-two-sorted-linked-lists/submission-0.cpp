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

class Solution{
    public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode dummy;
        ListNode* tail = &dummy; // alleine wäre ich darauf nie gekommen, ich wollte bereits ein list1->val <0 list2->val machen um den head zu haben. Es gibt aber so Probleme bei Edge Cases.
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        } 
        if(list1 != nullptr){
            tail->next = list1;
        }
        if(list2 != nullptr){
            tail->next = list2;
        }
        ListNode* head = &dummy;
        return head->next;
    }
};