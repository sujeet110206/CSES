#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back

void solve() {
  ll a, b;
	cin >> a >> b;
	if ((a + b) % 3 == 0 && max(a, b) <= 2 * min(a, b)) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
