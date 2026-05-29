#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

int cnt = 0;
bool isSafe(vector<string>& grid, int row, int col) {
  if (grid[row][col] == '*') return false;
  int i = row - 1;
  int j = col - 1;
  while (i >= 0 && j >= 0) {
    if (grid[i][j] == 'q') return false;
    i--;
    j--;
  }
  j = col - 1;
  while (j >= 0) {
    if (grid[row][j] == 'q') return false;
    j--;
  }
  i = row + 1;
  j = col - 1;
  while (i < 8 && j >= 0) {
    if (grid[i][j] == 'q') return false;
    i++;
    j--;
  }
  return true;
}
void f(int col, vector<string>& grid) {
  if (col == 8) {
    cnt++;
    return;
  }
  for (int row = 0; row < 8; row++) {
    if (isSafe(grid, row, col)) {
      grid[row][col] = 'q';
      f(col + 1, grid);
      grid[row][col] = '.';
    }
  }
}
void solve() {
  vector<string> grid(8);
  for (int i = 0; i < 8; i++) cin >> grid[i];
  int col = 0;
  f(col, grid);
  cout << cnt << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
