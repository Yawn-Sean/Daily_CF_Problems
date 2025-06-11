void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    

    int lb=0, rb=n-1;
    while(lb+1<n && arr[lb+1]>arr[lb]) lb ++;
    while(rb-1>=0 && arr[rb-1]>arr[rb]) rb--;

    bool ans = 1;
    int l = 0, r = n-1;
    while(true) {
        if(arr[l] > arr[r]) {
            if((lb-l)&1) {
                if(r < rb || r < l) {
                    ans = !ans;
                    break;
                }
                r--;
                lb = min(lb, r);
            } else {
                break;
            }
        } else if(arr[l] < arr[r]) {
            if((r-rb)&1) {
                if(l > lb || r < l) {
                    ans = !ans;
                    break;
                }
                l++;
                rb = max(rb, l);
            } else {
                break;
            }
        } else {
            if(((r-rb)&1) && ((lb-l)&1)) {
                ans = !ans;
                break;
            } else {
                break;
            }
        }
        ans = !ans;
    }

    if(ans) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}
