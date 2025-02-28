#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    vector<int> loc(1000001, -1);

    int n, m;
    cin >> n >> m;
    vector <int> A(2*n), B(m), Q(2*n+1);
    for (int i = 0; i < n; ++ i){
        cin >> A[i];
        A[i+n] = A[i];
    }
    for (int i = 0; i < m; ++ i){
        cin >> B[i];
    }
    for (int i = 0; i < m; ++ i){
        loc[B[i]] = i;
    }

    int tp = -1, hp = 0;
    auto check = [&](int pos)->bool{  // 检查 pos 这个位置进入到子序列后是否合法
        if (pos == -1) return false;

        assert(tp >= hp);

        if (Q[tp] >= Q[hp]){  // 根据队头 和 队尾 的位置分类讨论
            if (pos >= Q[hp] && pos <= Q[tp]) return false;
            else return true;
        } else {
            if (pos >= Q[hp] || pos <= Q[tp]) return false;
            else return true;
        }
    };

    int res = 0;
    for (int i = 0, j = -1; i < 2*n; ++ i){

        while (j < i || (Q[hp] != -1 && j+1 < 2*n && j-i+2 <= n && check(loc[A[j+1]]))){
            Q[++ tp] = loc[A[j+1]];
            j += 1;
        }
        if (Q[hp] != -1) fmax(res, j-i+1);
        hp += 1;
    }

    cout << res << "\n";
}

