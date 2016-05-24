/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// // 代码一 O(n) O(1)
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int m, int n) {
//         if(n<m) return head;
        
//         ListNode dummy(-1);
//         dummy.next=head;
        
//         ListNode* pre=&dummy;
        
//         for(int i=1;i<m&&head!=NULL;++i,pre=pre->next,head=head->next){};
//         if(head==NULL) return dummy.next;
        
//         ListNode* tmp=head;
//         pre->next=reverseList(head,n-m);
//         tmp->next=head;
        
//         return dummy.next;
//     }
    
//     ListNode* reverseList(ListNode* &head, int len) {
//         ListNode* pre=NULL;
//         int len_count=0;
        
//         while(head!=NULL&&len_count<=len){
//             ListNode* next=head->next;
//             head->next=pre;
            
//             pre=head;
//             head=next;
            
//             ++len_count;
//         }
        
//         return pre;
//     }
// };


// 代码二 头插法 O(n)  O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next=head;
        
        ListNode *prev=&dummy;
        for(int i=0;i<m-1;++i){
            prev=prev->next;
        }
        ListNode* const head2=prev; 
        
        prev=head2->next;
        ListNode* cur=prev->next;
        for(int i=m;i<n;++i){
            prev->next=cur->next;
            cur->next=head2->next;
            head2->next=cur; //头插法
            cur=prev->next;
        }
        
        return dummy.next;
    }
};