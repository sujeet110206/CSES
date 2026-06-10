#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define sp ' '
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n) {
      cout << "NO" << endl;
      continue;
    }
    if ((a == 0 || b == 0) && (a + b != 0)) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      cout << i << sp;
    }
    cout << endl;
    for (int i = a + 1; i <= a + b; i++) {
      cout << i << sp;
    }
    for (int i = 1; i <= a; i++) {
      cout << i << sp;
    }
    for (int i = a + b + 1; i <= n; i++) {
      cout << i << sp;
    }
    cout << endl;
  }
  return 0;
}
