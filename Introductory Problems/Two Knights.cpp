#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

void solve() {
    int n;
    cin >> n;
    for (ll k = 1; k <= n; k++) {
        ll total = (k * k * (k * k - 1)) / 2;
        ll attacking = 4 * (k - 1) * (k - 2);
        cout << total - attacking << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

  return 0;
}
