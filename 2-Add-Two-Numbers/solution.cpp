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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x=0,y=0,carry=0,sum=0;
        ListNode* result=NULL;
        ListNode** t=&result;
        
        while(l1!=NULL||l2!=NULL){
            x=__getValueAndMoveNext(l1);
            y=__getValueAndMoveNext(l2);
            
            sum=x+y+carry;
            
            ListNode* node=new ListNode(sum%10);
            *t=node;
            t=(&node->next);
            
            carry=sum/10;
        }
        
        if(carry>0){
            ListNode* node=new ListNode(carry);
            *t=node;
        }
        
        return result;
    }


private:
    int __getValueAndMoveNext(ListNode* &l){
        int x=0;
        if(l!=NULL){
            x=l->val;
            l=l->next;            
        }
        return x;
    }
};