#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

void TrimTrailingNulls(std::string& data) {
    int idx = 0;
    while ((1 << idx) < data.length()) {
        idx++;
    }
    idx--;
    int len_req = 1 << idx;
    data        = data.substr(0, len_req - 1);
}

std::string Traverse(TreeNode* root) {
    std::queue<TreeNode*> que;
    std::string           ret;
    que.push(root);
    while (!que.empty()) {
        auto middle = que.front();
        que.pop();
        if (middle == nullptr) {
            ret += '*';
            continue;
        }
        ret += std::to_string(middle->val);
        que.push(middle->left);
        que.push(middle->right);
    }
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

std::string Serialize(TreeNode* root) { return Traverse(root); }

TreeNode* DeSerialize(const std::string& data) { return DeTraverse(data); }

int main() {
    auto tree_node = DeSerialize("");
    int  height    = FindHeightOfTree(tree_node);
    printf("height = %d\n", height);
    std::string ser_str = "";
    for (int i = 0; i < height; ++i) {
        printf("level %d : ", i);
        ser_str += PrintLevelTree(tree_node, i + 1);
        printf("\n");
    }
    printf("%s: serialised_str = %s\n", __func__, ser_str.c_str());
    return 0;
}
