#include <bits/stdc++.h>
using namespace std;

int IntegerValueForPartition(int start, int end, vector<int>& bcd) {
  int val = 0;
  for(int i = 0; i < end - start + 1; i++) {
    val += bcd[start + i] * (1 << (end - start - i));
  }
  return val;
}

void Solve(vector<int> &bcd, int& start, int& end) {
  /*
   state[i, j]:
    num1 = bcd[0..i]
    num2 = bcd[i+1, j-1]
    num3 = bcd[j, bcd.lenght() - 1]
  */
  int sz = bcd.size();
  for(int i = 0; i < sz - 2; i++) {
    for(int j = i + 1; j < sz; j++) {
      int num1 = IntegerValueForPartition(0, i, bcd);
      int num2= IntegerValueForPartition(i+1, j-1, bcd);
      int num3 = IntegerValueForPartition(j, sz-1, bcd);
      if(num1 == num2 && num2 == num3) {
        start = i;
        end = j;
        cout << "val = " << IntegerValueForPartition(0, i, bcd) << endl;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> bcd(n);
  for (int i = 0; i < n; i++) {
    cin >> bcd[i];
  }
  int start = -1;
  int end = -1;
  Solve(bcd, start, end);
  cout << start << " " << end << endl;
  return 0;
}
