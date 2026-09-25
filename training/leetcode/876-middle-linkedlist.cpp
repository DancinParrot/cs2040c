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
struct ListNode {
  int val;
  ListNode *next;
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *fast = head, *slow = head;

    while (fast && fast->next) {
      // When fast reach end, slow is n/2 (second middle node as it can be 2 or
      // 3 for linked list of 6 in length. If odd then slow is (n-1)/2
      fast = fast->next->next; // is 2k of slow
      slow = slow->next;
      if (fast == nullptr)
        break;
    }
    return slow;
  }
};
