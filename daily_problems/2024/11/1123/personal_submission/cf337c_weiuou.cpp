#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+9;

long long qmi(long long a,long long b){
  a %= mod;
  long long res = 1;
  while(b>0){
    if(b&1)res = res * a % mod;
    a = a * a % mod;
    b>>=1;
  }
  return res;
}

void solve(){
  int n,m,k;
  cin>>n>>m>>k;
  int fail = n-m;
  if(m/(k-1)<=fail){
    cout<<m<<endl;
    return;
  }
  //2k 6k 14k 30k
  //4-2 8-2 16-2 32-2
  long long res = m-fail*(k-1);
  long long time = res / k;
  long long ans = qmi(2,time + 1);
  ans-=2;
  ans = ans*k+res%k+fail*(k-1);
  cout<<((ans%mod)+mod)%mod<<endl;
}
int main(){
  int t = 1;
  //cin>>t;
  while(t--)solve();
  return 0;
}

