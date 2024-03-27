//对于一个区间，我们要选择一个子序列，那么当我们枚举任意一个字符作为起点后
//后续一定是贪心选择最靠前，可以匹配的位置，那么我们把所有匹配链接起来后
//不难发现形成了一堆链条。
//那么对于每个询问我们要处理的就是区间内是否存在一个长度大于n的链条
//使用倍增处理起点为i的跳2^j步后的位置，然后判断区间最小值是否小于右端点即可。


const int N=200010,M=19;

struct ST{
	int f[N][M];
	void init(vector<int> &a,int n){
		for(int len=0;len<M;len++){
			for(int i=1;i+(1<<len)-1<=n;i++){
				if(!len) f[i][len]=a[i];
				else f[i][len]=min(f[i][len-1],f[i+(1<<len-1)][len-1]);
			}
		}
	}
	int query(int l,int r){
		int k=log(r-l+1)/log(2);
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n+1),ne(n+1,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) ne[a[i]]=a[(i+1)%n];
    vector<int> b(m+1);
    for(int i=1;i<=m;i++) cin>>b[i];
    vector<int> eg(m+1,0);
    vector<int> idx(n+1,0);
    for(int i=m;i>=1;i--){
        if(idx[ne[b[i]]]!=-1) eg[i]=idx[ne[b[i]]];
        idx[b[i]]=i;
    }

    vector<vector<int>> f(m+1,vector<int> (M,0));
    for(int j=0;j<M;j++){
        for(int i=1;i<=m;i++){
            if(!j) f[i][j]=eg[i];
            else f[i][j]=f[f[i][j-1]][j-1];
        }
    }
    vector<int> g(m+1);
    for(int i=1;i<=m;i++){
        int idx=i;
        for(int j=0;j<M;j++){
            if((n-1)>>j&1 and idx) idx=f[idx][j];
        }
        g[i]=(idx==0 ? 1e9 : idx);
    }
    st.init(g,m);
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        auto t=st.query(l,r);
        cout<<(t>=l and t<=r ? 1 : 0);
    }

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
