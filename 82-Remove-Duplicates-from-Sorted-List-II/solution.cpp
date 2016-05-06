/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
        
        ListNode dump(-1);
        dump.next=head;
        ListNode *pre=&dump, *cur=head;
        
        while(cur!=nullptr){
            bool duplicated=false;
            
            while(cur->next!=nullptr&&cur->val==cur->next->val){
                duplicated=true;
                ListNode *tmp=cur;
                cur=cur->next;
                delete tmp;
            }
            
            if(duplicated){
                ListNode *tmp=cur;
                cur=cur->next;
                delete tmp;
                continue;
            }
            
            pre->next=cur;
            pre=pre->next;
            cur=cur->next;
        }
        
        pre->next=cur;
        return dump.next;
    }
};