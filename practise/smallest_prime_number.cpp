#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const std::vector<char> prime_trailing_digits = {'1', '3', '7', '9'};

bool CheckIfPrime(const long long N) {
    printf("%s: Checking for %lld\n",  __func__, N);
    for (long long i = 2; i <= std::sqrt<long long>(N); ++i) {
	if (N % i) {
	    continue;
	}
	return false;
    }
    return true;
}

long long GetSmalletPrimeforNumStr(const std::string& num_str) {
    std::string tmp_str = num_str;
    int cnt = 0;
    while (cnt < prime_trailing_digits.size() && !CheckIfPrime(std::stoll(tmp_str + prime_trailing_digits[cnt]))) {
	//tmp_str += prime_trailing_digits[cnt++];
	cnt++;
    }
    return cnt < prime_trailing_digits.size() ? std::stoll(tmp_str + prime_trailing_digits[cnt]) : -1;
}

long long Solve(const int N) {
    std::string N_str = std::to_string(N);
    long long sol = -1;
    long long prefix_cnt = 1;

    while ((sol = GetSmalletPrimeforNumStr(N_str)) == -1) {
	N_str = std::to_string(prefix_cnt++) + N_str;
    }

    return sol;
}

int main() {
    long long N;
    scanf("%lld", &N);
    printf("%s: solution = %lld\n", __func__, Solve(N));
}



