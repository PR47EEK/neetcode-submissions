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
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* headNode = nullptr; ListNode* tempNode = nullptr;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(headNode == nullptr)
            {
                if(list1->val <= list2->val)
                {
                    headNode = list1;
                    list1 = list1->next;
                    headNode->next = nullptr;
                }
                else
                {
                    headNode = list2;
                    list2 = list2->next;
                    headNode->next = nullptr;
                }
                tempNode = headNode;
            }
            else
            {
                if(list1->val <= list2->val)
                {
                    tempNode->next = list1;
                    tempNode = list1;
                    list1 = list1->next;
                    tempNode->next = nullptr;
                }
                else
                {
                    tempNode->next = list2;
                    tempNode = list2;
                    list2 = list2->next;
                    tempNode->next = nullptr;
                }
            }
        }
        while(list1 != nullptr)
        {
            tempNode->next = list1;
            tempNode = list1;
            list1 = list1->next;
            tempNode->next = nullptr;
        }
        while(list2 != nullptr)
        {
            tempNode->next = list2;
            tempNode = list2;
            list2 = list2->next;
            tempNode->next = nullptr;
        }
        return headNode;
    }
};
