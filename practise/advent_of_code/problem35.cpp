#include <iostream>
#include <regex>
#include <stack>
#include <string>
#include <vector>

auto get_tokens = [](const std::string& str) {
    std::regex               re("((\\d+|[\\*]|[\\+]|[\\(.*]|[\\).*]))");
    std::vector<std::string> tokens;
    tokens.push_back("(");
    auto words_begin = std::sregex_iterator(str.begin(), str.end(), re);
    auto words_end   = std::sregex_iterator();
    for (auto i = words_begin; i != words_end; ++i) {
        std::string part = (*i).str();
        tokens.push_back(i->str());
        // printf("%s\n", part.c_str());
    }
    tokens.push_back(")");
    return tokens;
};

long long EvaluateExpr(std::stack<std::string>& expr) {
    // printf("op = %s sz = %d\n", expr.top().c_str(), (int)expr.top().size());
    long long op1 = std::stoi(expr.top());
    long long op2;
    expr.pop();
    bool multiply = false;
    bool addition = false;
    while (!expr.empty()) {
        auto curr = expr.top();
        expr.pop();
        // printf("op = %s\n", curr.c_str());
        if (curr == "*") {
            multiply = true;
            continue;
        } else if (curr == "+") {
            addition = true;
            continue;
        }
        op2 = std::stoi(curr);
        if (addition) {
            addition = false;
            op1      = op1 + op2;
        } else {
            multiply = false;
            op1      = op1 * op2;
        }
    }
    // printf("sol = %d\n", op1);

    return op1;
}

long long Solve(const std::string& str) {
    std::stack<std::string> st, expr;
    auto                    tokens = get_tokens(str);
    long long               sol;
    int                     idx = -1;
    while (++idx != tokens.size()) {
        auto curr = tokens[idx];
        // printf("curr = %s\n", curr.c_str());
        st.push(tokens[idx]);
        if (curr == ")") {
            st.pop();
            while (st.top() != "(") {
                expr.push(st.top());
                st.pop();
            }
            st.pop(); // pop '('
            sol = EvaluateExpr(expr);
            st.push(std::to_string(sol));
        }
    }

    return sol;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::string str;
    long long   sol = 0;
    while (std::getline(std::cin, str)) {
        sol += Solve(str);
        // printf("\n", sol);
    }
    printf("solutin = %lld\n", sol);

    return 0;
}
