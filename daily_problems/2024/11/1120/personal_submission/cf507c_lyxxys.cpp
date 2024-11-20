#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    long long tar, h;
    cin >> h >> tar;
    tar += (1ll << h) - 1;

    const long long limi = (1ll << h+1);
    const long long L = h+1;

    auto findL = [&](long long j)->long long{
        while (j*2 < limi) j *= 2;
        return j;
    };
    auto findR = [&](long long j)->long long{
        while (j*2+1 < limi) j = j*2 + 1;
        return j;
    };
    auto call = [&](int dep)->long long{
        return (1ll << dep)-1;
    };

    long long cur = 1, res = 0;
    int signal = 0, dep = 1;
    // signal == 0 表示走左边，否则表示走右边
    while (cur != tar){
        if (signal == 0){
            long long j = findR(cur*2);
            if (j < tar){
                res += call(L-dep);
                cur = cur*2+1;
            } else {
                cur = cur*2;
                signal = 1;
            }
        } else {
            long long j = findL(cur*2+1);
            if (j > tar){
                res += call(L-dep);
                cur = cur*2;
            } else {
                cur = cur*2+1;
                signal = 0;
            }
        }
        res += 1, dep += 1;
    }

    cout << res << "\n";
}
