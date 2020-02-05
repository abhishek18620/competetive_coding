#include <iostream>
#include <vector>

struct ListNode {
  int       val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

static auto get_carry    = [](const int& sum) -> int { return sum / 10; };
static auto get_retainer = [](const int& sum) -> int { return sum % 10; };

// clang-format off
int GetLLlength(ListNode* head) { // returns the length of linked list
  ListNode*curr = head;
  int len  = 0;
  while (curr->next != nullptr) {
    printf("%d  ", curr->val);
    len++;
    curr = curr->next;
  }
  printf("\n");
  return len;
}
// clang-format on

void PrintLL(ListNode* start) {
  while (start->next != nullptr) {
    printf("%d", start->val);
  }
  printf("\n");
  return;
}

void RecursiveSum(ListNode* L1, ListNode* L2, ListNode* till, ListNode* sum_tail_p, int& carry) {
  sum_tail_p->next = new ListNode(0);
  if (L1->next == till && L2->next == nullptr) {
    // reached end of both start summing
    carry           = get_carry(L1->val + L2->val);
    sum_tail_p->val = get_retainer(L1->val + L2->val);
    return;
  } else if (L2->next != nullptr) {
    RecursiveSum(L1->next, L2->next, nullptr, sum_tail_p->next, carry);
    carry           = get_carry(L1->val + L2->val + carry);
    sum_tail_p->val = get_retainer(L1->val + L2->val + carry);
    return;
  } else {
    RecursiveSum(L1->next, nullptr, nullptr, sum_tail_p->next, carry);
    carry           = get_carry(L1->val + carry);
    sum_tail_p->val = get_retainer(L1->val + carry);
  }
}

int Solve(ListNode* L1, ListNode* L2) {
  int len1 = GetLLlength(L1);
  int len2 = GetLLlength(L2);
  printf("%s: len1 = %d   len2 = %d\n", __func__, len1, len2);
  int len1_tmp = len1;
  if (len1 < len2) {
    std::swap(len1, len2);
    std::swap(L1, L2);
  }
  ListNode* L1_start = L1;
  while (len1_tmp != len2) {
    len1_tmp--;
    L1_start = L1_start->next;
  }
  /* Eg (4, 5, 6, 7) and (2, 3)
   */
  ListNode* sum_list_p = new ListNode(0);
  int       carry      = 0;
  RecursiveSum(L1_start, L2, nullptr, sum_list_p, carry); // (6, 7) + (2, 3)
  ListNode* sum_list_start_p = new ListNode(0);
  RecursiveSum(L1, L2, L1_start, sum_list_p, carry); //
  ListNode* curr_sum_p = sum_list_start_p;
  while (curr_sum_p->next != nullptr) {
    curr_sum_p = curr_sum_p->next;
  }
  curr_sum_p->next = sum_list_p;
  PrintLL(curr_sum_p);
  return 0;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int m, n;
  scanf("%d %d", &m, &n);
  printf("%s: m = %d  n = %d\n", __func__, m, n);
  ListNode* L1      = new ListNode(0);
  ListNode* l1_curr = L1;
  ListNode* L2      = new ListNode(0);
  ListNode* l2_curr = L2;
  int       tmp;
  for (int i = 0; i < m; ++i) {
    l1_curr->next = new ListNode(0);
    scanf("%d", &tmp);
    l1_curr->val = tmp;
    l1_curr      = l1_curr->next;
  }
  l1_curr = nullptr;
  // second linked list
  for (int i = 0; i < n; ++i) {
    l2_curr->next = new ListNode(0);
    scanf("%d", &tmp);
    l2_curr->val = tmp;
    l2_curr      = l2_curr->next;
  }
  l2_curr = nullptr;
  Solve(L1, L2);
  return 0;
}
