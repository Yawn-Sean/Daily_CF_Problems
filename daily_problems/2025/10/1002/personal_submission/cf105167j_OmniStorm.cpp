using i64 = long long;
using i128 = __int128_t;
#define dbg(x)  std::cerr << __LINE__ << ":" << #x << " = " << x << "\n"

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    if (n == 2) {
        std::cout << abs(a[2] - a[1]) << " 0\n";
        return;
    }

    std::vector b = a;
    std::sort(b.begin() + 1, b.end());

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= n / 2) {
            ans -= b[i] * 2LL;
        } else {
            ans += b[i] * 2LL;
        }
    }
    ans += b[n / 2];
    ans -= b[n / 2 + 1];
    
    i64 sum = 0;
    {
        std::vector<int> a1, a2;
        std::vector<int> S;
        int p1, p2;
        
        for (int i = 1; i <= n; i++) {
            if (a[i] == n / 2 || a[i] == n / 2 + 1) {
                if (a[i] == n / 2)
                p1 = i;
                else
                p2 = i;
                S.push_back(i);
            } else {
                (a[i] <= n / 2 ? a1 : a2).push_back(i);
            }
        }
        
        i64 q = 1;
        if (a[S[0]] < a[S[1]]) std::swap(S[0], S[1]);
        sum += S[0] - S[1] + n - 1;
        if (S[0] > S[1]) sum--;
        p1 = S[0], p2 = S[1];
        for (auto& x : a1) {
            if (x < p1) x++;
            if (x > p2) x--;
        }
        for (auto& x : a2) {
            if (x < p1) x++;
            if (x > p2) x--;
        }
        for (int i = 2, j = 0; i < n; i += 2, j++) {
            sum += abs(a1[j] - i);
        }
        
    }
    i64 sum2 = 0;
    {
        std::vector<int> a1, a2;
        std::vector<int> S;
        int p1, p2;
    
        for (int i = 1; i <= n; i++) {
            if (a[i] == n / 2 || a[i] == n / 2 + 1) {
                if (a[i] == n / 2)
                    p1 = i;
                else
                    p2 = i;
                S.push_back(i);
            } else {
                (a[i] <= n / 2 ? a1 : a2).push_back(i);
            }
        }
        if (a[S[0]] > a[S[1]]) std::swap(S[0], S[1]);
        i64 q = -1;
        
        sum2 += S[0] - S[1] + n - 1;
        if (S[0] > S[1]) sum2--;
        p1 = S[0], p2 = S[1];
        i64 sum3 = 0;
        for (auto& x : a1) {
            if (x < p1) x++;
            if (x > p2) x--;
        }
        for (auto& x : a2) {
            if (x < p1) x++;
            if (x > p2) x--;
        }
        
        for (int i = 3, j = 0; i < n; i += 2, j++) {
            sum2 += abs(a1[j] - i);
        }
    }
    
    std::cout << ans << " " << std::min(sum, sum2) << "\n";
}
