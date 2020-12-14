// Example program
#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

unsigned long long int CalculateBitOP(const std::string &mask,
                                      const std::string &val) {
  std::string out;
  for (int i = 0; i < mask.length(); ++i) {
    if (mask[i] == '1' || mask[i] == '0') {
      out += mask[i];
    } else {
      out += val[i];
    }
  }
  // printf("ret_val = %s\n", out.c_str());
  // printf("ret_val = %u\n", (std::bitset<36> (out)).to_ullong());
  return (std::bitset<36>(out)).to_ullong();
}

// 000000000000000000000000000001001001
// 000000000000000000000000000001001001
// 012345678911 12 13 14 15 16
// mem[24644]   =     1  1  6

void Solve(
    std::unordered_map<unsigned long long int, unsigned long long int> &mem_map,
    const std::vector<std::pair<unsigned long long int, unsigned long long int>>
        &indices,
    const std::string mask) {
  if (indices.empty()) {
    return;
  }
  for (auto [idx, val] : indices) {
    std::bitset<36> val_bs(val);
    // printf("mask: %s val = %s\n", mask.c_str(), val_bs.to_string().c_str());
    mem_map[idx] = CalculateBitOP(mask, val_bs.to_string());
  }
  return;
}

int main() {
  // auto sol = Solve("XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X",
  //                  "000000000000000000000000000001100101");
  std::string str, mask;
  std::unordered_map<unsigned long long int, unsigned long long int> mem_map;
  std::vector<std::pair<unsigned long long int, unsigned long long int>>
      indices;
  while (std::getline(std::cin, str)) {
    if (str.find("mask") != std::string::npos) {
      Solve(mem_map, indices, mask);
      mask = str.substr(7, 36);
      // printf("mask = %s\n", mask.c_str());
      indices.clear();
      continue;
    }
    auto idx = std::stoull(
        str.substr(str.find('[') + 1, str.find(']') - str.find('[') - 1));
    auto val = std::stoull(
        str.substr(str.find('=') + 2, str.length() - str.find('=') - 2));
    indices.push_back({idx, val});
    // printf("idx = %u val = %u\n", idx, val);
  }
  Solve(mem_map, indices, mask);
  unsigned long long int sol = 0;
  for (auto[idx, val] : mem_map) {
    sol += val;
    printf("sol = %llu\n", sol);
  }
  printf("sol = %llu\n", sol);
  return 0;
}

