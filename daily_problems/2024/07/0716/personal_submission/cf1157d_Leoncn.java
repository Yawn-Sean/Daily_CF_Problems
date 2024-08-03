    public static void solve() {
        long n = sc.ni();
        long k = sc.ni();
        long[] ans = new long[(int)k];
        n -= (k)*(k+1)/2;
        if(n<0){
            out.println("NO");
            return;
        }
        long x = n/k;
        long y = n%k;
        for (int i = 0; i < k; i++) {
            ans[i] = x+i+1;
        }
        long min = Math.min(y, k-2);
        for (int i = 0; i < min ; i++) {
            ans[(int)k-1-i] += 1;
            y--;
        }
        ans[(int)k-1]+=y;
        for (int i = 0; i < k-1; i++) {
            if(ans[i]*2< ans[i+1]){
                out.println("NO");
                return;
            }
        }
        out.println("YES");
        for (int i = 0; i < k; i++) {
            out.print(ans[i] + " ");
        }
    }
