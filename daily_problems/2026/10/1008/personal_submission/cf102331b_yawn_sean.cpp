#include <bits/stdc++.h>
using namespace std;

template <class S>
struct Trie
{

public:
    explicit Trie(S max_value, int size)
    {
        pt = 1;
        bit = 64 - __builtin_clzll(max_value);
        int total = size * bit + 1;
        zero.resize(total, -1);
        one.resize(total, -1);
        cnt.resize(total, 0);
    }

    void insert(S value)
    {
        int node = 0;
        for (int i = bit - 1; i >= 0; i--)
        {
            cnt[node]++;
            if (value >> i & 1)
            {
                if (one[node] == -1)
                    one[node] = pt++;
                node = one[node];
            }
            else
            {
                if (zero[node] == -1)
                    zero[node] = pt++;
                node = zero[node];
            }
        }
        cnt[node]++;
    }

    void remove(S value)
    {
        int node = 0;
        for (int i = bit - 1; i >= 0; i--)
        {
            cnt[node]--;
            node = (value >> i & 1 ? one[node] : zero[node]);
        }
        cnt[node]--;
    }

    S findMaxXor(S v)
    {
        int node = 0;
        S ans = 0;
        for (int i = bit - 1; i >= 0; i--)
        {
            ans <<= 1;
            if (v >> i & 1)
            {
                if (zero[node] != -1 && cnt[zero[node]])
                    node = zero[node], ans++;
                else
                    node = one[node];
            }
            else
            {
                if (one[node] != -1 && cnt[one[node]])
                    node = one[node], ans++;
                else
                    node = zero[node];
            }
        }
        return ans;
    }

    S findMinXor(S v)
    {
        int node = 0;
        S ans = 0;
        for (int i = bit - 1; i >= 0; i--)
        {
            ans <<= 1;
            if (v >> i & 1)
            {
                if (one[node] != -1 && cnt[one[node]])
                    node = one[node];
                else
                    node = zero[node], ans++;
            }
            else
            {
                if (zero[node] != -1 && cnt[zero[node]])
                    node = zero[node];
                else
                    node = one[node], ans++;
            }
        }
        return ans;
    }

    int countLowXor(S num, S x)
    {
        if (x >= 1ll << bit) return cnt[0];
        int node = 0, ans = 0;
        for (int i = bit - 1; i >= 0; i--)
        {
            if (x >> i & 1)
            {
                if (num >> i & 1)
                {
                    if (one[node] > 0)
                        ans += cnt[one[node]];
                    if (zero[node] > 0)
                        node = zero[node];
                    else
                        break;
                }
                else
                {
                    if (zero[node] > 0)
                        ans += cnt[zero[node]];
                    if (one[node] > 0)
                        node = one[node];
                    else
                        break;
                }
            }
            else
            {
                if (num >> i & 1)
                {
                    if (one[node] > 0)
                        node = one[node];
                    else
                        break;
                }
                else
                {
                    if (zero[node] > 0)
                        node = zero[node];
                    else
                        break;
                }
            }
        }
        return ans;
    }

private:
    int pt, bit;
    vector<int> zero, one, cnt;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long x;
	cin >> n >> x;

	vector<long long> nums(n);
	for (auto &v: nums) cin >> v;

	sort(nums.begin(), nums.end());

	int mod = 998244353;

	if (!x) {
		int ans = 1;
		for (int i = 0; i < n; i ++) ans = ans * 2 % mod;
		cout << ans - 1;
	}
	else {
		int k = 64 - __builtin_clzll(x);
		long long v = 1ll << k;

		auto solve = [&] (int l, int r) -> int {
			Trie<long long> trie(x, r - l);
			int cnt = 0, ans = r - l + 1;

			for (int i = l; i < r; i ++) {
				ans += cnt - trie.countLowXor(nums[i], x);
				ans %= mod;

				cnt ++;
				trie.insert(nums[i]);
			}

			return ans;
		};

		int l = 0, ans = 1;

		for (int i = 0; i < n; i ++) {
			if (nums[i] / v != nums[l] / v) {
				ans = 1ll * ans * solve(l, i) % mod;
				l = i;
			}
		}
		ans = 1ll * ans * solve(l, n) % mod;

		cout << (ans + mod - 1) % mod;
	}

	return 0;
}