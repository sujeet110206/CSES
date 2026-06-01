#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int xr1 = 0;
  for (auto &it : a) xr1 ^= it;
  int xr2 = 0;
  for (int i = 1; i <= n; i++) xr2 ^= i;
  cout << (xr1 ^ xr2) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
