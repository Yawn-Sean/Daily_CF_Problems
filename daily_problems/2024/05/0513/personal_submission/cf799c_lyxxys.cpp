#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 2e9;

void solve(){
    int n, c, d;
    cin >> n >> c >> d;
    vector <array<int,2>> coin(1), diamond(1);  //设置哨兵
    for (int i = 1; i <= n; ++ i){
        array <int,2> t;
        string ops;
        cin >> t[0] >> t[1] >> ops;
        if (ops == "C") coin.push_back(t);
        else diamond.push_back(t);
    }
    auto cmp = [](array<int,2> &a, array<int,2> &b)->bool{  //加引用效率提升20倍
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];  //按花费排序
    };
    sort(coin.begin(), coin.end(), cmp), sort(diamond.begin(), diamond.end(), cmp);
    auto find = [](vector<array<int,2>> &a, int x, int l, int r)->int{
        while (l < r){;
            int mid = l+r+1 >> 1;
            if (a[mid][1] <= x) l = mid;
            else r = mid-1;
        }
        return l;
    };
    vector <int> Pre1(n+1), Pre2(n+1);
    for (int i = 1; i < coin.size(); ++ i)
        Pre1[i] = max(Pre1[i-1], coin[i][0]);
    for (int i = 1; i < diamond.size(); ++ i)
        Pre2[i] = max(Pre2[i-1], diamond[i][0]);

    int res = 0;
    int pcoin = 0, pdiamond = 0;
    for (int i = coin.size()-1, w, spend, pos; i > 0; -- i){
        if (coin[i][1] <= c && coin[i][0] > coin[pcoin][0])
            pcoin = i;

        w = coin[i][0], spend = coin[i][1];
        pos = find(coin, c-spend, 0, i-1);
        if (pos == 0) continue;
        res = max(res, w+Pre1[pos]);  //费用少于剩余钱数的都可以选，取美丽值最大的
    }
    for (int i = diamond.size()-1, w, spend, pos; i > 0; -- i){
        if (diamond[i][1] <= d && diamond[i][0] > diamond[pdiamond][0])
            pdiamond = i;

        w = diamond[i][0], spend = diamond[i][1];
        pos = find(diamond, d-spend, 0, i-1);
        if (pos == 0) continue;
        res = max(res, w+Pre2[pos]);
    }
        
    if (pcoin && pdiamond)
        res = max(res, coin[pcoin][0]+diamond[pdiamond][0]);
    
    cout << res << "\n";
}
