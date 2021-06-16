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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minIdx = -1, minVal = -1;
        ListNode *minNode;
        ListNode *head = new ListNode(-1), *curr = head;
        while(minVal != INT_MAX)
        {
            minVal = INT_MAX;
            minIdx = -1;
            for(int i = 0; i < lists.size(); i++)
            {
                ListNode *node = lists[i];
                if(node && node->val < minVal)
                {
                    minVal = node->val;
                    minNode = node;
                    minIdx = i;
                }
            }
            if(minIdx != -1)
            {
                curr->next = minNode;
                curr = curr->next;
                lists[minIdx] = lists[minIdx]->next;
            }
        }
        return head->next;
    }
};