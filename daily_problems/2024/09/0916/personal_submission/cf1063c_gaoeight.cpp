int main(void){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;cin >> n;
    cout << "0 0" << endl;
    string d; cin >> d;
    n--;
    int l = 0, r = INF;
    while(n--){
        int mid = (r + l) / 2;
        cout << mid << ' ' << mid << endl;
        string temp; cin >> temp;
        if(temp == d) l = mid;
        else r = mid;
    }
    cout << l << ' ' << r << ' ' << r << ' ' << l << endl;
}
