using namespace std;
const int N = 200050, p = 998244353, INF = 2e9;

bool cmp(array<int,2> a, array<int,2> b){
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];  //优先按照第一维排序
}
void solve(){
    int n;
    cin >> n;
    vector <array<int,2>> a;
    for (int i = 1; i <= n; ++ i){
        array <int,2> tmp;
        cin >> tmp[1];  //第二维是x[i]
        if (i-tmp[1] >= 0){
            tmp[0] = i-tmp[1];  //第一维是i-x[i]
            a.push_back(tmp);
        }
    }
    sort(a.begin(), a.end(), cmp);  //第一维非严格升序
    vector <int> stk(N);
    int top = -1;
    
    for (int i = 0; i < a.size(); ++ i){
        if (~top && a[i][1] <= stk[top]){  //第二维严格升序
            int pos = lower_bound(stk.begin(), stk.begin()+1+top, a[i][1])-stk.begin();
            stk[pos] = a[i][1];
        }
        else stk[++ top] = a[i][1];
    }
    cout << top+1 << "\n";
}
