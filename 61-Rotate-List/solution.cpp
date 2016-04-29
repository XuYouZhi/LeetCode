/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// // 方法一 有点繁琐，易错
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head==NULL) return NULL;
        
//         ListNode* p=head;
//         int n=0;
//         while(p!=NULL){
//             ++n;
//             p=p->next;
//         }
//         k%=n;
        
//         ListNode* rotate_head=head;
        
//         for(int i=0;i<n-k-1;++i){
//             rotate_head=rotate_head->next;
//         }
        
//         if(rotate_head->next==NULL){ // Be Careful
//             return head;
//         }
        
//         p=rotate_head;
//         rotate_head=rotate_head->next;
//         p->next=NULL;
        
//         p=rotate_head;
//         for(int i=0;i<k-1;++i){
//             p=p->next;
//         }
        
//         p->next=head;
        
//         return rotate_head;
//     }
// };



// 方法二 简单  思路：形成一个环，然后断开
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        ListNode* p=head;
        int len=1;
        while(p->next!=NULL){
            ++len;
            p=p->next;
        }
        k%=len;
        
        p->next=head; //首尾相连
        for(int i=0;i<len-k;++i){
            p=p->next;
        }
        head=p->next;
        p->next=NULL; //断开
        
        return head;
    }
};
