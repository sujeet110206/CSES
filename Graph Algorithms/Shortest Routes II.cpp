#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> dist(n, vector<ll> (n, inf));
  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--;
    v--;
    dist[u][v] = min(dist[u][v], w);
    dist[v][u] = min(dist[v][u], w);
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] != inf && dist[k][j] != inf) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    cout << (dist[u][v] == inf ? -1 : dist[u][v]) << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
