#include<bits/stdc++.h>
using namespace std;
#pragma GCC optmize(2)
#define Endproce()
#define Debug(...)
#define llng long long
#define int llng
template<typename T>
T lowbit(T a){return a&(-a);}
template<typename T>
using vec = std::vector<T> ;
typedef long long ll;
const int mod=2;
void mian() {
    int n,m,k;
    cin>>n>>m>>k;
    vec<vec<pair<int,int>>>gr(n+k+1);
    for(int i=1;i<=m;i++){
        int u,v,vel;
        cin>>u>>v>>vel;
        gr[u].push_back({v,vel});
        gr[v].push_back({u,vel});
    }
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        while(t--){
            int u,vel;
            cin>>u>>vel;
            gr[u+n].push_back({i,0});
            gr[i].push_back({u+n,vel});
        }
    }
    priority_queue<pair<int,int>>pq;
    pq.push({0,1});
    vec<int>bl(n+k+1,-1e18);
    bl[1]=0;
    bl[1]=0;
    while(pq.empty()==0){
        int nw=pq.top().second,vel=pq.top().first;
        pq.pop();
        if(nw==n)break;
        for(int i=0;i<gr[nw].size();i++){
            int to=gr[nw][i].first;
            if(bl[to]>=vel-gr[nw][i].second)continue;
            bl[to]=vel-gr[nw][i].second;
            pq.push({vel-gr[nw][i].second,to});
        }
    }
    cout<<-bl[n]<<"\n";
}
#undef int
int main ()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios::sync_with_stdio(false);
	std::cin.exceptions(std::ios::badbit|std::ios::failbit);
	std::cout << std::fixed << std::setprecision(4) ;
	int T = 1 ;
	//cin>>T ;
	while(T--)
	{
		
		mian();
	}
	
	std::cout.flush() ;
	return 0 ;
}