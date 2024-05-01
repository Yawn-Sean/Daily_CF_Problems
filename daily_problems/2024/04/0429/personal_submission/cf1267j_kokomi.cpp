#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int a[N],b[N];
//屏幕大小肯定不超过比最小+1
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		a[i]=0;
	}
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[x]++;
	}
	int min1=1e9;
	int cnt=0;
	for(int i=0;i<=n;i++){
		if(a[i]){
			min1=min(min1,a[i]);
			b[cnt++]=a[i];
		}
	}
//	cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
//	cout<<cnt<<" --"<<endl;;
	min1++;
	int ans=0;
	for(int i=min1;i>=1;i--){
		ans=0;
		int ia=0;
		for(int j=0;j<cnt;j++){
			int tmp=(b[j]-1)/i+1;//上取整
			ans+=tmp;
			if((i-1)*tmp>b[j]){
				ia=1;
				break;
			}
		}
		if(!ia) break;
	}
	cout<<ans<<endl;
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}

}
/*
1
5
1 4 1 2 3
*/
