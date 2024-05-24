#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e18, mod = 998244353, N = 200060;
struct fenwick {
    vector <int> tr;
    int n;
    fenwick(){}
    fenwick(int n): tr(n+1), n(n){}
    void add(int x, int c){
        ++ x;
        while (x <= n) tr[x] += c, x += x&-x;
    }
    int query(int x) {
        ++ x;
        int res = 0;
        while (x) res += tr[x], x -= x & -x;
        return res;
    }
};

void solve(){
    int n;
    cin >> n;
    static fenwick box1(n), box2(n), box3(n);

    vector <int> A(n+1), B(n+1), f(n+1), g(n+1), flag(n+2);

    for (int i = 1; i <= n; ++ i) cin >> A[i];
    for (int i = 1; i <= n; ++ i) cin >> B[i];

    for (int i = 1; i <= n; ++ i){
        f[i] = A[i] - box1.query(A[i]);  //f,g,分别计算当前数字对竖式原本的贡献减去前面比它小的数有多少个
        g[i] = B[i] - box2.query(B[i]);
        if (f[i] + g[i] > n-i) flag[i] = 1;  //模拟阶乘的进位过程
        else if (f[i] + g[i] < n-i) flag[i] = 0;
        else flag[i] = -1;
        box1.add(A[i], 1), box2.add(B[i], 1);
    }
    for (int i = n, last = 0; i > 0; -- i){  //预处理进位
        if (flag[i] == -1) flag[i] = last;
        else last = flag[i];
    }

    for (int i = 1; i <= n; ++ i){  //从高位到低位二分, 调整数值
        int x = (f[i] + g[i] + flag[i+1]) % (n+1-i); //该位置不会超过n-i
        int l = 0, r = n-1;
        while (l < r){ 
            int mid = l+r >> 1;
            if (mid - box3.query(mid) >= x) r = mid; //找到第一个比 x - 前缀统计过的数字 大的数字
            else l = mid+1;
        }
        cout << l;
        if (i != n) cout << " ";
        box3.add(l, 1);  //加上统计
    }
    cout << "\n";
}
#2024.5.23
