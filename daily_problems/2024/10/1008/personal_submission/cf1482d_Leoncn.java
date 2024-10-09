
public class cf1482d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int[] pre = new int[n];
        int[] suf = new int[n];
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            pre[i] = (i - 1 + n)%n;
            suf[i] = (i + 1)%n;
            dq.add(i);
        }
        boolean[] d = new boolean[n];
        List<Integer> ans = new ArrayList<>();
        while (dq.size()>0){
            int p = dq.poll();
            if(d[p]) continue;
            int next = suf[p];
            if(gcd(g[p], g[next])==1){
                ans.add(next);
                d[next] = true;
                pre[suf[next]] = p;
                suf[p] = suf[next];
                dq.add(p);
            }
        }
        out.print(ans.size() + " ");
        for(int a: ans){
            out.print( a+ 1 + " ");
        }
        out.println(" ");
    }
}
