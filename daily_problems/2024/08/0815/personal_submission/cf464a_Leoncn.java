
public class cf464a_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int p = sc.ni();
        char[] cs =sc.ns().toCharArray();
        for (int i = n-1; i >=0 ; i--) {
            int c = cs[i] -'a';
            for (int j = c+1; j <p ; j++) {
                if((i-1>=0 && cs[i-1]-'a' == j) ||
                   (i-2>=0 && cs[i-2]-'a' == j)){

                }else {
                    cs[i] = (char) (j+'a');
                    out:for (int k = i+1; k < n; k++) {
                        for (int l = 0; l < p; l++) {
                            if((k-1>=0 && cs[k-1]-'a' == l) ||
                                    (k-2>=0 && cs[k-2]-'a' == l)){

                            }else {
                                cs[k] = (char) (l + 'a');
                                continue out;
                            }
                        }
                    }
                    out.println(new String(cs));
                    return;
                }
            }
        }
        out.println("NO");
    }
}
