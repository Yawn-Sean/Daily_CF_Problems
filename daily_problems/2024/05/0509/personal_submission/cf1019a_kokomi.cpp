#include<bits/stdc++.h>
using namespace std;
const int N = 3e3+10;
//尽可能买价值小的票
//但不是总是最优的
//一种贪心思路：枚举自己要x张选票，然后先买其它>x张票（从小到大买），然后在从所有票中由小到大
typedef long long ll;
vector<int> a[N];
	int n,m;
ll check(int x){
	ll sum=0;
	int tot=0;
	vector<int> tmp;
	for(int i=1;i<=m;i++){
		int j=0,k=a[i].size();
		while(k>=x){
			sum+=a[i][j++];
			k--,tot++;
		}
		while(j<a[i].size()){
			tmp.push_back(a[i][j++]);
		}
		
	}
	sort(tmp.begin(),tmp.end());
	for(int i=0;i<tmp.size();i++){
		if(tot>=x){
			break;
		}
		sum+=tmp[i];
		tot++;
	}
	return sum;
}
int main(){

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int p,c;
		cin>>p>>c;
		a[p].push_back(c);
	}
	for(int i=1;i<=m;i++){
		sort(a[i].begin(),a[i].end());
	}
	for(int i=0;i<a[1].size();i++){
		a[1][i]=0;
	}
	int l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)<check(mid+1)) r=mid-1;
		else l=mid+1;
	}
	cout<<check(l);
	
}