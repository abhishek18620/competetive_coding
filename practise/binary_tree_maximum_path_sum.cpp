// https://leetcode.com/problems/binary-tree-maximum-path-sum/
#include <iostream>
#include <queue>
#include <string>
#include <vector>

constexpr auto INT_MIN = -1 * (1e9 + 9);

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

struct SolState {
    int longest_path_in_stree;
    int longest_path_from_root;
    int longest_path_across_stress;
    SolState(int val1, int val2, int val3)
        : longest_path_in_stree(val1), longest_path_from_root(val2),
          longest_path_across_stress(val3) {}
    void PrintState() {
        printf("in_stree = %d, from_root = %d, across_strees = %d\n",
               this->longest_path_in_stree, this->longest_path_from_root,
               longest_path_across_stress);
    }
};

int FindHeightOfTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return std::max(FindHeightOfTree(root->left) + 1,
                    FindHeightOfTree(root->right) + 1);
}

std::string PrintLevelTree(TreeNode* root, int level) {
    TreeNode*   left  = nullptr;
    TreeNode*   right = nullptr;
    std::string ret;
    if (root != nullptr) {
        left  = root->left;
        right = root->right;
    }
    if (level == 1) {
        if (root == nullptr) {
            printf("* ");
            ret = "*";
        } else {
            ret = std::to_string(root->val);
            printf("%d ", root->val);
        }
        return ret;
    }

    ret += PrintLevelTree(left, level - 1);
    ret += PrintLevelTree(right, level - 1);
    return ret;
}

TreeNode* DeTraverse(const std::string& data) {
    /* sanity check */
    if (data.empty()) {
        return nullptr;
    }
    TreeNode*             root = new TreeNode(0);
    std::queue<TreeNode*> que;
    int                   idx = 0;
    que.push(root);
    printf("%s: %s\n", __func__, data.c_str());
    while (!que.empty()) {
        auto curr_node = que.front();
        que.pop();
        std::string tmp = "";
        tmp += data[idx++];
        if (tmp == "*" || curr_node == nullptr) {
            continue;
        }
        printf("idx = %d  curr_val = %c\n", idx - 1, data[idx - 1]);
        if (idx <= data.length()) {
            curr_node->val = std::stoi(tmp);
            int left_idx   = 2 * (idx - 1) + 1;
            int right_idx  = 2 * (idx - 1) + 2;
            if (left_idx < data.length() && data[left_idx] != '*') {
                printf("data[%d] = %c\n", left_idx, data[left_idx]);
                curr_node->left = new TreeNode(data[left_idx] - '0');
            }
            if (right_idx < data.length() && data[right_idx] != '*') {
                printf("data[%d] = %c\n", right_idx, data[right_idx]);
                curr_node->right = new TreeNode(data[right_idx] - '0');
            }
            que.push(curr_node->left);
            que.push(curr_node->right);
        }
    }

    return root;
}

TreeNode* DeSerialize(const std::string& data) { return DeTraverse(data); }

SolState SolveRecursive(TreeNode* root) {
    auto sanitize_value = [](const int val) {
        return val == INT_MIN ? 0 : val;
    };

    SolState ret_sol = SolState(INT_MIN, INT_MIN, INT_MIN);
    if (root == nullptr) {
        return ret_sol;
    }

    SolState sol_left  = SolState(INT_MIN, INT_MIN, INT_MIN);
    SolState sol_right = SolState(INT_MIN, INT_MIN, INT_MIN);
    sol_left           = SolveRecursive(root->left);
    sol_right          = SolveRecursive(root->right);

    ret_sol.longest_path_across_stress = std::max(
        root->val, root->val + sanitize_value(sol_left.longest_path_from_root) +
                       sanitize_value(sol_right.longest_path_from_root));

    ret_sol.longest_path_from_root = std::max(
        root->val,
        root->val + sanitize_value(std::max(sol_left.longest_path_from_root,
                                            sol_right.longest_path_from_root)));

    ret_sol.longest_path_in_stree =
        std::max(ret_sol.longest_path_across_stress,
                 std::max(ret_sol.longest_path_from_root,
                          std::max(root->val,
                                   std::max(sol_left.longest_path_in_stree,
                                            sol_right.longest_path_in_stree))));

    // printf("for node %d -> ", root->val);
    // ret_sol.PrintState();
    return ret_sol;
}

int Solve(TreeNode* root) {
    auto sol = SolveRecursive(root);
    return sol.longest_path_in_stree;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    auto root_node = DeSerialize("1234561");
    int  height    = FindHeightOfTree(root_node);
    printf("height = %d\n", height);
    std::string ser_str = "";
    for (int i = 0; i < height; ++i) {
        printf("level %d : ", i);
        ser_str += PrintLevelTree(root_node, i + 1);
        printf("\n");
    }

    printf("%s: solution = %d\n", __func__, Solve(root_node));
    return 0;
}
