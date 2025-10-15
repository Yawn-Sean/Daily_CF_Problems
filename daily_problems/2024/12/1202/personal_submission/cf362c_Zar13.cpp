#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n, a[N], sa[N][N], tr[N];
int lowbit(int x){
    return x&-x;
}
void add(int x, int c){
    for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=c;
}
int sum(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i)) res+=tr[i];
    return res;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i], a[i]++;
	int ans=0, res=-1, cnt;
	for(int i=1;i<=n;i++){
		vector<int> tmp;
		for(int j=i-1;j>0;j--){
			if(a[i]>a[j]) continue;
			ans++;
			tmp.push_back(a[j]);
			add(a[j], 1);
			int t=2*(sum(a[j]-1)-sum(a[i]))+1;
			if(t>res){
				res=t; cnt=1;
			}else if(t==res){
				cnt++;
			}
		}
		for(auto v:tmp) add(v, -1);
	}
	cout<<ans-res<<" "<<cnt;
	return 0;
}
