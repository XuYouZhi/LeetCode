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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA=0, lengthB=0;
        
        ListNode *p=headA;
        while(p){
            p=p->next;
            ++lengthA;
        }
        p=headB;
        while(p){
            p=p->next;
            ++lengthB;
        }
        
        ListNode *pA=headA, *pB=headB;
        if(lengthA==0||lengthB==0) return nullptr;
        if(lengthA>=lengthB){
            int dif=lengthA-lengthB;
            while(dif>0){
                pA=pA->next;
                dif--;
            }
            
            while(pA!=nullptr&&pB!=nullptr){
                if(pA==pB) return pA;
                else{
                    pA=pA->next;
                    pB=pB->next;
                }
            }
        }
        else{
            int dif=lengthB-lengthA;
            while(dif>0){
                pB=pB->next;
                dif--;
            }
            
            while(pA!=nullptr&&pB!=nullptr){
                if(pA==pB) return pB;
                else{
                    pA=pA->next;
                    pB=pB->next;
                }
            }
        }
        
        
        return nullptr;
    }
};