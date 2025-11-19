#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

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

	int n, k;
	cin >> n >> k;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	auto solve = [&] (int val) -> long long {
		Trie<int> trie((1 << 30) - 1, n);
		int l = 0, r = 0;
		long long ans = 0;

		while (l < n) {
			while (r < n) {
				if (l == r) trie.insert(nums[l]);
				else {
					if (trie.findMinXor(nums[r]) >= val) trie.insert(nums[r]);
					else break;
				}
				r ++;
			}

			ans += r - l;
			trie.remove(nums[l]);
			l ++;
		}

		return ans;
	};

	cout << solve(k) - solve(k + 1);

	return 0;
}