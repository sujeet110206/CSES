#include<bits/stdc++.h>
using namespace std;

bool is_prime(int64_t p) {
    if (p <= 1) return false;
    if (p <= 3) return true;
    if (p % 2 == 0 || p % 3 == 0) return false;
    for (int64_t i = 5; i * i <= p; i += 6) {
        if (p % i == 0 || p % (i + 2)  == 0)
            return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int64_t n;
        cin >> n;
        int64_t p = n + 1;
        while (!is_prime(p)) p++;
        cout << p << '\n';
    }
    return 0;
}
