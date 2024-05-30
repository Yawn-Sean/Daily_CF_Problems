#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5050, mod = 998244353;
struct cmp {
    bool operator()(array<ll,2> &a, array<ll,2> &b){
        return a[0] > b[0];
    }
};

void solve(){
    int n, k, m, s;
    cin >> n >> m >> k >> s;
    vector <int> a(n+1), b(n+1), idx1(n+1), idx2(n+1);
    vector <array<int,2>> item;
    vector <ll> dollar, pound;
    for (int i = 1; i <= n; ++ i) idx1[i] = idx2[i] = i;  //预处理前缀最小，和改前缀最小是第几天
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    for (int i = 1, t, c; i <= m; ++ i){
        cin >> t >> c;
        if (t == 1) dollar.push_back(c);
        else pound.push_back(c);
        item.push_back({t, c});
    }
    for (int i = 2; i <= n; ++ i){
        if (a[i] > a[i-1]) a[i] = a[i-1], idx1[i] = idx1[i-1];
        if (b[i] > b[i-1]) b[i] = b[i-1], idx2[i] = idx2[i-1];
    }
    sort(dollar.begin(), dollar.end()), sort(pound.begin(), pound.end());
    int len1 = dollar.size(), len2 = pound.size();

    auto check = [&](int mid)->bool{
        ll tot = s;
        int p1 = 0, p2 = 0;
        for (int i = 1; i <= k; ++ i){
            // 双指针核心，每次选代价最小的
            if (p1 == len1){
                tot -= pound[p2]*b[mid], ++ p2;
            } else if (p2 == len2){
                tot -= dollar[p1]*a[mid], ++ p1;
            } else if (dollar[p1]*a[mid] < pound[p2]*b[mid]){
                tot -= dollar[p1]*a[mid], ++ p1;
            } else {
                tot -= pound[p2]*b[mid], ++ p2;
            }
            if (tot < 0) return false;
        }
        //只需贪心地取美元汇率最有利时，买入所有需要用美元买的东西
        //贪心地取欧元汇率最有利时，买入所有需要用欧元买的东西
        return true;
    };

    int l = 1, r = n+1;
    while (l < r){
        int mid = l+r >> 1;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    if (l == n+1) return cout << "-1\n", void();

    cout << l << "\n";
    vector <array<int,2>> ans;
    priority_queue<array<ll,2>, vector<array<ll,2>>, cmp> pq;
    for (int i = 0; i < item.size(); ++ i)
        if (item[i][0] == 1) pq.push({1ll*a[l]*item[i][1], i});
        else pq.push({1ll*b[l]*item[i][1], i});
    int buy1 = idx1[l], buy2 = idx2[l];
    vector <array<ll,2>> chosen;
    for (int i = 1; i <= k; ++ i) chosen.push_back(pq.top()), pq.pop();  //取出前k大的
    for (auto &it : chosen){
        int idx = it[1];
        if (item[idx][0] == 1) ans.push_back({idx+1, buy1});  //记录编号和天数
        else ans.push_back({idx+1, buy2});
    }
    for (auto &it : ans) cout << it[0] << " " << it[1] << "\n";
}

