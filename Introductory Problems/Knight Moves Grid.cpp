#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  const long long inf = 1e18;
  vector<vector<long long>> dist(n, vector<long long> (n, inf));
  vector<vector<int>> vis(n, vector<int> (n, 0));
  vis[0][0] = 1;
  dist[0][0] = 0;
  queue<pair<pair<int,int>, int>> q;
  q.push({{0, 0}, 0});
  int delrow[] = {2, 2, -2, -2, 1, 1, -1, -1};
  int delcol[] = {1, -1, 1, -1, 2, -2, 2, -2};
  auto isValid = [&](int nrow, int ncol) -> bool {
    return nrow >= 0 && ncol >= 0 && nrow < n && ncol < n;
  };
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int row = p.first.first;
    int col = p.first.second;
    int dis = p.second;
    if (dis > dist[row][col]) continue;
    for (int i = 0; i < 8; i++) {
      int nrow = row + delrow[i];
      int ncol = col + delcol[i];
      if (isValid(nrow, ncol) && !vis[nrow][ncol]) {
        if (dis + 1 < dist[nrow][ncol]) {
          dist[nrow][ncol] = dis + 1;
          vis[nrow][ncol] = 1;
          q.push({{nrow, ncol}, dis + 1});
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dist[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
