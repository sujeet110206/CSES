#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

void solve() {
  ll n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)  cin >> a[i];
	ll ans = 0;
	int mx = a[0];
	for (int i = 1; i < n; i++) {
		if (mx > a[i]) ans += mx - a[i];
		mx = max(mx, a[i]);
	}
	cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
