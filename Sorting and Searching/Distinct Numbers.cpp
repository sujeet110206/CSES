#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<ll> st;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    cout << st.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
  return 0;
}
