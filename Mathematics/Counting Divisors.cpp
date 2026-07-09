#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define sp ' '
#define pb push_back
#define inf 1e18
#define pii pair<int, int>
#define pll pair<ll, ll>

const int N = 1e6 + 1;
vector<ll> divisors(N, 0);
void precompute_divisors() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divisors[j]++;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  precompute_divisors();
  int t;
  cin >> t;
  while(t--) {
    ll x;
    cin >> x;
    cout << divisors[x] << endl;
  }
  return 0;
}
