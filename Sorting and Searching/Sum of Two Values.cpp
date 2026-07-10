#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    map<ll, ll> mpp;
    for (ll i = 0; i < n; i++) {
        ll rem = x - a[i];
        if (mpp.find(rem) != mpp.end()) {
            cout << i + 1 << " " << mpp[rem] + 1;
            return;
        }
        mpp[a[i]] = i;
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

  return 0;
}
