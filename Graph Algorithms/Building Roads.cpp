#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
  vis[node] = 1;
  for (auto& adjNode : adj[node]) {
    if (!vis[adjNode])
      dfs(adjNode, vis, adj);
  }
}
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
  vector<int> vis(n + 1, 0);
  int components = 0;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      components++;
      v.pb(i);
      dfs(i, vis, adj);
    }
  }
  cout << components - 1 << endl;
  int node = v[0];
  for (int i = 1; i < (int)v.size(); i++) {
    cout << node << " " << v[i] << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
