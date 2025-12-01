struct Node{
	int v,x,y;
	friend bool operator <(const Node& x,const Node& y){
		return x.v>y.v;
	}
};
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void solve(){
	int n,m;
	cin>>n>>m;
	vector a(n,vector<int>(m));
	vector f(n,vector<bool>(m,0));
	priority_queue<Node>q;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>a[i][j];
			q.emplace(a[i][j],i,j);
		}
	}
	LL s=0;
	while(q.size()){
		auto [v,x,y]=q.top();
		q.pop();
		f[x][y]=1;
		int mn=-1;
		for(int i=0;i<4;++i){
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(nx<0 || ny<0 || nx==n || ny==m) continue;
			if(!f[nx][ny]) continue;
			updmx(mn,a[nx][ny]);
		}
		dbg(x,y,a[x][y],mn+1);
		s+=v-(a[x][y]=mn+1);
	}
	if(s&1) cout<<"YES\n";
	else cout<<"NO\n";
}
