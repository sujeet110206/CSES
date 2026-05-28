#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

ll ans = LLONG_MAX;
ll totalSum = 0;
vector<ll> v;
void f(int ind, ll sum) {
    if (ind == v.size()) {
        ans = min(ans, abs(totalSum - 2 * sum));
        return;
    }
    f(ind + 1, sum + v[ind]);
    f(ind + 1, sum);
}
void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        totalSum += v[i];
    }
    f(0, 0);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
  return 0;
}
