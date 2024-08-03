//这题我们只需要联系到俩个字符串身上就好了
//每俩个字符串，记录他们每个的s和h并且顺便记录总的h数
//然后根据s1的h * s2的s数 和 s2的 h * s1的s数，这样算出这俩个字符串在前在后对总的子串数的影响
//然后根据这样排好序，最后我们算出结果就好了
//结果先让总的h数减去正在算的h数，再去相乘就好了
//


//核心代码：

bool cmp(PII a,PII b){
    return (ll)a.first * b.second > (ll)a.second * b.first;
}

int main(){
    cin >> n;
    ll ans = 0;
    ll h1 = 0; //所有的h数
    for(int i = 1;i <= n;i++){
        string s;
        cin >> s;
        ll a = 0,b = 0;
        for(int j = 0;j < s.length();j++){
            if(s[j] == 's')a++;
            else{
                ans += a; //这里出现b，那么自身内部字串前面都是sh
                h1++;
                b++;
            }
        }
        q[++cnt] = {a,b};
    }
    sort(q + 1,q + 1 + cnt,cmp);
    for(int i = 1;i <= cnt;i++){
        h1 -= q[i].second; 
        ans += (ll)h1*q[i].first;
    }
    cout << ans;
}
