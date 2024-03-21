//对于某个字符串，我们可以知道它覆盖的区间，我们将所有区间排序。
//由于题目限制一定有解，所以按区间处理并不会冲突
//对于一个新的区间，我们要看看当前填到了哪一位，跟区间左端点取个max，这个位置放哪个字符，自然是当前位置减去左端点。
//由于放置位置单调递增，复杂度为 O(n) , 排序为 O(nlogn)
//故总复杂度为 O(nlogn)

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n;
    cin>>n;
    vector<array<int,3>> q;
    vector<string> s(n);
    int len=0;
    for(int i=0;i<n;i++){
        cin>>s[i];
        int k;
        cin>>k;
        while(k--){
            int l;
            cin>>l;
            q.pb({l,l+(int)s[i].size()-1,i});
            len=max(len,l+(int)s[i].size()-1);
        }
    }
    sort(all(q));
    vector<bool> st(len+1,0);
    vector<char> res(len+1,0);
    int la=1; 
    for(auto [l,r,id]:q){
        for(la=max(la,l);la<=r;la++){
            res[la]=s[id][la-l];
            st[la]=1;
        }
    }
    for(int i=1;i<=len;i++){
        if(st[i]) cout<<res[i];
        else cout<<'a';
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
