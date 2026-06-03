#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	int maxLen = 0;
	for (int i = 0; i < n; i++)	{
		int j = i;
		int len = 0;
		while (j < n && s[i] == s[j]) {
			len++;
			j++;
		}
		maxLen = max(maxLen, len);
		i = j - 1;
	}
	cout << maxLen;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
