#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

void solve() {
  ll n, m , k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >>  x;
  vector<ll> b(m);
  for (auto& x : b) cin >> x;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int i = 0;
  int j = 0;
  int ans = 0;
  while (i < n && j < m) {
    if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
      ans++;
      i++;
      j++;
    } else if (b[j] > a[i] + k) {
      i++;
    } else {
      j++;
    }
  }
  cout << ans << endl;

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
