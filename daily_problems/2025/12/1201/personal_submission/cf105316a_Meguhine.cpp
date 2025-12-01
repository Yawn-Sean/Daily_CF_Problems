int main(){
	int n; cin>>n;
	vector<int>a(n+1);
	vector<LL>s(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	const LL lim=(s[n]-1)/2;
	vector<Z>dp(n+1),sdp(n+1);
	dp[0]=sdp[0]=raw(1);
	auto get1=[&](int l,int r)->LL{
		return s[r]-s[l-1];
	};
	auto get2=[&](int l,int r)->Z{
		return sdp[r]-(l?sdp[l-1]:raw(0));
	};
	for(int i=1,j=1;i<=n;++i){
		while(get1(j,i)>lim) ++j;
		dp[i]=get2(j-1,i-1);
		sdp[i]=sdp[i-1]+dp[i];
	}
	cout<<dp[n].val();
	return 0;
}
