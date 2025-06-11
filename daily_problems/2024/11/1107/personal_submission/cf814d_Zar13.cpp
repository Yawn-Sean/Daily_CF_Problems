#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const long double pi=acos(-1), eps=1e-9;
int x[N], y[N], r[N];
double p(int x1, int y1, int x2, int y2){
	return sqrt(pow(0LL+x1-x2, 2)+ pow(0LL+y1-y2, 2));
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>r[i];
	long long res=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			double d=p(x[i], y[i], x[j], y[j]);
			if(r[j]>=r[i]+d-eps) cnt++;
//			if(cnt>1) break;
		}
		if(cnt==0|| cnt%2){
			res+=1LL*r[i]*r[i];
//			cout<<"i:"<<i<<endl;
		}else{
			res-=1LL*r[i]*r[i];
		}
	}
	// cout<<"res:"<<res<<endl;
	cout<<fixed<<setprecision(15)<<pi*res;
	return 0;
}
