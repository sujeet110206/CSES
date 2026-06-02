#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

void f(int n, int src, int dest, int via) {
	if (n <= 0) return;
	f(n - 1, src, via, dest);
	cout << src << " " << dest << endl;
	f(n - 1, via, dest, src);
}
void solve() {
  int n;
	cin >> n;
	cout << (1 << n) - 1 << endl;
	f(n, 1, 3, 2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
