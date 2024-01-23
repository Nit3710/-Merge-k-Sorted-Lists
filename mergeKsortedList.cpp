class Solution {
public:
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoSortedList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedList(l1, l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partionAndMerge(vector<ListNode*>& lists, int start, int end) {
        if (start > end) {
            return NULL;
        }
        if (start == end) {
            return lists[start];
        }
        int mid = start + (end - start) / 2;
        ListNode* L1 = partionAndMerge(lists, start, mid);
        ListNode* L2 = partionAndMerge(lists, mid + 1, end);
        return mergeTwoSortedList(L1, L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return NULL;
        }
        return partionAndMerge(lists, 0, k - 1);
    }
};