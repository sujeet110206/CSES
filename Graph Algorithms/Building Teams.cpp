#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

vector<vector<int>> adj;
vector<int> team;
bool bfs(int src) {
  queue<int> q;
  q.push(src);
  team[src] = 1;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int adjNode : adj[node]) {
      if (team[adjNode] == -1) {
        team[adjNode] = 3 - team[node];
        q.push(adjNode);
      } else if (team[adjNode] == team[node]) {
        return false;
      }
    }
  }
  return true;
}
void solve() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  team.assign(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i = 1; i <= n; i++) {
    if (team[i] == -1) {
      if (!bfs(i)) {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << team[i] << " ";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
