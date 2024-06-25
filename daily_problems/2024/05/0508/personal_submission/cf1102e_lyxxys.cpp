#include <bits/stdc++.h>
using namespace std;
using ll = long  long;
using Pii = pair<int,int>;
const int INF = 2e9;
const int P = 998244353;

int facts(int a, int b){
    int res = 1;
    while (b){
        if (b&1) res = 1ll*res*a%P;
        a = 1ll*a*a%P;
        b >>= 1;
    }
    return res;
}
void solve(){ 
    int n;
    cin >> n;
    vector <int> a(n+1);
    vector <Pii> chat;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i], chat.push_back({a[i], i});
    sort(chat.begin(), chat.end());

    vector <Pii> seg;

    for (int i = 0, last = -1; i < chat.size(); ++ i){  
        if (last == -1) last = chat[i].second;
        else if (chat[i].first != chat[i-1].first){
            seg.push_back({last, chat[i-1].second}), last = chat[i].second;

        }
        if (i == chat.size()-1) seg.push_back({last, chat[i].second});  //存入区间
    }

    sort(seg.begin(), seg.end());
    int k = 0;
    int start = 1;
    int r = -1;
    for (auto &it : seg){  //区间合并
        int lp = it.first, rp = it.second;
        if (lp > r) ++ k;
        r = max(r, rp);
    }
    cout << facts(2, k-1) << "\n";
}
