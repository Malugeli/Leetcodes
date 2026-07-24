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
    void reorderList(ListNode* head){
        //Phase 1: Cutte die Liste in zwei
        auto slow = head;
        auto fast = head;
        while(fast->next && fast->next->next){ //diese Version gibt mir bei gerader Länge das letzte Element, fast && fast->next würde mir das erste Element der zweiten Hälfte geben
            slow = slow->next;
            fast = fast->next->next;
        }
        auto second = slow->next;
        slow->next = nullptr;           
        //Phase 2: Reverte die zweite Liste
        ListNode* prev = nullptr;
        while(second){
            auto nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
        }
        second = prev; // ist der neue head, ohne das ist second nullptr

        // Phase 3: Merge die Listen verzahnt zusammen
        auto first = head;
        while(second){
            auto t1 = first->next;
            auto t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
    }
}; 
