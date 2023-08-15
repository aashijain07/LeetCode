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
    ListNode* partition(ListNode* head, int x) {

        ListNode *node = head;
        ListNode *resultL = nullptr;
        ListNode *resultR = nullptr;
        ListNode *headL = nullptr;
        ListNode *headR = nullptr;

        while(node) {
            if(node->val < x) {
                if(resultL == 0) {
                    resultL = new ListNode(node->val);
                    headL = resultL;
                }
                else {
                    resultL->next = new ListNode(node->val);
                    resultL = resultL->next;
                }
            }
            else if(resultR == 0) {
                resultR = new ListNode(node->val);
                headR = resultR;
            }
            else {
                resultR->next = new ListNode(node->val);
                resultR = resultR->next;
            }
            
            node = node->next;
        }
        if(resultL)
            resultL->next = headR;
        else
            headL = headR;

        return headL;
    }
};