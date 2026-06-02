#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
	ll n;
	cin >> n;
	ll res = 0;
	ll base = 5;
	while (n / base != 0) {
		res += n / base;
		base *= 5;
	}
	cout << res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
