#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct P {
    ll x, y;
};
long double ang(const P& a){ return atan2l((long double)a.y, (long double)a.x); }
ll cross(const P& a, const P& b){ return a.x*b.y - a.y*b.x; }
P rotCCW(const P& a){ return P{-a.y, a.x}; }  
P rotCW (const P& a){ return P{ a.y,-a.x}; } 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    if(!(cin >> n)) return 0;
    vector<P> p(n);
    for(int i=0;i<n;i++) cin >> p[i].x >> p[i].y;

    if(n==1){
        cout << "YES\n";
        cout << "1 0\n0 1\n";
        return 0;
    }

    int m = n-1;
    vector<P> d(m);
    for(int i=0;i<m;i++){
        d[i] = P{p[i+1].x - p[i].x, p[i+1].y - p[i].y};
        if(d[i].x==0 && d[i].y==0){ 
            cout << "NO\n"; 
            return 0;
        }
    }

    vector<pair<long double,int>> a;
    a.reserve(m);
    for(int i=0;i<m;i++) a.push_back({ang(d[i]), i});
    sort(a.begin(), a.end(), [](auto &A, auto &B){ return A.first < B.first; });

    const long double PI = acosl(-1.0L);
    vector<pair<long double,int>> ext = a;
    for(auto t: a) ext.push_back({t.first + 2*PI, t.second});

    long double best = 10;
    int Lidx = -1, Ridx = -1;
    for(int i=0;i<m;i++){
        long double w = ext[i + m - 1].first - ext[i].first;
        if(w < best){
            best = w;
            Lidx = ext[i].second;
            Ridx = ext[i + m - 1].second;
        }
    }

    const long double EPS = 1e-15L;
    if(best >= PI - 1e-12L){
        cout << "NO\n";
        return 0;
    }

    P A = d[Lidx], B = d[Ridx];
    ll cr = cross(A, B);

    P U;
    if(cr == 0){ 
        U = A;   
    }else{
        P nA = (cr > 0 ? rotCCW(A) : rotCW(A)); 
        P nB = (cr > 0 ? rotCW(B)  : rotCCW(B));
        U = P{ nA.x + nB.x, nA.y + nB.y };
    }

    P V = rotCCW(U);

    cout << "YES\n";
    cout << U.x << ' ' << U.y << "\n";
    cout << V.x << ' ' << V.y << "\n";
    return 0;
}
