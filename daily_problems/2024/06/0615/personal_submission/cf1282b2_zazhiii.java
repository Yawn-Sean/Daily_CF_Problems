import java.io.*;
import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static int T, n, m, k;
    static long a[], s[];
    public static void main(String[] args) throws Exception {
        T = sc.nextInt();
        while(T --> 0){
            n = sc.nextInt();
            m = sc.nextInt();
            k = sc.nextInt();
            a = new long[n + 1];
            s = new long[n + 1];
            for(int i = 1; i <= n; i ++) a[i] = sc.nextInt();
            Arrays.sort(a);
            int ans = 0;
            for(int i = 1; i <= n; i ++){
                if(i < k) s[i] = s[i - 1] + a[i];
                else s[i] = s[i - k] + a[i];
                if(s[i] <= m) ans = i;
            }
            pw.println(ans);
        }
        pw.flush();
        pw.close(); 
    }

}