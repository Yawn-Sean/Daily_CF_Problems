
public class cf865b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int tot = sc.ni();
        List<long[]> v1 = new ArrayList<>();
        List<long[]> v2 = new ArrayList<>();
        long ans = 0;
        long cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            long s = sc.ni();
            long a = sc.ni();
            long b = sc.ni();
            if(a>=b){
                ans += s*a;
                v1.add(new long[]{a-b,s});
                cnt1+=s;
            }else {
                ans += s*b;
                v2.add(new long[]{b-a,s});
                cnt2+=s;
            }
        }
        if((cnt1 + tot - 1)/ tot + (cnt2 + tot - 1)/ tot == (cnt1 + cnt2 + tot - 1) / tot){
            out.println(ans);
            return;
        }
        long res = (long)1e11;
        long toR1 = cnt1%tot;
        long c1 = 0;
        v1.sort(Comparator.comparingLong(a->a[0]));
        for(long[] l : v1){
            long c = Math.min(toR1, l[1]);
            c1 += c *l[0];
            toR1 -= c;
        }
        res = Math.min(res, c1);

        long toR2 = cnt2%tot;
        long c2 = 0;
        v2.sort(Comparator.comparingLong(a->a[0]));
        for(long[] l : v2){
            long c = Math.min(toR2, l[1]);
            c2 += c *l[0];
            toR2 -= c;
        }
        res = Math.min(res, c2);
        out.println(ans - res);
    }
}
