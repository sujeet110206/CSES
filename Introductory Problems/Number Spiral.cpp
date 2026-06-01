#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

void solve() {
	ll x, y;
	cin >> x >> y;
	ll ans = 0;
	if (x <= y) {
		if (y % 2)
			ans = y * y - x + 1;
		else
			ans = (y - 1) * (y - 1) + x;
	} else {
		if (x % 2)
			ans = (x - 1) * (x - 1) + y;
		else
			ans = x * x - y + 1;
	}
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
