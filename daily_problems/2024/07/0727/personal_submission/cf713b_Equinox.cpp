// LUOGU_RID: 169096278
#include <bits/stdc++.h>
#include <ranges>
#define sc scanf
// #define DEBUG
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using PII = std::pair<int, int>;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1e18 + 7;
constexpr int P = 1E9 + 7;
constexpr double eps = 1E-6;

/*
    1、先划分两块，每块各一个矩形
        如果二者平行则得再二分一次
    2、每块再单独二分四个边界

    128 + 33 = 161
*/

int query(int x1, int y1, int x2, int y2) {
    std::cout << '?' << ' ' << x1 << ' ' << y1 << ' ' << x2  << ' ' << y2 << '\n';
    std::cout.flush();
    
    // int c = 0;
    // if (x1 <= 2 && y1 <= 2 && x2 >= 2 && y2 >= 2)
    //     ++ c;
    // if (x1 <= 3 && y1 <= 4 && x2 >= 3 && y2 >= 5)
    //     ++ c;
    // return c;

    int res;
    std::cin >> res;
    return res;
}

std::vector<int> path;

void work(int x1, int y1, int x2, int y2) {
    int l, r, ans;

    // 左边界
    l = x1, r = x2, ans = -1;
    while (l <= r) {
        int x = l + r >> 1;
        if (query(x, y1, x2, y2))
            ans = x, l = x + 1;
        else
            r = x - 1;
    }
    path.push_back(ans);


     // 下边界
    l = y1, r = y2, ans = -1;
    while (l <= r) {
        int x = l + r >> 1;
        if (query(x1, x, x2, y2))
            ans = x, l = x + 1;
        else
            r = x - 1;
    }
    path.push_back(ans);


    // 右边界
    l = x1, r = x2, ans = -1;
    while (l <= r) {
        int x = l + r >> 1;
        if (query(x1, y1, x, y2))
            ans = x, r = x - 1;
        else
            l = x + 1;
    }
    path.push_back(ans);

    //上边界
    l = y1, r = y2, ans = -1;
    while (l <= r) {
        int x = l + r >> 1;
        if (query(x1, y1, x2, x))
            ans = x, r = x - 1;
        else
            l = x + 1;
    }
    path.push_back(ans);


}

void solve() {
    int n;
    std::cin >> n;

    int l = 1, r = n + 1;
    while (l < r) {
        int x = l + r >> 1;
        if (query(1, 1, x, n))
            r = x;
        else
            l = x + 1;
    }

    if (l < n && query(l + 1, 1, n, n) == 1) {
        // std::cerr << 1 << ' ' << 1 << ' ' << l << ' ' << n << '\n';
        // std::cerr << l + 1 << ' ' << 1 << ' ' << n << ' ' << n << '\n';
        work(1, 1, l, n);
        work(l + 1, 1, n, n);
    }
    else { // 平行
        int l = 1, r = n;
        while (l < r) {
            int x = l + r >> 1;
            if (query(1, 1, n, x))
                r = x;
            else
                l = x + 1;
        }
        work(1, 1, n, l);
        work(1, l + 1, n, n);
    }

    std::cout << '!' << ' ';
    for (int i = 0; i < path.size(); ++ i)
        std::cout << path[i] << " \n"[i == path.size() - 1];
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_--)
        solve();
    return 0;
}