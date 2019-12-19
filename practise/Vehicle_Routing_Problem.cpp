/******************************************
 *  Author : abhishek18620
 *  Created On : 2019-07-21
 *  File : Vehicle_Routing_Problem.cpp
 *******************************************/
/*
The VRP concerns the service of a delivery company. How things are delivered from one or more depots which has a given set of home vehicles and operated
by a set of drivers who can move on a given road network to a set of customers. It asks for a determination of a set of routes, S, (one route for each vehicle
that must start and finish at its own depot) such that all customers' requirements and operational constraints are satisfied and the global transportation cost
is minimized. This cost may be monetary, distance or otherwise.
 */

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

struct Coordinates {
  int x;
  int y;

  Coordinates(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

inline float CalculateManhattanDistance(Coordinates start, Coordinates des) {
  return sqrt((des.y - start.y) * (des.y - start.y) + (des.x - start.x) * (des.x - start.x));
}

void GetGraph() {
  int vertices; //number of customers
  std::cin >> vertices;;
  std::vector<Coordinates> Customers(vertices, Coordinates(-1, -1));
  std::vector<std::vector<float> > graph(vertices);
  for (int i = 0; i < vertices; ++i) {
    for (int j = 0; j < vertices; j++) {
      if(i==j) continue;
      graph[i][j] = CalculateManhattanDistance(Customers[i], Customers[j]);
    }
  }
}


int main() {
#ifdef LOCAL_DEFINE
  clock_t tStart = clock();
  freopen("INP.txt", "rt", stdin);
  // freopen("output.txt","w",stdout);
#endif

  // Logic goes here

#ifdef LOCAL_DEFINE
  std::cerr << "Time elapsed: " << 1.0 * (clock() - tStart) / CLOCKS_PER_SEC
       << " s.\n";
#endif
  return 0;
}
