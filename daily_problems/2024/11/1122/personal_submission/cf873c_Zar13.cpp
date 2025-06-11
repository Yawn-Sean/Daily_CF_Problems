#include<bits/stdc++.h>
using namespace std;
int n, m, k, a[105][105], sa[105], rc, rs;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sa[j]=sa[j-1];
			if(a[j][i]==1) sa[j]++;
		}
		if(sa[n]==0) continue;
		int maxt=0, maxj=0;
		for(int j=0;j+k<=n;j++){
			int t=sa[j+k]-sa[j];
			if(t>maxt){
				maxt=t;
				maxj=j;
			}
		}
		rc+=sa[maxj];
		rs+=maxt;
	}
	cout<<rs<<" "<<rc;
	return 0;
} 
