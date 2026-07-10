#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int cnt = 0;
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    if (left == right) {
      cnt++;
      break;
    }
    if (a[left] + a[right] <= x)
      left++;
    cnt++;
    right--;
  }
  cout << cnt << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
