
public class cf1290b_Leoncn {
    public static void solve() {
        char[] cs = sc.ns().toCharArray();
        int q = sc.ni();
        int n = cs.length;
        int[][] cnt = new int[n+1][26];
        for (int i = 0; i < n; i++) {
            cnt[i+1] = Arrays.copyOf(cnt[i], 26);
            cnt[i+1][cs[i]-'a']++;
        }

        while (q-->0){
            int a = sc.ni()-1;
            int b = sc.ni()-1;
            if(a == b){
                out.println("Yes");
            }else if(cs[a] != cs[b]){
                out.println("Yes");
            }else{
                int c = 0;
                for (int i = 0; i < 26; i++) {
                    c += Math.min(cnt[b+1][i] - cnt[a][i],1);
                }
                if(c>=3){
                    out.println("Yes");
                }else {
                    out.println("No");
                }
            }
        }
    }
}
