#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
/*
    维护因子出现的最右边的位置
*/
void solve(){
    int n;
    cin >> n;
    vector <int> lastf(N+1, 0), ans(n+1);
    auto divide = [&](int x)->vector<int>{
        vector <int> with;
        for (int i = 1; i <= x/i; ++ i){
            if (x%i==0){
                int j = x/i;
                with.push_back(i);
                if (i != j) with.push_back(j);
            }
        }
        return with;
    };

    for (int i = 1; i <= n; ++ i){
        int x, y, cnt = 0;
        cin >> x >> y;
        vector <int> with = divide(x);
        for (auto &it : with){
            // 如果该 因子与最右边的该因子距离大于y，统计答案
            if (i - lastf[it] > y) ++ cnt;
            lastf[it] = i;
        }
        ans[i] = cnt;
    }

    for (int i = 1; i <= n; ++ i) cout << ans[i] << "\n";
}
