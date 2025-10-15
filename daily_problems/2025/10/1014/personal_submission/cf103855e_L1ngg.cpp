//RR....PP....SSS
//ss...RR...PP
//PP....SS....RRR
//PPPSSS SR
//PPPSSS RP

//no: RS  PR SP

#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, k;   std::cin >> n >> k;
    std::string s;  std::cin >> s;

    auto cal = [&](int l, int r) {
        std::map<char, std::vector<int>> mp;
        for (int i = l;i < r;i++)
            mp[s[i]].push_back(i);

        if (!mp.contains('P')) {
            for (int i = l;i < r;i++)
                s[i] = 'R';
            int st = l - 1;
            for (auto idx : mp['S']) {
                st = std::max(st + 1, idx - k);
                s[st] = 'S';
            }
        }
        else if (!mp.contains('R')) {
            for (int i = l;i < r;i++)
                s[i] = 'S';
            int st = l - 1;
            for (auto idx : mp['P']) {
                st = std::max(st + 1, idx - k);
                s[st] = 'P';
            }
        }
        else {
            for (int i = l;i < r;i++)
                s[i] = 'P';
            int st = l - 1;
            for (auto idx : mp['R']) {
                st = std::max(st + 1, idx - k);
                s[st] = 'R';
            }
        }
        };

    std::set<char> st;
    int l = 0;
    for (int i = 0;i < n;i++)
    {
        st.insert(s[i]);
        if (st.size() == 3) {
            cal(l, i);
            l = i;
            st = { s[i] };
        }
    }
    cal(l, n);
    std::cout << s;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}
