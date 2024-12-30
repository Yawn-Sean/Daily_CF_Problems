#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
//感觉就是统计正负交替的次数？ 也不尽然！ 有可能正的次数也可以用，减少换的次数
//感觉就是dp，然后我们dp关心的就是正负交接点
//我想先把正负区间统计一下，然后去dp
//但细想为了减少交换次数，必定在一段连续的正区间用冬天胎
//那么我只要贪心的每次给最短的正区间就好了
vector<int> cx;
priority_queue<int,vector<int>,greater<int>> d;
void solve(){
	int n,k;
	cin>>n>>k;
	int cnt=0,last=1e9;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x<0){
			cnt++;
			if(last!=1e9) d.push(i-last-1);
			last=i;
		}
	}
	if(cnt>k){
		cout<<-1;
		return;
	}
	k-=cnt;
	int ans=cnt*2;
	int max_ind=last;
	if(last==1e9) max_ind=0;
	while(d.size()){
		int v=d.top();
		d.pop();
		if(k>=v){
			k-=v;
			ans-=2;
		}
	}
	if(k>=n-max_ind) ans--;
	cout<<max(ans,0);
//	int cnt=0;
//	int ans=0;
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//		if(a[i]<0) cnt++;
//		if(i>0){
//			if((a[i]>=0&&a[i-1]<0)||(a[i]<0&&a[i-1]>=0)){
//				ans++;
//			}
//		}else{
//			if(a[i]<0) ans++;
//		}
//	}
//	cout<<ans<<endl;
//	if(cnt>k){
//		cout<<-1<<endl;
//		return;
//	}
//	//统计正区间长度
//	int left = k-cnt;
//	int cnt1;
//	for(int i=0;i<n;i++){
//		if(a[i]>=0){
//			cnt1=1;
//			while(a[++i]>=0&&i<n){
//				cnt1++;
//			}
//			cx.push_back(cnt1);
//		}
//	}
//	sort(cx.begin(),cx.end());
//	for(int i=0;i<cx.size();i++){
//		if(left>=cx[i]){
//			left-=cx[i];
//			ans-=2;
//		}else{
//			break;
//		}
//	}
//	cout<<ans<<endl;
}
int main(){
	int t;
//	cin>>t;
	t=1;
	while(t--){
		solve();
	}
}
