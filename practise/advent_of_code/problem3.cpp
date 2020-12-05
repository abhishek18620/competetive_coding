// https://adventofcode.com/2020/day/1
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

struct Constraint {
    int         min_constr;
    int         max_constr;
    char        constr;
    std::string pwd;

    void PrintConstraint() {
        printf("%d %d %c %s\n", this->min_constr, this->max_constr,
               this->constr, this->pwd.c_str());
    }

    bool CheckValidity() {
        int freq = std::count(this->pwd.begin(), this->pwd.end(), this->constr);
        // printf("freq = %d\n", freq);
        return (freq >= this->min_constr && freq <= this->max_constr);
    }
};

auto break_str = [](const std::string& str) {
    Constraint ret;
    auto       pos_for_dash  = str.find('-');
    auto       pos_for_colon = str.find(':');
    auto       constr        = str[pos_for_colon - 1];
    // min_constr
    const int min_constr = std::stoi(str.substr(0, pos_for_dash));
    // max_constr
    const int max_constr = std::stoi(
        str.substr(pos_for_dash + 1, pos_for_colon - pos_for_dash - 2));

    auto pwd = str.substr(pos_for_colon + 1, str.length() - pos_for_colon - 1);

    return ret = {min_constr, max_constr, constr, pwd};
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
        if (constr.CheckValidity()) {
            sol++;
        }
    }
    printf("%s: solution = %d\n", __func__, sol);

    return 0;
}
