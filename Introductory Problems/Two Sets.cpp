#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

void solve() {
    ll n;
    cin >> n;
    ll sum = (n * (n + 1) ) / 2;
    if (sum % 2 == 1) {
        cout << "NO";
        return;
    } else {
        cout << "YES\n";
        bool flag = true;
        ll half = n / 2;
        ll temp = n;
        cout << half << "\n";
        while (temp > 0) {
            if (flag) {
                cout << temp << " ";
                temp -= 3;
            } else {
                cout << temp << " ";
                temp -= 1;
            }
            flag = !flag;
        }
        cout << "\n" << n - half << "\n";
        n -= 1;
        flag = true;
        while (n > 0) {
            if (flag) {
                cout << n << " ";
                n -= 1;
            } else {
                cout << n << " ";
                n -= 3;
            }
            flag = !flag;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
