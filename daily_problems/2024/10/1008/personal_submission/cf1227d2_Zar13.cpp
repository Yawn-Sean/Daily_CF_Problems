#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
int a[N], ord[N], tr[N], ans[N];
int n;
struct node{
	int k, x, id;
	operator<(const node &b)const{
		return k<b.k;
	}
} op[N];
int lowbit(int x){
    return x & -x;
}
void add(int x, int c){
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}
int sum(int x){
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]; ord[i]=i;
	}
	stable_sort(ord+1, ord+1+n, [&](int i, int j) {return a[i] > a[j];});
	int m, k, x, id;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>k>>x;
		op[i]={k, x, i};
	}
	sort(op+1, op+1+m);
	int tk=0;
	for(int i=1;i<=m;i++){
		k=op[i].k, x=op[i].x, id=op[i].id;
		while(tk<k){
			add(ord[++tk], 1);
		}
		int l=0, r=n+1;
		while(l+1<r){
			int mid=l+r>>1;
			if(sum(mid)>=x) r=mid;
			else l=mid;
		}
		ans[id]=a[r];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
	return 0;
}
