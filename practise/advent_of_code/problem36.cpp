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

long long EvaluateExprWithPrecedence(const std::string tokens) {
    auto precedence = [](char op) {
        if (op == '+')
            return 2;
        return 1;
    };

    auto apply_op = [](long long a, long long b, char op) -> long long {
        switch (op) {
        case '+':
            return a + b;
        case '*':
            return a * b;
        }
        return -1;
    };

    std::stack<long long> values;
    std::stack<char>      ops;
    for (int i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ')
            continue;
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        } else if (isdigit(tokens[i])) {
            long long val = 0;
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            values.push(val);
            i--;
        }

        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                long long val2 = values.top();
                values.pop();

                long long val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(apply_op(val1, val2, op));
            }

            if (!ops.empty())
                ops.pop();
        }

        else {
            while (!ops.empty() &&
                   precedence(ops.top()) >= precedence(tokens[i])) {
                long long val2 = values.top();
                values.pop();

                long long val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(apply_op(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }

    while (!ops.empty()) {
        long long val2 = values.top();
        values.pop();

        long long val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(apply_op(val1, val2, op));
    }
    // printf("expr_str = %s res = %lld\n", tokens.c_str(), values.top());

    return values.top();
}

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

long long SolveWithPrecedence(const std::string& str) {
    std::stack<std::string> st;
    auto                    tokens = get_tokens(str);
    long long               sol;
    int                     idx = -1;
    while (++idx != tokens.size()) {
        auto curr = tokens[idx];
        // printf("curr = %s\n", curr.c_str());
        st.push(tokens[idx]);
        if (curr == ")") {
            st.pop();
            std::string expr_str;
            while (st.top() != "(") {
                expr_str += st.top();
                st.pop();
            }
            st.pop(); // pop '('
            sol = EvaluateExprWithPrecedence(expr_str);
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
        sol += SolveWithPrecedence(str);
        // printf("\n", sol);
    }
    printf("solutin = %lld\n", sol);

    return 0;
}
