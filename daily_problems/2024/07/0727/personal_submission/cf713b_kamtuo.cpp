/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-27 12:41 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

int t1, t2, b1, b2, l1, l2, r1, r2;
int n;
int l, r;
int now;

void find() {
    l = 1, r = n; 
    while (l < r) {
        int mid = l + r >> 1;
        cout << "? " << 1 << ' ' << 1 << ' ' << mid << ' ' << n << endl; 
        cin >> now;
        if (1 <= b1 && 1 <= l1 && mid >= t1 && n >= r1) now --;
        if (now >= 1) r = mid;
        else l = mid + 1;
    }
    t2 = r;
    l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        cout << "? " << 1 << ' ' << 1 << ' ' << n << ' ' << mid << endl; 
        cin >> now;
        if (1 <= b1 && 1 <= l1 && n >= t1 && mid >= r1) now --;
        if (now >= 1) r = mid;
        else l = mid + 1;
    }
    r2 = r;
    l = 1, r = t2;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        cout << "? " << mid << ' ' << 1 << ' ' << t2 << ' ' << r2 << endl;
        cin >> now;
        if (mid <= b1 && 1 <= l1 && t2 >= t1 && r2 >= r1) now --;
        // cout << now << endl;
        if (now < 1) r = mid - 1;
        else l = mid;
    }
    b2 = l;
    l = 1, r = r2;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        cout << "? " << 1 << ' ' << mid << ' ' << t2 << ' ' << r2 << endl;
        cin >> now;
        if (1 <= b1 && mid <= l1 && t2 >= t1 && r2 >= r1) now --;
        if (now < 1) r = mid - 1;
        else l = mid;
    }
    l2 = l;
}

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    l = 1, r = n; 
    while (l < r) {
        int mid = l + r >> 1;
        cout << "? " << 1 << ' ' << 1 << ' ' << mid << ' ' << n << endl; 
        cin >> now;
        if (now >= 1) r = mid;
        else l = mid + 1;
    }
    t1 = r;
    l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        cout << "? " << 1 << ' ' << 1 << ' ' << t1 << ' ' << mid << endl; 
        cin >> now;
        if (now >= 1) r = mid;
        else l = mid + 1;
    }
    r1 = r;
    l = 1, r = t1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        cout << "? " << mid << ' ' << 1 << ' ' << t1 << ' ' << r1 << endl;
        cin >> now;
        if (now < 1) r = mid - 1;
        else l = mid;
    }
    b1 = l;
    l = 1, r = r1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        cout << "? " << 1 << ' ' << mid << ' ' << t1 << ' ' << r1 << endl;
        cin >> now;
        if (now < 1) r = mid - 1;
        else l = mid;
    }
    l1 = l;
    find();
    cout << "! ";
    cout << b1 << ' ' << l1 << ' ' << t1 << ' ' << r1;
    cout << ' ';
    cout << b2 << ' ' << l2 << ' ' << t2 << ' ' << r2;
    // cout << "! " << b1 << ' ' << l1 << ' ' << t1 << ' ' << r1 << ' ';
    // cout << b2 << ' ' << l2 << ' ' << t2 << ' ' << r2 << endl;
    return 0;
}

/*

*/
