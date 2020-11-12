// https://leetcode.com/problems/validate-binary-search-tree/
#include <iostream>
#include <queue>
#include <string>
#include <vector>

constexpr auto INF     = 1e10 + 9;
constexpr auto NEG_INF = -1 * INF;

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

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

//
bool ValidateBST(TreeNode* root, const long long min_val,
                 const long long max_val) {
    if (root == nullptr) {
        return true;
    }
    printf("%s: val = %d min_val = %lld max_val = %lld\n", __func__, root->val,
           min_val, max_val);
    if (max_val < min_val) {
        return false;
    }
    if (root->val < min_val || root->val > max_val) {
        return false;
    }

    return ValidateBST(root->left, min_val, root->val - 1LL) &&
           ValidateBST(root->right, root->val + 1LL, max_val);
}

bool Solve(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    return ValidateBST(root->left, NEG_INF, root->val - 1LL) &&
           ValidateBST(root->right, root->val + 1LL, INF);
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
        // printf("idx = %d  curr_val = %c\n", idx - 1, data[idx - 1]);
        if (idx <= data.length()) {
            curr_node->val = std::stoi(tmp);
            int left_idx   = 2 * (idx - 1) + 1;
            int right_idx  = 2 * (idx - 1) + 2;
            if (left_idx < data.length() && data[left_idx] != '*') {
                // printf("data[%d] = %c\n", left_idx, data[left_idx]);
                curr_node->left = new TreeNode(data[left_idx] - '0');
            }
            if (right_idx < data.length() && data[right_idx] != '*') {
                // printf("data[%d] = %c\n", right_idx, data[right_idx]);
                curr_node->right = new TreeNode(data[right_idx] - '0');
            }
            que.push(curr_node->left);
            que.push(curr_node->right);
        }
    }

    return root;
}

TreeNode* DeSerialize(const std::string& data) { return DeTraverse(data); }

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::string tree_str;
    std::getline(std::cin, tree_str);
    auto root_node = DeSerialize(tree_str);
    for (int i = 0; i < 2; ++i) {
        printf("level %d : ", i);
        PrintLevelTree(root_node, i + 1);
        printf("\n");
    }

    printf("%s: Solution : %s\n", __func__,
           Solve(root_node) ? "True" : "False");
    return 0;
}
