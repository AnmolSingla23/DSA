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

    int length(ListNode* head){

        int count = 0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = length(head);
        if(len == n) return head->next;
        int count = len-n;
        ListNode* curr = head;

        for(int i=0;i<count-1;i++){
            curr = curr->next;
        }

        curr->next = curr->next->next;
        return head;
    }
};