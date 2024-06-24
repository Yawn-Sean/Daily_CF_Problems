#include <bits/stdc++.h>
using PII = std::pair<int, int>;
using i64 = long long;
 
const int inf = 1e9;

template<typename T = int>
class FenWick {
private:
    T n;
    std::vector<T> tr;
public:
    FenWick(T _n) : n(_n), tr(_n + 1) 
    {}

    void add(T x, T k) {
        for (; x <= n; x += x & -x) tr[x] += k;
    }

    T query(T x) const {
        T res = 0;
        for (; x; x &= x - 1) res += tr[x];
        return res;
    }
};
 
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i ++ ) std::cin >> nums[i];
    std::vector<int> id(nums);
    std::sort(id.begin(), id.end());
    id.erase(std::unique(id.begin(), id.end()), id.end());
    int m = id.size();
    
    FenWick<int> st(m + 1);

    i64 res = 0;
    for (int x : nums) {
        x = std::lower_bound(id.begin(), id.end(), x) - id.begin() + 1;
        int L = st.query(x - 1), R = st.query(m) - st.query(x);
        st.add(x, 1);
        res += std::min(L, R);
    }
    std::cout << res << '\n';
}
 
 
int main () {
    std::ios::sync_with_stdio(false);   std::cin.tie(0);  std::cout.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_ --)
        solve();
    return 0;
}