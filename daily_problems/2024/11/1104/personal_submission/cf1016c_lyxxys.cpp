#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    vector <int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    long long sum1 = 0, sum2 = 0;
    vector <long long> Pr1(2*n), Pr2(2*n);

    for (int i = 1; i < n; ++ i){
        sum1 += 1ll * i * A[i];
        Pr1[i] = Pr1[i-1] + A[i];

        sum2 += 1ll * i * B[i];
        Pr2[i] = Pr2[i-1] + B[i];
    }
    for (int i = n-1, idx = n; i >= 0; -- i, ++ idx){
        sum1 += 1ll * idx * B[i];
        Pr1[idx] = Pr1[idx-1] + B[i];

        sum2 += 1ll * idx * A[i];
        Pr2[idx] = Pr2[idx-1] + A[i];
    }

    long long res = 0;
    long long ans = 0, c = 0;
    int x = 0, y = 0;

    auto subs = [&](int i)->void{       // 更新折返 的 贡献
        long long t1 = Pr1[2*n-i-1] - Pr1[i];
        long long t2 = Pr2[2*n-i-1] - Pr2[i];
        sum1 -= t1;
        sum2 -= t2;
        int rare = 2 * (n-i-1);
        sum1 -= 1ll * rare * B[i];
        sum2 -= 1ll * rare * A[i];
    };

    while (y < n){
        
        if (x == 0){
            
            long long all = Pr1[2*n-y-1] - Pr1[y];
            fmax(res, ans + all*c + sum1);  // 计算在 (1, y) 先走满第一行的值
            x += 1, c += 1;
            ans += c * B[y];

            subs(y);
            y += 1, c += 1;
            if (y >= n) break;
            ans += c * B[y];
        } else {
            
            long long all = Pr2[2*n-y-1] - Pr2[y];
            fmax(res, ans + all*c + sum2);
            x -= 1, c += 1;
            ans += c * A[y];

            subs(y);
            y += 1, c += 1;
            if (y >= n) break;
            ans += c * A[y];
        }
    }

    fmax(res, ans);
    cout << res << "\n";
}
