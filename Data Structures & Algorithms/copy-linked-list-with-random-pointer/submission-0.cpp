/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        //Phase 1 kopieren
        auto current = head;
        while(current){
            auto copy = new Node(current->val);

            copy->next = current->next;
            current->next = copy;

            current = copy->next;
        }

        //Phase 2 Random hinzufügen
        current = head;
        while (current) {
          auto copy = current->next;
          if (current->random) {
            copy->random = current->random->next;
          }
          current = copy->next;
        }

        //Phase 3 LInked Lists trennen 
        // A zeigt auf A'->next und A'->next zeigt auf A'->next->next?
        Node* copyHead = head->next;
        current = head;
        while(current){
            auto copy = current->next;
            current->next = copy->next;
            if (copy->next) {
              copy->next = copy->next->next;
            }
            current = current->next;
        }
        return copyHead;

    }
};