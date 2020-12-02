#include <cassert>
#include <iostream>
#include <string>
#include <vector>

constexpr auto INF = 1e9+9;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static void PrintLL(ListNode* node) {
    ListNode* curr = node;
    while (curr != nullptr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

ListNode* Solve(std::vector<ListNode*>& ll_list) {
    auto find_min = [] (std::vector<ListNode*>& list) {
        int min_idx = -1;
        int min_val = INF;
        for (int i = 0; i < list.size(); ++i) {
            if (list[i] == nullptr) {
                continue;
            }

            if (list[i]->val < min_val) {
                min_idx = i;
                min_val = list[i]->val;
            }
        }
        return min_idx;
    };

    // auto increment_LL = [] (ListNode& node) {
    //     node = *(node.next);
    // };

    ListNode* ret_head;
    ListNode* prev_node = nullptr;
    int curr_min_idx;
    std::vector<ListNode*> curr_node_list = ll_list;

    curr_min_idx = find_min(curr_node_list);
    assert (curr_min_idx != -1);
    ret_head = new ListNode(curr_node_list[curr_min_idx]->val);
    prev_node = ret_head;
    // increment_LL(*curr_node_list[curr_min_idx]);
    printf("curr_min_idx = %d\n", curr_min_idx);
    curr_node_list[curr_min_idx] = curr_node_list[curr_min_idx]->next;
    printf("after incrementing %d\n", curr_node_list[curr_min_idx]->val);
    
    while (curr_min_idx != -1) {
        curr_min_idx = find_min(curr_node_list);
        if (curr_min_idx == -1) {
            break;
        }
        printf("curr_min_idx = %d\n", curr_min_idx);
        auto curr_node = new ListNode(ll_list[curr_min_idx]->val);
        prev_node->next = curr_node;
        prev_node = curr_node;
        printf("curr_val = %d\n", curr_node->val);
        // increment_LL(*curr_node_list[curr_min_idx]);
        curr_node_list[curr_min_idx] = curr_node_list[curr_min_idx]->next;
    }

    return ret_head;
}

int main() {
    int K, N, val;
    scanf("%d", &K);
    std::vector<ListNode*> ll_list(K);
    for (auto& node : ll_list) {
        scanf("%d", &N);
        scanf("%d", &val);
        // Insert first node
        node = new ListNode(val);
        ListNode* prev_node = node;
        // Insert rest of LL
        for (int i = 0; i < N - 1; ++i) {
            scanf("%d", &val);
            auto new_node = new ListNode(val);
            prev_node->next = new_node;
            prev_node = node;
        }
        PrintLL(node);
    }
    auto sol_node = Solve(ll_list);
    PrintLL(sol_node);
    
    return 0;
}
