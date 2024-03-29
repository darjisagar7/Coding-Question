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
class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        if (n == 0) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (int i=0;i<n;i++) {
            ListNode* temp = lists[i];
            if (temp != NULL) 
            pq.push(temp);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            if (head == NULL) {
                head = temp;
                tail = temp;
                if (tail->next != NULL) {
                    pq.push(tail->next);
                }
            } else {
                tail->next = temp;
                tail = temp;
                if (tail->next != NULL) {
                    pq.push(tail->next);
                }
            }
        }

        return head;
    }
};
