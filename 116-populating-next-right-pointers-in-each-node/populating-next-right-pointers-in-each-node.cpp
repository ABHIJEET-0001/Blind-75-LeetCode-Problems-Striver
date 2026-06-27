class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        Node* leftmost = root;

        while (leftmost->left) {
            Node* head = leftmost;

            while (head) {
                // Connect left -> right
                head->left->next = head->right;

                // Connect right -> next left
                if (head->next) {
                    head->right->next = head->next->left;
                }

                head = head->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};