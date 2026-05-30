#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

void solve() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	vector<string> ans;
	do {
		ans.pb(s);
	} while (next_permutation(s.begin(), s.end()));
	cout << ans.size() << endl;
	for (auto &it : ans)
		cout << it << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
