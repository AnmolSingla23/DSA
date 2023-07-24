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
   ListNode* reverse(ListNode* head){

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;

        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head2 = reverse(slow->next);
        slow->next = NULL;
        
        ListNode* curr1 = head;

        while(head2){
            ListNode* tmp1 = curr1->next;
            ListNode* tmp2 = head2->next;

            curr1->next = head2;
            head2->next = tmp1;

            curr1 = tmp1;
            head2 = tmp2;
            
        }

    }
};