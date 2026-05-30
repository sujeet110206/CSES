#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

vector<string> gray_code(int n) {
	if (n == 1)
		return {"0", "1"};
	vector<string> prevGray = gray_code(n - 1);
	vector<string> res;
	int sz = prevGray.size();
	for (int i = 0; i < sz; i++)
		res.pb("0" + prevGray[i]);
	for (int i = sz - 1; i >= 0; i--)
		res.pb("1" + prevGray[i]);
	return res;
}
void solve() {
	int n;
	cin >> n;
	vector<string> res = gray_code(n);
	for (auto &it : res)
		cout << it << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
