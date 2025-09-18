// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define i64 long long
#define db long double
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ull unsigned long long
#define vi vector<int>
using ll = long long;
using i128 = __int128;
//#define endl '\n'
#define vpii vector<pii>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define pqpii priority_queue<pii, vector<pii>, greater<pii>>
#define pqi priority_queue<int,vector<int>, greater<int>>
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define INF 1e18
#define exp 1e-12
using i128 = __int128;

istream &operator>>(istream &is, i128 &x) {
    string s;
    is >> s;
    bool neg = false;
    x = 0;
    for (char c : s) {
        if (c == '-')
            neg = true;
        else
            x = x * 10 + (c - '0');
    }
    if (neg)
        x = -x;
    return is;
}

ostream &operator<<(ostream &os, i128 x) {
    if (x == 0)
        os << 0;
    else {
        string s, t;
        if (x < 0)
            x = -x, t = "-";
        while (x)
            s.push_back('0' + x % 10), x /= 10;
        reverse(s.begin(), s.end());
        os << t << s;
    }
    return os;
}

i128 abs(i128 &x) { return x > 0 ? x : -x; }
int get(int x, int y, int x1, int y1) {
    int res = x * y1 -  y * x1;
    return res;
}

void slove(){
    int n;
    cin>>n;
    vi x(n+1),y(n+1),sumx(n+1),sumy(n+1);
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)sumx[i]=sumx[i-1]+x[i],sumy[i]=sumy[i-1]+y[i];
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=get(x[i]*i-sumx[i],y[i]*i-sumy[i],sumx[n]-sumx[i]-x[i]*(n-i),sumy[n]-sumy[i]-y[i]*(n-i));
    }
    int ans=0;
    for(int i=2;i<n;i++){
        ans+=get(x[i]-x[1],y[i]-y[1],x[i+1]-x[1],y[i+1]-y[1]);
    }
    cout<<sum*1.0/ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);
    int t=1;
    //cin>>t;
    while (t--) slove();
    return 0;
}
