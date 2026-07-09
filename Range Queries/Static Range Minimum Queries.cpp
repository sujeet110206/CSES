#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define pb push_back

class SegmentTree {
private:
	vector<ll> seg;
	vector<ll> arr;
	int n;

	void build(int ind, int low, int high) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid);
		build(2 * ind + 2, mid + 1, high);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}

	ll query(int ind, int low, int high, int l, int r) {
		if (l > high || r < low)
			return INT_MAX;
		if (l <= low && high <= r)
			return seg[ind];
		int mid = (low + high) / 2;
		ll leftRes = query(2 * ind + 1, low, mid, l, r);
		ll rightRes = query(2 * ind + 2, mid + 1, high, l, r);
		return min(leftRes, rightRes);
	}
public:
	SegmentTree(vector<ll> &input) {
		arr = input;
		n = arr.size();
		seg.resize(4 * n);
		build(0, 0, n - 1);
	}
    
	ll getMinValue(int l, int r) {
		return query(0, 0, n - 1, l, r);
	}
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    SegmentTree smt(v);
    while (q--) {
        int a, b;
        cin >> a >> b;

        int ans  = smt.getMinValue(a - 1, b - 1);
        cout << ans << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    solve();

	return 0;
}
