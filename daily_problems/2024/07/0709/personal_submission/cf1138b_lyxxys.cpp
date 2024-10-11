#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector <int> A(n+1), B(n+1), ids(n+1);
    vector<vector<int>> with(3);

    int tot = 0;
    for (int i = 1; i <= n; ++ i){
        char x;
        cin >> x;
        A[i] = x-'0';
        tot += A[i];
    }
    for (int i = 1; i <= n; ++ i){
        char x;
        cin >> x;
        B[i] = x-'0';
        with[A[i]+B[i]].push_back(i);
    }

    int m1 = with[0].size(), m2 = with[1].size(), m3 = with[2].size();
    int p, ct1, ct2;
    // 枚举会两种技能的艺术家
    for (p = 0; p <= m3; ++ p){
        ct1 = tot-2*p;  // 会一种技能的艺术家
        ct2 = n/2 - ct1 - p;  // 一种技能都不会的艺术家
        if (ct1 > m2 || ct2 > m1 || ct1 < 0 || ct2 < 0) continue;
        break;
    }
    if (p == m3+1){
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < p; ++ i) ids[with[2][i]] = 1;
    for (int i = 0; i < ct1; ++ i) ids[with[1][i]] = 1;
    for (int i = 0; i < ct2; ++ i) ids[with[0][i]] = 1;

    for (int i = 1; i <= n; ++ i)
        if (!ids[i]) cout << i << " ";
}
