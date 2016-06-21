/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 归并排序 O(nlogn) O(1)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        
        ListNode *fast=head, *slow=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        fast=slow;
        slow=slow->next;
        fast->next=nullptr;
        
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(slow);
        return mergeTwoLists(l1,l2);
    }
    
    
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode dummy(-1);
        
        for(ListNode *p=&dummy;l1!=nullptr||l2!=nullptr;p=p->next){
            if(l1==nullptr){
                p->next=l2;
                l2=l2->next;
            }
            else if(l2==nullptr){
                p->next=l1;
                l1=l1->next;
            }
            else{
                if(l1->val<=l2->val){
                    p->next=l1;
                    l1=l1->next;
                }
                else{
                    p->next=l2;
                    l2=l2->next;
                }
            }
        }
        
        return dummy.next;
    }
};