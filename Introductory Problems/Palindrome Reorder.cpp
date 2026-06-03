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
	vector<int> freq(26, 0);
	for (char ch : s) freq[ch-'A']++;
	int cnt = 0;
	for (int i = 0; i < 26; i++)
		if (freq[i] % 2 == 1) cnt++;
	if (cnt > 1) {
		cout << "NO SOLUTION" << endl;
		return;
	}
	string firststr = "";
	for (int i = 0; i < 26; i++) {
		if ((freq[i] & 1) == 0)
			firststr += string(freq[i] / 2, char(i + 'A'));
	}
	string middlestr = "";
	for (int i = 0; i < 26; i++) {
		if ((freq[i] & 1) == 1) {
			middlestr += string(freq[i], char(i + 'A'));
			break;;
		}
	}
	string res = firststr + middlestr;
	reverse(firststr.begin(), firststr.end());
	cout << res + firststr;	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
