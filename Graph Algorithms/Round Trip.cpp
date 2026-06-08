#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

vector<vector<int>> adj;
vector<int> vis;
vector<int> parent;
int start = -1;
int finish;
bool dfs(int node, int par) {
  vis[node] = 1;
  for (auto& adjNode : adj[node]) {
    if (adjNode == par) continue;
    if (vis[adjNode]) {
      start = adjNode;
      finish = node;
      return true;
    } else {
      parent[adjNode] = node;
      if (dfs(adjNode, node)) return true;
    }
  }
  return false;
}
void solve() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  parent.assign(n + 1, -1);
  vis.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i] && dfs(i, -1)) break;
  }
  if (start == -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    vector<int> path;
    path.pb(start);
    int cur = finish;
    while (cur != start) {
      path.pb(cur);
      cur = parent[cur];
    }
    path.pb(start);
    cout << path.size() << endl;
    for (auto& node : path) {
      cout << node << " ";
    }
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
