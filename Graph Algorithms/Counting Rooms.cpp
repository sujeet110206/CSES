#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

int n, m;
bool isValid(int nrow, int ncol) {
    return nrow >= 0 && ncol >= 0 && nrow < n && ncol < m;
}
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {
  vis[row][col] = 1;
  int delrow[] = {-1, 0, 1, 0};
  int delcol[] = {0, 1, 0, -1};
  for (int i = 0; i < 4; i++) {
    int nrow = row + delrow[i];
    int ncol = col + delcol[i];
    if (isValid(nrow, ncol) && !vis[nrow][ncol] && grid[nrow][ncol] == '.')
      dfs(nrow, ncol, vis, grid);
  }
}
void solve() {
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char> (m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      grid[i][j] = s[j];
    }
  }
  vector<vector<int>> vis(n, vector<int> (m, 0));
  int countRooms = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') {
        if (!vis[i][j]) {
          dfs(i, j, vis, grid);
          countRooms++;
        }
      }
    }
  }
  cout << countRooms << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
