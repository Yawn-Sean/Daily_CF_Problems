int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,q;
	cin>>n>>m>>q;
	int maxn=(1<<(n));
	
	auto to_n=[&](string s){
		int ans=0;
		for(auto c:s){
			ans=((ans<<1)+int(c-'0'));
		}
		return ans;
	};

	vector<int>w(n), cnt(maxn);
	for(int i=n-1;i>=0;i--)cin>>w[i];
	for(int i=0;i<m;i++){
		string s;cin>>s;
		cnt[to_n(s)]++;
	}
	vector<vector<int>>a(1<<(n+1), vector<int>(101,0));
	

	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			if(!cnt[j])continue;
			int temp=0;
			for(int k=0;k<n;k++){
				if(((i>>k)&1)==((j>>k)&1)){
					temp+=w[k];
				}
			}
			if(temp>100)continue;
			a[i][temp]+=cnt[j];
		}

		for(int j=1;j<=100;j++){
			a[i][j]+=a[i][j-1];
		}
	}

	while(q--){
		string s;cin>>s;
		int k;cin>>k;
		int temp=to_n(s);
		cout<<a[temp][k]<<"\n";
	}
}
