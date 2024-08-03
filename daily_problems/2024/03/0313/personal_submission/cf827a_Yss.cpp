// https://codeforces.com/problemset/problem/827/A
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
typedef long long LL;
const int N = 2e6+10;

int p[N] , k , mx ,sz , l , la;
char ans[N] ;
string s ;

//int find(int x) {
//    return x == p[x] ? x : p[x] = find(p[x]);
//}

int find(int x){
	int v = x , fv = p[v];
	while(p[x]!=x) x = p[x] ;
	while(v!=x){
		p[v] = x ;
		v = fv ;
		fv = p[fv];
	} 
	return x ;
} 

void join(int i, int j){
	p[find(i)] = find(j) ; // i 的祖宗变成j 
}

inline void solve(){
	int n ; cin >> n ;
	for(int i=0;i<N;i++) p[i] = i ,ans[i] = 'a';
	// 并查集记录下一个未探索的点
	for(int i=1;i<=n;i++){
		cin >> s >> k ;
		sz = s.size() ;
		for(int j=1;j<=k;j++){
			cin >> l ;
			mx = max(mx,l+sz-1);//最大位置
			la = find(l) ;// 下一个没有被填满的位置
			for(int t=la;t<l+sz;t++){
				ans[t] = s[t-l];
				join(t,t+1);
			}
		}
	} 
	for(int i=1;i<=mx;i++){
		cout << ans[i];
	}
}
 
signed main(){
    IOS
    int _ = 1;
    while(_ --) solve();
    return 0;
}
