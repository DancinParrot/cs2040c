
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    // Floyd Tortoise and Hare (fast & slow ptr)
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) // do they point to same memory location
        return true;
    }

    return false;
  }
};
