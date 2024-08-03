#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
const int N = 300050, M = 1e6+11;
int xcor[N], ycor[N];
bool onx[M], ony[M]; 
vector <int> forX[N], forY[N];
int n, m, k;

void solve(){
    memset(onx, 0, sizeof onx), memset(ony, 0, sizeof ony);

    cin >> n >> m >> k;
    for (int i = 1, cache; i <= n; ++ i)
        cin >> xcor[i], onx[xcor[i]] = true;
    for (int i = 1, cache; i <= m; ++ i)
        cin >> ycor[i], ony[ycor[i]] = true;
    
    for (int i = 1; i <= n; ++ i) forY[i].clear();
    for (int i = 1; i <= m; ++ i) forX[i].clear();

    for (int i = 1; i <= k; ++ i){
        int x, y;
        cin >> x >> y;
        if (onx[x] && ony[y]) continue;
        if (onx[x]){
            int idy = lower_bound(ycor+1, ycor+1+m, y) - ycor;
            forX[idy].push_back(x);  //forX维护纵坐标在ycor[i]下面且在ycor[i-1]上面的点的横坐标
        }
        if (ony[y]){
            int idx = lower_bound(xcor+1, xcor+1+n, x) - xcor;
            forY[idx].push_back(y);  //forY维护横坐标在xcor[i]左边且在xcor[i+1]右边的点的横坐标
        }
    }   

    
    ll res = 0;
    auto calc = [&](vector <int> *vet, int n)->void{
        for (int k = 1; k <= n; ++ k){
            vector <int> &c = vet[k];
            sort(c.begin(), c.end());  //等价于问每层有若干相同的数，从所有层中选出2个，求总方案数
            for (int i = 0, j = 0; i < c.size(); ++ i){
                if (i+1 == c.size() || c[i] != c[i+1]){  //每次用前缀层所有点更新当前层的方案数
                    res += 1ll * (i-j+1) * j;  //前缀点 * 当前层点
                    j = i+1;
                }
            }
        }
    };
    calc(forY, n), calc(forX, m);
    cout << res << "\n";
}
