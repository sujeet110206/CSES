#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  vector<int> parent(n + 1);
  vector<int> vis(n + 1, 0);
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  parent[1] = 1;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto& adjNode : adj[node]) {
      if (!vis[adjNode]) {
        vis[adjNode] = 1;
        parent[adjNode] = node;
        q.push(adjNode);
      }
    }
  }
  if (!vis[n]) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  vector<int> path;
  int node = n;
  while (node != parent[node]) {
    path.pb(node);
    node = parent[node];
  }
  path.pb(1);
  reverse(path.begin(), path.end());
  cout << path.size() << endl;
  for (auto& node : path) {
    cout << node << " ";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
