#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
#include <queue>
using namespace std;

long long mod = 1e9 + 7;

template <typename T>
class Fenw {
public:
    Fenw(int _n) : n(_n), v(n, 0) {}
    int lowbit(int x) { return x & -x; }
    T sum(int x) {
        T ans = 0;
        // i = i&(i-1);
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += v[i];
            ans %= mod;
        }
        return ans;
    }
    void update(int x, T val) {
        for (int i = x; i < n; i += lowbit(i)) {
            v[i] += val;
            v[i] %= mod;
        }
    }
    T rangeSum(int left, int right) {
        return sum(right) - sum(left - 1);
    }
   
private:
    int n;
    vector<T> v;
};


int main() {
	
	int n;cin >> n;

	vector<int> a(n);
	for (int i = 0;i < n;++i) {
		cin >> a[i];
	}
	auto b = a;
	sort(b.begin(), b.end());

	b.erase(unique(b.begin(), b.end()), b.end());

    Fenw<long long> fw(b.size()+1);
    long long tot = 0;

	for (int i = 0;i < n;++i) {
        long long v = a[i];
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        long long s = (fw.sum(a[i] + 1) + 1) * v % mod - (fw.sum(a[i] + 1) - fw.sum(a[i]));
        s %= mod;
        tot += s;
        tot %= mod;
        fw.update(a[i] + 1, s);
	}
    tot += mod;
    tot %= mod;
    cout << tot;







	return 0;
}