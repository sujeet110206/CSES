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
    for (int i = 0; i < n; i++) cin >> a[i];
    ll maxSum = INT_MIN;
    ll sum = 0;
    for (auto it : a) {
        sum  += it;
        maxSum = max(maxSum, sum);
        if (sum < 0) sum = 0;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

  return 0;
}
