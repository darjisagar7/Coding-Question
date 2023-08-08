/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* org = head;
        ListNode* delay_n = head;
        
        int count = 0;
        while (org->next != nullptr) {
            
            if (count >= n) {
                // cout<<head->next->val<<endl;
                delay_n = delay_n->next;
            }
            
            count++;
            org = org->next;
        }
        count++;
        if (delay_n == head && count == n) {
            head = delay_n->next;
        } else {
            delay_n->next = delay_n->next->next;
        }
        
        return head;
    }
};
