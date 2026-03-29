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
    ListNode* insertionSortList(ListNode* head)
    {
        ListNode* sorted = NULL;  // new sorted list

        while (head != NULL) {
            ListNode* temp = head;
            head = head->next;

            // insert temp into sorted list
            if (sorted == NULL || temp->val < sorted->val) {
                temp->next = sorted;
                sorted = temp;
            }
            else 
            {
                ListNode* curr = sorted;

                while (curr->next != NULL && curr->next->val < temp->val) {
                    curr = curr->next;
                }

                temp->next = curr->next;
                curr->next = temp;
            }
        }
        return sorted;
    }
};