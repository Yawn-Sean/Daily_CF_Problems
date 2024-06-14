import java.io.*;
import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static char c1[], c2[];
    static int n, T, inf = (int)1e9;
    public static void main(String[] args) throws Exception {
        T = sc.nextInt();
        while(T --> 0){
             n = sc.nextInt();
             c1 = sc.next().toCharArray();
             c2 = sc.next().toCharArray();
             int s1 = 0, s2 = 0, d = 0;
             for(int i = 0; i < n; i ++){
                 if(c1[i] != c2[i]) d ++;
                 if(c1[i] == '1') s1 ++;
                 if(c2[i] == '1') s2 ++;
            }
            int ans = inf;        
            if(s1 == s2) ans = d;
            if(n - s1 + 1 == s2) ans = Math.min(ans, n - d);
            pw.println(ans == inf ? -1 : ans);
        }
        pw.flush();
        pw.close(); 
    }
}
