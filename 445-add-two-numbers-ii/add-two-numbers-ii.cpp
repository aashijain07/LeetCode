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

    ListNode* rev(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* nxt = head->next;
            head->next = prev;
            prev= head;
            head = nxt;
        }
        return prev;
    }

    ListNode* helper(ListNode* l1, ListNode* l2){
        ListNode* t1 = new ListNode(0);
        ListNode* tail = t1;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int d1 = (l1 == NULL) ? 0 : l1->val;
            int d2 = (l2 == NULL) ? 0 : l2->val;

            int sum = d1+d2+carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* t2 = new ListNode(digit);
            tail->next = t2;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        return t1->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rev(l1);
        l2 = rev(l2);
        ListNode* ans = helper(l1, l2);
        return rev(ans);
    }
};