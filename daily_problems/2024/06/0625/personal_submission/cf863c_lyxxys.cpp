#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5, inf = 1e9;
array<int,2> g[N][N];
int A[4][4], B[4][4];

void solve(){   
    ll k, a, b;
    cin >> k >> a >> b;
    for (int type = 0; type < 2; ++ type)
        for (int i = 1; i <= 3; ++ i)
            for (int j = 1; j <= 3; ++ j)
                if (type==0) cin >> A[i][j];
                else cin >> B[i][j];
    
    vector <int> nums(1);
    ll res1 = 0, res2 = 0;
    //比较函数
    auto cmp = [&](int x, int y)->int{
        if (x==y) return 0;
        if (x==1 && y==3 || x==2 && y==1 || x==3 && y==2) return 1;
        else return -1;
    };

    -- k;
    if (cmp(a, b) == 1) res1 += 1;
    else if (cmp(a, b) == -1) res2 += 1;
    int tmpa = a, tmpb = b;
    
    array<int,2> wing;
    while (true){
        int x = A[a][b], y = B[a][b];
        g[a][b] = {x, y};
        if (g[x][y][0]){
            wing = {x, y};
            break;
        }
        a = x, b = y;
    }
    // 原点不是环点， 先走到环点
    if (tmpa != wing[0] || tmpb != wing[1]){
        a = tmpa, b = tmpb;
        while (k){
            -- k;
            int x = A[a][b], y = B[a][b];
            if (cmp(x, y) == 1) res1 += 1;
            else if (cmp(x, y) == -1) res2 += 1;
            if (x==wing[0] && y==wing[1]) break;
            a = x, b = y;
        }
    }
    a = wing[0], b = wing[1];
    //从环点开始记录环的路径权值
    while (k){
        -- k;
        int x = A[a][b], y = B[a][b];
        if (cmp(x, y) == 1) res1 += 1, nums.push_back(1);
        else if (cmp(x, y) == -1) res2 += 1, nums.push_back(-1);      
        else nums.push_back(0);
        if (x==wing[0] && y==wing[1]) break;
        a = x, b = y;
    }
    // 路径长度为n
    int n = nums.size()-1;
    ll q = k/n;
    //跑q次
    if (q)
        for (int i = 1; i <= n; ++ i){
            if (nums[i]==1) res1 += q;
            else if (nums[i]==-1) res2 += q;
        }
    //跑剩下的
    for (int i = 1; i <= k%n; ++ i){
        if (nums[i]==1) res1 += 1;
        else if (nums[i]==-1) res2 += 1;
    }
    cout << res1 << " " << res2 << "\n";
}
