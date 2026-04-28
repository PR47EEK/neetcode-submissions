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
        if(head == NULL) return head;
        ListNode* tempNode = head;
        int l = 0;
        while(tempNode != NULL) {
            tempNode = tempNode->next;
            l++;
        }
        l = l - n;
        if(l == 0) {
            tempNode = head->next;
            delete head;
            return tempNode;
        }
        tempNode = head;
        ListNode* prev = NULL;
        while(l--) {
            prev = tempNode;
            tempNode = tempNode->next;
        }
        if(tempNode) prev->next = tempNode->next;
        else prev->next = NULL;
        return head;
    }
};
