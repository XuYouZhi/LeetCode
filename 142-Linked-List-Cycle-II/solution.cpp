/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// O(n)  O(1) 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        do{
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=NULL&&fast->next!=NULL&&fast!=slow); // 注意分号
        
        if(fast==slow){
            ListNode* slow2=head;
            
            while(slow!=slow2){
                slow=slow->next;
                slow2=slow2->next;
            }
            return slow;
        }
        else{
            return NULL;
        }
    }
};