#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  vector<string> ans(n, string(m, ' '));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        if (grid[i][j] == 'A') {
          ans[i][j] = 'B';
        } else {
          ans[i][j] = 'A';
        }
      } else {
        if (grid[i][j] == 'C') {
          ans[i][j] = 'D';
        } else {
          ans[i][j] = 'C';
        }
      }
    }
  }
  for (auto& row : ans) cout << row << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
