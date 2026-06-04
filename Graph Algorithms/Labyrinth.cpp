#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>

const vector<char> directions = {'U', 'R', 'D', 'L'};
const vector<int> delrow = {-1, 0, 1, 0};
const vector<int> delcol = {0, 1, 0, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++)
    cin >> grid[i];
  pii start, end;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'A') 
        start = {i, j};
      else if (grid[i][j] == 'B') 
        end = {i, j}; 
    }
  }
  vector<vector<int>> vis(n, vector<int> (m, 0));
  vector<vector<char>> prevDirection(n, vector<char> (m, '0'));
  queue<pii> q;
  q.push(start);
  vis[start.first][start.second] = 1;
  bool found = false;
  auto is_valid = [&](int nrow, int ncol) -> bool {
    return nrow >= 0 && ncol >= 0 && nrow < n && ncol < m;
  };
  while (!q.empty() && !found) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
      int nrow = row + delrow[d];
      int ncol = col + delcol[d];
      if (is_valid(nrow, ncol) && !vis[nrow][ncol] && grid[nrow][ncol] != '#') {
        vis[nrow][ncol] = 1;
        prevDirection[nrow][ncol] = directions[d];
        q.push({nrow, ncol});
        if (make_pair(nrow, ncol) == end) {
          found = true;
          break;
        }
      }
    }
  }
  if (!vis[end.first][end.second]) {
    cout << "NO" << endl;
    return;
  }
  string path;
  pii cur = end;
  while (cur != start) {
    char dir = prevDirection[cur.first][cur.second];
    path.pb(dir);
    int ind = find(directions.begin(), directions.end(), dir) - directions.begin();
    cur.first -= delrow[ind];
    cur.second -= delcol[ind];
  }
  reverse(path.begin(), path.end());
  cout << "YES\n";
  cout << path.size() << endl;
  cout << path << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
