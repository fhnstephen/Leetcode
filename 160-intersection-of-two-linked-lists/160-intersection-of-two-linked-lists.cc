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
        int len1 = 0, len2 = 0, delta = 0;
        for (auto temp = headA; temp != nullptr; temp = temp->next, len1++);
        for (auto temp = headB; temp != nullptr; temp = temp->next, len2++);
        auto temp1 = headA, temp2 = headB;
        if (len1 > len2) {
            delta = len1 - len2;
        }
        else {
            delta = len2 - len1;
            swap(temp1, temp2);
        }
        for (int i = 0; i < delta; ++i, temp1 = temp1->next);
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return nullptr;
    }
};
