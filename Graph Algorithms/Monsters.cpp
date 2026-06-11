#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

const vector<char> directions = {'U', 'R', 'D', 'L'};
const vector<int> delRow = {-1, 0, 1, 0};
const vector<int> delCol = {0, 1, 0, -1};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  vector<vector<int>> monster_time(n, vector<int> (m, inf));
  queue<pii> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'M') {
        q.push({i, j});
        monster_time[i][j] = 0;
      }
    }
  }
  auto is_valid = [&](int adjRow, int adjCol) -> bool {
    return adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m;
  };
  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
      int adjRow = row + delRow[d];
      int adjCol = col + delCol[d];
      if (is_valid(adjRow, adjCol) && grid[adjRow][adjCol] != '#' && monster_time[row][col] + 1 < monster_time[adjRow][adjCol]) {
        monster_time[adjRow][adjCol] = 1 + monster_time[row][col];
        q.push({adjRow, adjCol});
      }
    }
  }
  pii start, exit_point = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'A') {
        start = {i, j};
        break;
      }
    }
  }
  vector<vector<int>> vis(n, vector<int> (m, 0));
  vector<vector<int>> dist(n, vector<int> (m, 0));
  vector<vector<char>> parent(n, vector<char> (m));
  q.push(start);
  vis[start.first][start.second] = 1;
  bool escape = false;
  while (!q.empty() && !escape) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    if (row == 0 || row == n - 1 || col == 0 || col == m -1) {
      exit_point = {row, col};
      escape = true;
      break;
    }
    for (int d = 0; d < 4; d++) {
      int adjRow = row + delRow[d];
      int adjCol = col + delCol[d];
      if (is_valid(adjRow, adjCol) && !vis[adjRow][adjCol] && grid[adjRow][adjCol] != '#' && dist[row][col] + 1 < monster_time[adjRow][adjCol]) {
        dist[adjRow][adjCol] = 1 + dist[row][col];
        vis[adjRow][adjCol] = 1;
        parent[adjRow][adjCol] = directions[d];
        q.push({adjRow, adjCol});
      }
    }
  }
  if (!escape) {
    cout << "NO" << endl;
    return;
  }
  string path;
  pii cur = exit_point;
  while (cur != start) {
    char dir = parent[cur.first][cur.second];
    path.pb(dir);
    int ind = find(directions.begin(), directions.end(), dir) - directions.begin();
    cur.first -= delRow[ind];
    cur.second -= delCol[ind];
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
