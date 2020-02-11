#include <cassert>
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
  ListNode* curr = head;
  int len  = 0;
  while (curr != nullptr) {
    printf("%d  ", curr->val);
    len++;
    curr = curr->next;
  }
  printf("\n");
  return len;
}
// clang-format on
// Push operation on Linked list
void PushLL(ListNode* head, const int& val) {
  ListNode* curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  curr->next = new ListNode(val);
}

void PrintLL(ListNode* start) {
  ListNode* curr = start;
  while (curr->next != nullptr) {
    printf("%d  ", curr->val);
    curr = curr->next;
  }
  printf("%d  ", curr->val);
  printf("\n");
  return;
}

ListNode* GetTail(ListNode* head) {
  ListNode* tmp = head;
  while (tmp->next != nullptr) {
    tmp = tmp->next;
  }
  return tmp;
}

ListNode* RecursiveSumWithCarry(ListNode* node_p, const ListNode* till, int& carry) {
  if (node_p->next == till) {
    int retainer  = get_retainer(node_p->val + carry);
    carry         = get_carry(node_p->val + carry);
    ListNode* tmp = new ListNode(retainer);
    return tmp;
  }
  ListNode* tmp1     = RecursiveSumWithCarry(node_p->next, till, carry);
  int       retainer = get_retainer(node_p->val + carry);
  carry              = get_carry(node_p->val + carry);
  ListNode* tmp2     = new ListNode(retainer);
  tmp2->next         = tmp1;
  printf("%s carry = %d\n", __func__, carry);
  return tmp2;
}

ListNode* RecursiveSum(ListNode* L1, ListNode* L2, int& carry) {
  printf("%s: L1_val = %d  L2_val = %d\n", __func__, L1->val, L2->val);
  if (L1->next == nullptr && L2->next == nullptr) {
    // reached end of both start summing
    printf("hit the end\n");
    int retainer = get_retainer(L1->val + L2->val);
    carry        = get_carry(L1->val + L2->val);
    printf("%s: %d %d\n", __func__, carry, retainer);
    ListNode* tmp = new ListNode(retainer);
    return tmp;
  }
  ListNode* tmp1 = RecursiveSum(L1->next, L2->next, carry);
  printf("%s: %d\n", __func__, tmp1->val);
  assert(tmp1 != nullptr);
  int retainer   = get_retainer(L1->val + L2->val + carry);
  carry          = get_carry(L1->val + L2->val + carry);
  ListNode* tmp2 = new ListNode(retainer);
  tmp2->next     = tmp1;
  return tmp2;
}

int Solve(ListNode* L1, ListNode* L2) {
  int len1 = GetLLlength(L1);
  int len2 = GetLLlength(L2);
  printf("%s: len1 = %d   len2 = %d\n", __func__, len1, len2);
  if (len1 < len2) { // len1 should always be greater that len2
    std::swap(len1, len2);
    std::swap(L1, L2);
  }
  int       len1_tmp = len1;
  ListNode* L1_start = L1;
  while (len1_tmp != len2) {
    len1_tmp--;
    L1_start = L1_start->next;
  }
  /* Eg (4, 5, 6, 7) and (2, 3)
   */
  int       carry = 0;
  ListNode* sum_head_p;
  ListNode* sum_head_p1 = RecursiveSum(L1_start, L2, carry); // (6, 7) + (2, 3)
  sum_head_p            = sum_head_p1;
  PrintLL(sum_head_p1);
  if (L1_start != L1) {
    ListNode* sum_head_p2      = RecursiveSumWithCarry(L1, L1_start, carry);
    ListNode* sum_head2_tail_p = GetTail(sum_head_p2);
    sum_head2_tail_p->next     = sum_head_p1;
    sum_head_p                 = sum_head_p2;
  }
  if (carry != 0) {
    // very first digit, insert it in the begining
    ListNode* save   = sum_head_p;
    sum_head_p       = new ListNode(carry);
    sum_head_p->next = save;
  }
  PrintLL(sum_head_p);
  return 0;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int m, n;
  scanf("%d %d", &m, &n);
  printf("%s: m = %d  n = %d\n", __func__, m, n);
  ListNode* L1 = new ListNode(0);
  int       tmp;
  scanf("%d", &tmp);
  L1->val = tmp;
  for (int i = 0; i < m - 1; ++i) {
    scanf("%d", &tmp);
    PushLL(L1, tmp);
  }
  // second linked list
  ListNode* L2 = new ListNode(0);
  scanf("%d", &tmp);
  L2->val = tmp;
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d", &tmp);
    PushLL(L2, tmp);
  }
  Solve(L1, L2);
  return 0;
}
