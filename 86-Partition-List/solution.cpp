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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr) return nullptr;
        
        ListNode dump(-1);
        dump.next=head;
        
        ListNode* insert_pos=&dump;
        while(insert_pos->next&&insert_pos->next->val<x){
            insert_pos=insert_pos->next;
        }
        
        ListNode* p=insert_pos->next;
        ListNode* pre=pre=insert_pos;
        while(p){
            if(p->val<x){
                cout<<pre->val<<endl;
                pre->next=p->next;
                
                ListNode* tmp=insert_pos->next;
                insert_pos->next=p;
                p->next=tmp;
                insert_pos=insert_pos->next;
                
                p=pre->next;
            }
            else{
                p=p->next;
                pre=pre->next;
            }
            
        }
        
        return dump.next;
    }
};