public class cf551b_Leoncn {
    public static void solve() {
        String g = sc.ns();
        String a = sc.ns();
        String b = sc.ns();
        long[] cnt = getC(g.toCharArray());
        long[] x =  getC(a.toCharArray());
        long[] y =  getC(b.toCharArray());
        int n = g.length();
        int left = 0, right = 0;
        long max = 0;
        out:for (int i = 0; i <=n; i++) {
            long[] v = new long[26];
            for (int j = 0; j < 26; j++) {
                v[j] = cnt[j] - x[j] * i;
                if(v[j]<0){
                    break out;
                }
            }
            int c = Integer.MAX_VALUE;
            for (int j = 0; j < 26; j++) {
                if(y[j] == 0) continue;
                c = Math.min((int)(v[j]/y[j]), c);
            }
            c = c == Integer.MAX_VALUE?0:c;
            if(i+c>max){
                max = i+c;
                left = i;
                right = c;
            }
        }
        StringBuilder ans = new StringBuilder(a.repeat(left));
        ans.append(b.repeat(right));
        for (int i = 0; i < 26; i++) {
            ans.append((((char) (i + 'a')) + "").repeat((int) (cnt[i] - x[i] * left - y[i] * right)));
        }
        out.println(ans);
    }

    private static long[] getC(char[] g){
        long[] ans = new long[26];
        for(char c: g){
            ans[c-'a']++;
        }
        return ans;
    }
}
