#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<ll> prefixSum(n, 0);
    prefixSum[0] = v[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + v[i];

    while (q--) {
        int a, b;
        cin >> a >> b;

        ll ans = 0;
        if (a - 2 < 0)
            ans = prefixSum[b - 1];
        else
            ans = prefixSum[b - 1] - prefixSum[a - 2];
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
