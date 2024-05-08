//题目给了两种令人头大的函数映射关系
//我们一个个来看，首先观察一下 h[g[x]] = f[x]
//我们把 g[x] 看作一个数字(因为给个x会得到一个g[x]),下面用 t 代表一下吧
//然后我们会发现 i 从 1 到 n ，枚举的过程中总是满足 f[i]=h[t] ，t是谁先不考虑。
//这说明 h 数组的元素要包含 f 数组中的元素

//那我们按从小到大，将 f 中的元素去重并排序得到数组 h 
//现在再来看式子 f[i]=h[t] 由于 h 中的元素没有重复则我们需要一种映射规则
//使得对于每个相同 f[i] 都可以准确映射到同一个 t 上
//这个似乎就是我们要求的 g[i] ，即 h[g[i]]=f[i] ,(g[i]=t)

//现在我们来看看这个式子 g[h[i]]=i 。
//这个映射关系告诉我们，一个 i 经过两次变换后，依然是 i , 并且第一次变换的映射规则就是数组 h
//我们不难发现，只要能满足映射关系，h 数组中的元素顺序并不重要，
//因为不管 h[i] 是多少，我们让 g[h[i]]=i，即可满足映射关系 
//那现在我们便可以计算出 g 数组的值了

//在计算的时候，我们不要忘记 h[g[i]]=f[i] ,(g[i]=t) 。
//这个式子说明，f[i] 和 f[j] 相同，那么 g[i] 和 g[j] 要映射到同一个 t 。
//所以我们在计算 g 时，如果 f[i] 对应的 g 被计算过，直接赋值即可。

//最后用映射关系检验一遍合法性就可以了。

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
    vector<int> f(n+1),g(n+1,-1),idx(n+1,-1);
    vector<int> a;
    for(int i=1;i<=n;i++){
        cin>>f[i];
        a.pb(f[i]);
    }
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    int m=a.size();
    vector<int> h(m+1);
    for(int i=1;i<=m;i++) {
        h[i]=a[i-1];
        if(idx[f[h[i]]]==-1){
            g[h[i]]=i;
            idx[f[h[i]]]=i;
        }else g[h[i]]=idx[f[h[i]]];
    }
    for(int i=1;i<=n;i++){
        g[i]=idx[f[i]];
    }
    bool flag=1;
    for(int i=1;i<=n and flag;i++){
        if(h[g[i]]!=f[i]) flag=0;
    }
    for(int i=1;i<=m and flag;i++){
        if(g[h[i]]!=i) flag=0;
    }
    if(!flag) cout<<-1;
    else{
        cout<<m<<endl;
        for(int i=1;i<=n;i++) cout<<g[i]<<" ";
        cout<<endl;
        for(int i=1;i<=m;i++) cout<<h[i]<<" ";
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
