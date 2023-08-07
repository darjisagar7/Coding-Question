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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* temp;
        
        if (list1 == nullptr && list2 == nullptr) return head;
        
        if (list1 == nullptr) {
            head = list2;
            temp = list2;
            list2 = list2->next;
            while (list2 != nullptr) {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
                temp->next = nullptr;
            }
            
            return head;
        }
        
        if (list2 == nullptr) {
            head = list1;
            temp = list1;
            list1 = list1->next;
            while (list1 != nullptr) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
                temp->next = nullptr;
            }
            
            return head;
        }
        
        if (list1->val > list2->val) {
            head = list2;
            temp = list2;
            list2 = list2->next;
        } else {
            head = list1;
            temp = list1;
            list1 = list1->next;
        }
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                temp->next = list2;
                list2 = list2->next;
            } else {
                temp->next = list1;
                list1 = list1->next;
            }
            
            temp = temp->next;
            temp->next = nullptr;
        }
        
        if (list1 != nullptr) {
            while (list1 != nullptr) {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
                temp->next = nullptr;
            }
        }
        
        if (list2 != nullptr) {
            while (list2 != nullptr) {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
                temp->next = nullptr;
            }
        }
        
        return head;
    }
};
