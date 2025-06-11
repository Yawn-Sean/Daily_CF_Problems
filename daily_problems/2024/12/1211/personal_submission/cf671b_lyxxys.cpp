#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> A(n);
    int ma = 0, mi = 1e9;
    for (auto &x : A){
        cin >> x;
        fmax(ma, x);
        fmin(mi, x);
    }

    auto chk1 = [&](int mid1)->bool{
        long long det1 = 0, det2 = 0;
        for (auto &x : A){
            if (mid1 >= x) det1 += mid1-x;
            else det2 += x-mid1;
        }
        return det1 <= det2 && det1 <= k;
    };
    auto chk2 = [&](int mid2)->bool{
        long long det1 = 0, det2 = 0;
        for (auto &x : A){
            if (x >= mid2) det1 += x-mid2;
            else det2 += mid2-x;
        }
        return det1 <= det2 && det1 <= k;
    };

    int poor, rich;
    int lo = mi, hi = ma;
    while (lo < hi){
        int mid = (lo+hi+1) >> 1;
        if (chk1(mid)) lo = mid;
        else hi = mid-1;
    }
    poor = lo;

    lo = mi, hi = ma;
    while (lo < hi){
        int mid = (lo+hi) >> 1;
        if (chk2(mid)) hi = mid;
        else lo = mid+1;
    }
    rich = lo;
    assert(poor <= rich);

    cout << rich-poor << "\n";
}
