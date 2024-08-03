
ll n,b;
PLL a[N]; //b的质因数与幂
int cnt;


int main(){
    cin >> n >> b;
    for(ll i = 2;i <= b / i;i++){
        if(b % i == 0){
        ll s = 0;
            while(b % i == 0){
                b /= i;
                s++;
            }
            a[++cnt] = {i,s};
        }
    }
    if(b > 1)a[++cnt] = {b,1};
    ll ans = 1e18;
    for(int i = 1;i <= cnt;i++){
        ll as = 0; //质因数个数
        ll c = a[i].first; //质因数
        //要求10!有几个2，那么就10 / 2 + 10 / 4 + 10 / 8(有几个2的3次方2的2次方2)
        while(n >= c){
            as += n / c;
            if (1E18 / c < a[i].first) break; //最保险的防越界方式
            c *= a[i].first;
        }
        
        ans = min(ans,as / a[i].second); //能形成几个
        //比如b = 2 * 2* 3，那可以形成几个2*2和几个3,取最小的就好
    }
    cout << ans;


    
}
