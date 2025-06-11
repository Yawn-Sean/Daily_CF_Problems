#include <bits/stdc++.h>
using namespace std;
void fmax(int &x, int y){
    if (y > x) x = y;
}
void fmin(int &x, int y){
    if (y < x) x = y;
}

void solve(){
    int n, h;
    cin >> n >> h;
    vector <int> A(n), p(n);
    const int inf = 1e9;
    int mi1 = inf, mi2 = inf, mi3 = inf;
    int ma1 = 0, ma2 = 0;

    for (auto &x : A){
        cin >> x;
        if (x < mi1){
            mi3 = mi2, mi2 = mi1;
            mi1 = x; 
        } else if (x < mi2){
            mi3 = mi2;
            mi2 = x;
        } else if (x < mi3){
            mi3 = x;
        }

        if (x > ma1){
            ma2 = ma1;
            ma1 = x;
        } else if (x > ma2){
            ma2 = x;
        }
    }
    int f1 = ma1+ma2 - (mi1+mi2);
    int f2 = max(ma1+ma2, mi1+h+ma1) - min(mi2+mi3, mi1+h+mi2);

    cout << min(f1, f2) << "\n";
    if (f1 <= f2){
        for (int i = 0; i < n; ++ i){
            if (i) cout << " ";
            cout << 1;
        }
    } else {
        for (int i = 0, jg = 0; i < n; ++ i){
            if (i) cout << " ";
            cout << ((A[i]==mi1&&!jg) ? 2 : 1);
            if (A[i]==mi1) jg = 1;
        }
    }
}
