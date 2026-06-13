#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define sp ' '
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pii>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].pb({v, w});
  }
  vector<vector<ll>> dist(n + 1, vector<ll> (2, inf));
  dist[1][0] = 0;
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
  pq.push({0, 1, 0});
  while (!pq.empty()) {
    auto [curDist, node, used] = pq.top();
    pq.pop();
    if (curDist > dist[node][used]) continue;
    for (auto [adjNode, wt] : adj[node]) {
      if (used == 0) {
        if (curDist + wt < dist[adjNode][0]) {
          dist[adjNode][0] = curDist + wt;
          pq.push({dist[adjNode][0], adjNode, 0});
        }
        if (curDist + wt / 2 < dist[adjNode][1]) {
          dist[adjNode][1] = curDist + wt / 2;
          pq.push({dist[adjNode][1], adjNode, 1});
        }
      } else {
        if (curDist + wt < dist[adjNode][1]) {
          dist[adjNode][1] = curDist + wt;
          pq.push({dist[adjNode][1], adjNode, 1});
        }
      }
    }
  }
  cout << dist[n][1] << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
