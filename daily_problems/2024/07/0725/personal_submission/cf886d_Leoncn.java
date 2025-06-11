
public class cf886d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] pre = new int[26];
        int[] next = new int[26];
        Arrays.fill(pre, -1);
        Arrays.fill(next,-1);
        boolean[] cnt = new boolean[26];
        for (int i = 0; i < n; i++) {
            char[] cs = sc.ns().toCharArray();
            int c = cs.length;
            for (int j = 1; j <c; j++) {
                int a = cs[j-1] - 'a';
                int b = cs[j] - 'a';
                if(pre[b]!=-1 && pre[b]!= a){
                    out.println("NO");
                    return;
                }
                if(next[a] !=-1 && next[a] != b){
                    out.println("NO");
                    return;
                }
                next[a] = b;
                pre[b] = a;
                cnt[b] = true;
            }
            cnt[cs[0]-'a'] = true;
        }
        StringBuilder sb = new StringBuilder();
        boolean[] vis = new boolean[26];
        for (int i = 0; i < 26; i++){
            if(!vis[i] && pre[i] == -1 && cnt[i] ){
                int f = i;
                while (f!=-1){
                    sb.append((char) (f+'a'));
                    vis[f] = true;
                    f = next[f];
                }

            }
        }
        for (int i = 0; i < 26; i++) {
            if(!vis[i] && pre[i]!=-1){
                out.println("NO");
                return;
            }
        }
        out.println(sb);
    }

}
