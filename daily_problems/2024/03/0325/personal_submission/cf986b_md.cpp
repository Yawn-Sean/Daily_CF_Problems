#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

using i64 = long long;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    // set num[x] = v
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    // sum of [0, x)    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    // rangeSum [l, r)
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    copy_n(istream_iterator<int>(cin), n, begin(nums));

    Fenwick<int> fen(n);
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += i - fen.sum(nums[i]);
        fen.add(nums[i], 1);
    }

    if (3 * n % 2 == cnt % 2) {
        cout << "Petr\n";
    } else {
        cout << "Um_nik\n";
    }

    return 0;
}