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
        int len1 = 0;
        int len2 = 0;
        ListNode* prev1 = headA;
        ListNode* prev2 = headB;
        while(prev1 || prev2){
            if(prev1){
                prev1 = prev1->next;
                len1++;
            }
            if(prev2){
                prev2 = prev2->next;
                len2++;
            }
        }
        
        prev1 = headA;
        prev2 = headB;
        
        if(len1 < len2){
            for(int i = 0; i < len2 - len1; i++) prev2 = prev2->next;

        } else {
            for(int i = 0; i < len1 - len2; i++) prev1 = prev1->next;
        }

        while(prev1 && prev2){
            if(prev1 == prev2) return prev1;
            prev1 = prev1->next;
            prev2 = prev2->next;
        }

        return NULL;
    }
};
