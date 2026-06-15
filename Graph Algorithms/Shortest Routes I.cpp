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
  vector<vector<pair<int, ll>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].pb({v, w});
  }
  vector<ll> dist(n + 1, inf);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push({0, 1});
  dist[1] = 0;
  while (!pq.empty()) {
    ll dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (dis > dist[node]) continue;
    for (auto& it : adj[node]) {
      int adjNode = it.first;
      ll wt = it.second;
      if (wt + dist[node] < dist[adjNode]) {
        dist[adjNode] = wt + dist[node];
        pq.push({dist[adjNode], adjNode});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
