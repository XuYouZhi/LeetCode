/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// // 代码一 找到插入的位置，找到待插入的元素 容易出错 O(n)  O(1)
// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         if(head==nullptr) return nullptr;
        
//         ListNode dump(-1);
//         dump.next=head;
        
//         ListNode* insert_pos=&dump;
//         while(insert_pos->next&&insert_pos->next->val<x){
//             insert_pos=insert_pos->next;
//         }
        
//         ListNode* p=insert_pos->next;
//         ListNode* pre=insert_pos;
//         while(p){
//             if(p->val<x){
//                 cout<<pre->val<<endl;
//                 pre->next=p->next;
                
//                 ListNode* tmp=insert_pos->next;
//                 insert_pos->next=p;
//                 p->next=tmp;
//                 insert_pos=insert_pos->next;
                
//                 p=pre->next;
//             }
//             else{
//                 p=p->next;
//                 pre=pre->next;
//             }
            
//         }
        
//         return dump.next;
//     }
// };


// 代码二 两个合并 O(n) O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr) return nullptr;
        
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);
        
        ListNode* left_cur=&left_dummy;
        ListNode* right_cur=&right_dummy;
        
        for(ListNode* cur=head;cur;cur=cur->next){
            if(cur->val<x){
                left_cur->next=cur;
                left_cur=cur;
            }
            else{
                right_cur->next=cur;
                right_cur=cur;
            }
        }
        
        left_cur->next=right_dummy.next;
        right_cur->next=nullptr;
        
        return left_dummy.next;
    }
};
        