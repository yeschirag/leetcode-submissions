class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* new_head = reverseList(head);
        ListNode* ptr = new_head;
        int max = new_head->val;

        while (ptr && ptr->next) {
            if (ptr->next->val < max) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
                max = ptr->val;
            }
        }

        return reverseList(new_head);
    }
};
