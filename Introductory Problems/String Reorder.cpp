#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define inf 1e18

void solve() {
  string s;
  cin >> s;
  vector<int> freq(26, 0);
  for (auto& it : s) freq[it - 'A']++;
  int n = s.length();
  int maxFreq = *max_element(freq.begin(), freq.end());
  if (maxFreq > (n + 1) / 2) {
    cout << "-1";
    return;
  }
  string ans = "";
  for (int pos = 0; pos < n; pos++) {
    for (int ch = 0; ch < 26; ch++) {
      if (freq[ch] == 0) continue;
      if (!ans.empty() && ans.back() == char(ch + 'A')) continue;
      freq[ch]--;
      int rem = n - pos - 1;
      int maxFeq = *max_element(freq.begin(), freq.end());
      if (maxFeq <= (rem + 1) / 2) {
        ans += char(ch + 'A');
        break;
      }
      freq[ch]++;
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
