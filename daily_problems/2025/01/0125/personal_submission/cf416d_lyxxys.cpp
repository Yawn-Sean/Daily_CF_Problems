void solve(){
    int n;
    cin >> n;
    vector <i64> A(n);
    for (auto &x : A){
        cin >> x;
    }
    /*
    算法流程：
        对于一个新的一段，任意确定最前面的两个非-1元素x,y.
        如果它们可以填成等差数列：
            判断 x 前面 能不能根据该公差构成等差数列，
                如果不可以，goto->a。
            如果可以，根据这个公差继续往后填数字，直到不能填为止，不能填的就是新的一段的开始。
        a：
            优先 把第 x 前后的 -1 消去，然后确定新的一段走到那里。
    */
    int res = 0;
    {
        int i = 0;
        while (i < n){
            res += 1;
            int last = i;
            while (i < n && A[i] == -1) i += 1; 

            int chose = -1;
            for (int j = i+1; j < n; ++ j){
                if (A[j] != -1){
                    chose = j;
                    break;
                }
            }
            if (chose == -1) break;

            int d1 = A[chose]-A[i], d2 = chose-i;
            if (abs(d1)%d2 == 0){
                int d = d1/d2;
                i64 cur = A[i];
                bool jg = 0;
                for (int j = i-1; j >= last; -- j){
                    cur -= d;
                    if (cur <= 0){
                        jg = 1;
                        break;
                    }
                }
                if (jg){    // 考虑两边位置不够的情况
                    i= chose;
                    continue;
                }

                i = chose;
                cur = A[chose];
                while (i+1 < n && cur+d > 0 && (A[i+1]==-1 || A[i+1]==cur+d)){
                    cur += d;
                    i += 1;
                }
                i += 1;
            } else {
                i = chose;
            }
        }
    }

    cout << res << "\n";
}
