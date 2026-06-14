#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define sp ' '
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

typedef pair<int, pii> Edges;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<Edges> edges(m);
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {u, {v, w}};
    adj[u].pb(v);
  }
  vector<ll> dist(n + 1, -inf);
  dist[1] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (auto& it : edges) {
      int node = it.first;
      int adjNode = it.second.first;
      int wt = it.second.second;
      if (dist[node] != inf && dist[node] + wt > dist[adjNode]) {
        dist[adjNode] = dist[node] + wt;
      }
    }
  }
  set<int> cycle_nodes;
  for (auto& it : edges) {
    int node = it.first;
    int adjNode = it.second.first;
    int wt = it.second.second;
    if (dist[node] != inf && dist[node] + wt > dist[adjNode]) {
      cycle_nodes.insert(adjNode);
    }
  }
  vector<bool> vis(n + 1, false);
  queue<int> q;
  q.push(1);
  queue<int> cycle_q;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    if (vis[node])
      continue;
    vis[node] = true;
    if (cycle_nodes.count(node))
      cycle_q.push(node);
    for (int adjNode : adj[node]) {
      if (!vis[adjNode]) {
        q.push(adjNode);
      }
    }
  }
  vis.assign(n + 1, false);
  bool can_reach_n = false;
  while (!cycle_q.empty()) {
    int node = cycle_q.front();
    cycle_q.pop();
    if (vis[node])
      continue;
    vis[node] = true;
    if (node == n) {
      can_reach_n = true;
      break;
    }
    for (int adjNode : adj[node]) {
      if (!vis[adjNode])
        cycle_q.push(adjNode);
    }
  }
  if (can_reach_n)
    cout << "-1" << endl;
  else
    cout << dist[n] << endl;
  return 0;
}
