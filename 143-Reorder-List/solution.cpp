/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// // 代码一 Time Limit Exceeded O(n^2) O(1)
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         ListNode* p=head;

//         while(p){
//             ListNode* last=getLastNode(p);
//             if(last==p) break;
//             ListNode* tmp=p->next;
//             p->next=last;
//             p->next->next=tmp;
//             p=p->next->next;
//         }
//     }
    
// private:
//     ListNode* getLastNode(ListNode* &head){
//         if(head==nullptr) return nullptr;
        
//         ListNode dummy(-1);
//         dummy.next=head;
//         ListNode* pre=&dummy;
//         ListNode* cur=head;
        
//         while(cur->next){
//             pre=pre->next;
//             cur=cur->next;
//         }
        
//         pre->next=nullptr;

//         return cur;
//     }
// };



// 代码二 O(n) (1) 找到中间结点，断开，后半截reserve，再合并两个单链表
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return;
        
        ListNode *slow=head, *fast=head, *prev=nullptr;
        while(fast&&fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        
        slow=reverse(slow);
        
        ListNode *cur=head;
        while(cur->next){
            ListNode *tmp=cur->next;
            cur->next=slow;
            slow=slow->next;
            cur->next->next=tmp;
            cur=tmp;
        }
        // 1 2    3 4 5
        cur->next=slow;
    }
    
    
private:
    ListNode* reverse(ListNode *head){
        if(head==nullptr||head->next==nullptr)  return head;
        
        ListNode *prev=head;
        for(ListNode *cur=head->next, *next=cur->next;cur;){
            cur->next=prev;
            prev=cur;
            cur=next;
            next=next?next->next:nullptr;
        }
        
        head->next=nullptr;
        return prev;
    }
};