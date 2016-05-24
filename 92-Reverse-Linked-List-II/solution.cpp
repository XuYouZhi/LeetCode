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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n<m) return head;
        
        ListNode dummy(-1);
        dummy.next=head;
        
        ListNode* pre=&dummy;
        
        for(int i=1;i<m&&head!=NULL;++i,pre=pre->next,head=head->next){};
        if(head==NULL) return dummy.next;
        
        ListNode* tmp=head;
        pre->next=reverseList(head,n-m);
        tmp->next=head;
        
        return dummy.next;
    }
    
    ListNode* reverseList(ListNode* &head, int len) {
        ListNode* pre=NULL;
        int len_count=0;
        
        while(head!=NULL&&len_count<=len){
            ListNode* next=head->next;
            head->next=pre;
            
            pre=head;
            head=next;
            
            ++len_count;
        }
        
        return pre;
    }
};