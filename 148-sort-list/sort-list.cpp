class Solution {
public:

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (left && right) {

            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            }
            else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if (left) tail->next = left;
        if (right) tail->next = right;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        if (!head || !head->next)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL;

        // Recursively sort
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Merge
        return merge(left, right);
    }
};