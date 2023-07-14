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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* curr = NULL;
        ListNode* p = NULL;
            
        if(first->val < second->val){
            curr = p = first;
            first = first->next;
            curr->next = NULL;
            }
        else{
            curr = p = second;
            second = second->next;
            curr->next = NULL;
            }
        
        while(first && second){
            if(first->val <= second->val){
                curr->next = first;
                curr = first;
                first = first->next;
                curr->next = NULL;
            }
            else{
                curr->next = second;
                curr = second;
                second = second->next;
                curr->next = NULL;
            }
        }
        
        if(first != NULL){
            curr->next = first;
        }
        if(second != NULL){
            curr->next = second;
        }
        
        return p;
        
    }
};