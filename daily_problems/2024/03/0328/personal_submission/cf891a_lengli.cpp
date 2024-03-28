

const int N=100010,M=20;

struct ST{
	int f[N][M];
	void init(vector<int> a,int n){
		for(int len=0;len<M;len++){
			for(int i=1;i+(1<<len)-1<=n;i++){
				if(!len) f[i][len]=a[i-1];
				else f[i][len]=gcd(f[i][len-1],f[i+(1<<len-1)][len-1]);
			}
		}
	}
	int query(int l,int r){
		int k=log(r-l+1)/log(2);
		return gcd(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int d=-1,cnt=0;
    for(auto &x:a) {
        cin>>x;
        if(x==1) cnt++;
        if(d==-1) d=x;
        else d=gcd(x,d);
    } 
    if(cnt){
        cout<<n-cnt<<endl;
        return;
    }
    if(d!=1){
        cout<<-1<<endl;
        return;
    }
    int l=1,r=n;
    st.init(a,n);
    auto check=[&](int x){
        for(int i=1,j=i+x-1;j<=n;i++,j++){
            if(st.query(i,j)==1) return 1;
        }
        return 0;
    };

    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<r+n-2<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
