/*
如果 a[i] <= a[j], i < j，则模 a[j] 没用
所以真正有用的是严格单调递减的模数序列
另外，对于某个 x，其在第一个 <= x 的模数出现时才有用，前面的都没用，不过问题可能不太大
我们直接从 a[1] 开始，先提取出严格递减的子序列，后边只考虑这些的模的值
下面考虑一个事情
x % a[i] 之后变小，其变小的次数会很多吗？
我的意思是，x 是个很大的数，a 也很大，x %= a[i] 之后变小
我们会快速找下一个 >= x 的 a[j]
x % a[i] 如果真的让 x 变小了，会变小多少？
x % a[i] < a[i]，还知道 x % a[i] = x - x / a[i] * a[i]
所以假如会变小，则会变小 x / a[i] * a[i]
这个东西有多大呢？
如果 (k + 1) * a[i] > x >= k * a[i]，则会减少 k * a[i]
对于 x 来说至少是减半了
所以只需要每次二分查 >= x 的最小的 a[i]，然后 x %= a[i]
到查不到为止，就是答案了
每次模拟有用的模数至多有 log x 个
*/

const int N = 2e5 + 10;

int n, q, a[N];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<int> b;
    b.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (a[i] < b.back()) {
            b.push_back(a[i]);
        }
    }
    
    while (q--) {
        int x;
        cin >> x;
        int st = 0;
        
        auto check = [&] (int ans) -> bool {
            return b[ans] <= x;    
        };
        
        while (st < b.size()) {
            int l = st, r = b.size() - 1, mid;
            while (l + 1 < r) {
                mid = (l + r) / 2;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            
            if (check(l)) {
                x %= b[l];
                st = l + 1;
            } else if (check(r)) {
                x %= b[r];
                st = r + 1;
            } else {
                break;
            }
        }
        cout << x << "\n";
    }
}
