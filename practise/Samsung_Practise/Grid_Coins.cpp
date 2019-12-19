#include <iostream>
using namespace std;
#define trace2(x, y)                                                           \
  cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)                                                        \
  cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": "   \
       << z << endl;
#define trace4(a, b, c, d)                                                     \
  cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)                                                  \
  cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#

int n;
int grid[100][100];
int row, column;

inline int max(int &x, int &y) {
  if(x >= y) {
    return x;
  }
  return y;
}

int solve(int ss_pos, int next_row, int enemy_killed, bool bomb_used) {
  trace4(ss_pos, next_row, enemy_killed, bomb_used);
	// base condition
  if (next_row < 0) {
    return 0;
  }
  int stay = grid[next_row][ss_pos];
  int left = (ss_pos == 0) ? -1 : grid[next_row][ss_pos - 1];
  int right = (ss_pos == column - 1) ? -1 : grid[next_row][ss_pos + 1];
  // enemy encountered
  if (bomb_used and enemy_killed > 0) {
    stay = (stay == 2) ? 0 : stay;
    left = (left == 2) ? 0 : left;
    right = (right == 2) ? 0 : right;
  }
  // stay at same position
  int ans1 = 0;
  if (stay == 2) {
    if (!bomb_used) {
      ans1 = solve(ss_pos, next_row - 1, 5, true);
    } else if (enemy_killed > 0) {
      // enemy has been killed already
      ans1 = solve(ss_pos, next_row - 1, enemy_killed - 1, bomb_used);
    } else {
      ans1 = 0;
    }
  } else {
    ans1 = stay + solve(ss_pos, next_row - 1, enemy_killed - 1, bomb_used);
  }
  // move left
  int ans2 = 0;
  if (left == -1) {
    ans2 = 0;
  } else {
    if (left == 2) {
      if (!bomb_used) {
        ans2 = solve(ss_pos - 1, next_row - 1, 5, true);
      } else if (enemy_killed > 0) {
        // enemy has been killed already
        ans2 = solve(ss_pos - 1, next_row - 1, enemy_killed - 1, bomb_used);
      } else {
        ans2 = 0;
      }
    } else {
      ans2 =
          left + solve(ss_pos - 1, next_row - 1, enemy_killed - 1, bomb_used);
    }
  }
  // move right
  int ans3;
  if (right == -1) {
    ans3 = 0;
  } else {
    if (right == 2) {
      if (!bomb_used) {
        ans3 = solve(ss_pos + 1, next_row - 1, 5, true);
      } else if (enemy_killed > 0) {
        // enemy has been killed already
        ans3 = solve(ss_pos + 1, next_row - 1, enemy_killed - 1, bomb_used);
      } else {
        ans3 = 0;
      }
    } else {
      ans3 =
          right + solve(ss_pos + 1, next_row - 1, enemy_killed - 1, bomb_used);
    }
  }
  return max(ans1, max(ans2, ans3));
}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  cin >> row >> column;
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; j++) {
      cin >> grid[i][j];
    }
  }

  int ans = solve(column / 2, row - 1, -1, false);
  cout << ans << endl;
  return 0;
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
  // cin>>t;
#endif

}
