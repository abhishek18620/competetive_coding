// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

struct Constraint {
    int         idx1;
    int         idx2;
    char        constr;
    std::string pwd;

    void PrintConstraint() {
        printf("%d %d %c %s\n", this->idx1, this->idx2, this->constr,
               this->pwd.c_str());
    }

    bool CheckValidity() {
        // printf("%c %c\n", this->pwd[idx1 - 1], this->pwd[idx2 - 1]);
        bool ret = !(this->pwd[idx1 - 1] == this->constr &&
                     this->pwd[idx2 - 1] == this->constr);
        return ret && (this->pwd[idx1 - 1] == this->constr ||
                       this->pwd[idx2 - 1] == this->constr);
    }
};

auto break_str = [](const std::string& str) {
    Constraint ret;
    auto       pos_for_dash  = str.find('-');
    auto       pos_for_colon = str.find(':');
    auto       constr        = str[pos_for_colon - 1];
    // idx1
    const int idx1 = std::stoi(str.substr(0, pos_for_dash));
    // idx2
    const int idx2 = std::stoi(
        str.substr(pos_for_dash + 1, pos_for_colon - pos_for_dash - 2));

    auto pwd = str.substr(pos_for_colon + 2, str.length() - pos_for_colon - 1);

    return ret = {idx1, idx2, constr, pwd};
};

int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
#endif
    std::string str;
    // (break_str(str)).PrintConstraint();

    std::vector<std::string> pwd_list(1000);
    Constraint               constr;
    int                      sol = 0;
    for (auto& str : pwd_list) {
        std::getline(std::cin, str);
        // printf("%s ", str.c_str());
        constr = break_str(str);
        // constr.PrintConstraint();
        if (constr.CheckValidity()) {
            sol++;
        }
    }
    printf("%s: solution = %d\n", __func__, sol);

    return 0;
}
