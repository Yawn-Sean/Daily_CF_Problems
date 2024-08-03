import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.InputMismatchException;

public class cf946e_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        char[] cs = sc.ns().toCharArray();
        int n = cs.length;
        int[] cnt = new int[10];
        for (char value : cs) {
            cnt[value - '0']++;
        }
        for (int i = n-1; i >= 0; i--) {
            int w = cs[i] - '0';
            cnt[w]--;
            for (int j = w-1; j >=0; j--) {
                if(j==0 && i==0) continue;
                cnt[j]++;
                int c = 0;
                for (int k = 0; k < 10; k++) {
                    if(cnt[k]%2==1){
                        c++;
                    }
                }

                if(c<=(n-1-i)){
                    cs[i] = (char) (j+ '0');
                    out:for (int k = n-1; k >=i+1; k--) {
                        for (int l = 0; l<=9; l++) {
                            if(cnt[l] %2==1){
                                cs[k] = (char)(l + '0');
                                cnt[l]--;
                                continue out;
                            }
                        }
                        cs[k] = '9';
                    }
                    out.println(new String(cs));
                    return;
                }
                cnt[j]--;
            }
        }
        out.println("9".repeat(n-2));
    }
}
