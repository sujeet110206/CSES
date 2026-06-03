#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

void solve() {
	int n;
	cin >> n;
	if (n == 1)	{
		cout << "1";
		return;
	}
	if (n == 2 || n == 3)	{
		cout << "NO SOLUTION";
		return;
	}
	for (int i = 2; i <= n; i += 2)
		cout << i << " ";
	for (int i = 1; i <= n; i += 2)
		cout << i << " ";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
