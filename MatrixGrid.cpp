/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-05-19
 *  File : MatrixGrid.cpp
 *******************************************/
#pragma comment(linker, "/ STACK: 100000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::string;
//-------------------------MACROS-------------------------------
#define trace2(x, y)                                                           \
  std::cerr << #x << ": " << x << " | " << #y << ": " << y << std::endl;
#define trace3(x, y, z)                                                        \
  std::cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": "   \
       << z << std::endl;
#define trace4(a, b, c, d)                                                     \
  std::cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << std::endl;
#define trace5(a, b, c, d, e)                                                  \
  std::cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
       << c << " | " << #d << ": " << d << " | " << #e << ": " << e << std::endl;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;

int M, N;
struct Block {
  int x;
  int y;
  Block(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

inline bool isdelim(Block &b) {
  if(b.x == -1 and b.y == -1) {
    return true;
  }
  return false;
}

inline bool isvalid(int &x, int &y) {
 if(x < 0 or x >= M or y < 0 or y >= N) {
   return false;
 }
 return true;
}

int SolveRotOranges(vector<vector<int> > &grid) {
  M = grid.size();
  N = grid[0].size();
  int xspan[4] = {0, 1, 0, -1};
  int yspan[4] = {1, 0, -1, 0};
  int minTime = 0;
  Block rot(-1, -1);
  Block temp(-1, -1);
  std::queue <Block> q; // to store all the rotted orages
  // add a delimiter which separates oranges from time frames
  q.push(rot);
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; j++) {
      if(grid[i][j] == 2) {
        rot = Block(i, j);
        q.push(rot);
      }
    }
  }

  while(!q.empty()) {
    int xadj = -1;
    int yadj = -1;
    bool already_rotten = false; // if already rotten a neighbour
    while(!isdelim(q.front())) {
      rot = q.front();
      q.pop();
      for(int offset = 0; offset < 4; offset++) {
        xadj = rot.x + xspan[offset];
        yadj = rot.y + yspan[offset];
        // if the block is valid and contains a rotten ornage
        if(isvalid(xadj, yadj) and grid[xadj][yadj] == 1) {
          grid[xadj][yadj] = 2;
          if(!already_rotten) {
            minTime++;
            already_rotten = true;
          }
          temp = Block(xadj, yadj);
          q.push(temp);
        }
      }
    }
    q.pop();

    // push the delimeter/start for the next frame
    if(!q.empty()) {
      rot = Block(-1, -1);
      q.push(rot);
    }
  }
  // check if all oranges gor rotten or not
  bool not_all_rotten = false;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; j++) {
      if(grid[i][j] == 1) {
        not_all_rotten = true;
        break;
      }
    }
     if(not_all_rotten) {
        break;
      }
  }
  return (not_all_rotten) ? -1 : minTime;
}

int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  // Logic goes here
 vector<vector<int> > grid = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
 std::cout << SolveRotOranges(grid) << std::endl;
#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
#endif
  return 0;
}
