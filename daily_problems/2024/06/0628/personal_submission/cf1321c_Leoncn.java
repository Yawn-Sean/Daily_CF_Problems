
public class cf1321c_Leoncn {
    int n = sc.ni();
    String s = sc.ns();
    int ans = 0;
    for (int i = 24; i >=0 ; i--) {
        char[] cs = s.toCharArray();
        boolean[] v = new boolean[cs.length];
        StringBuilder sb = new StringBuilder();
        for (int j = 0; j < cs.length; j++) {
            int t = cs[j] - 'a';
            if(t == i){
                int l = j-1;
                while (l>=0 && cs[l]-'a' == t+1 && !v[l]){
                    v[l--] = true;
                    ans++;
                }
                int r = j+1;
                while (r<cs.length && cs[r]-'a' == t+1 && !v[r]){
                    v[r++] = true;
                    ans++;
                }
            }
        }
        for (int j = 0; j < cs.length;j++) {
            if(!v[j]){
                sb.append(cs[j]);
            }
        }
        s = sb.toString();
    }
    out.println(ans);
}
