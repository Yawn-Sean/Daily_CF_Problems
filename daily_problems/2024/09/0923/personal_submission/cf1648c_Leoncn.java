public class cf1648c_Leoncn {
    static int mod = 998244353;
    static Combitation combitation;
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int[] g = sc.na(n);
        int[] arr = sc.na(m);
        int max = (int)2e5 + 2;
        int[] cnt = new int[max];
        Fenwick fenwick = new Fenwick(max);
        for(int a: g){
            cnt[a]++;
            fenwick.add(a, 1);
        }
        combitation = new Combitation(max, mod);
        long cur = Combitation.fac[n];
        for (int i = 0; i < max; i++) {
            if(cnt[i]>0){
                cur = cur * Combitation.facR[cnt[i]]%mod;
            }
        }
        long ans = 0;
        for (int i = 0; i < m; i++) {
            if(i>=n){
                ans += 1;
                break;
            }
            cur = Combitation.pow(n-i, mod-2, (long)mod) * cur  %mod;
            ans += cur * fenwick.pre(arr[i]-1)%mod;
            ans %= mod;
            if(cnt[arr[i]] == 0){
                break;
            }
            cur = cur * cnt[arr[i]] % mod;
            cnt[arr[i]] -= 1;
            fenwick.add(arr[i], -1);
        }

        out.println(ans%mod);

    }
}
