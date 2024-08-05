#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> nums(n);
	vector<vector<int>> tmp(n);

	for (int i = 0; i < n; i ++) {
		cin >> nums[i];
		nums[i] = min(nums[i], n) - 1;
		tmp[nums[i]].emplace_back(i);
	}

	long long ans = 0;
	FenwickTree fen(n);
	for (int i = n - 1; i >= 0; i --) {
		for (auto &x : tmp[i])
			fen.add(x, 1);
		if (nums[i] > i)
			ans += fen.sum(i, nums[i] - 1);
	}
	cout << ans;
	return 0;
}
