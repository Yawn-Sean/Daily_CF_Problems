import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        String[] firstLine = br.readLine().split(" ");
        int n = Integer.parseInt(firstLine[0]);
        int m = Integer.parseInt(firstLine[1]);
        
        Map<String, Integer> mp = new HashMap<>();
        mp.put("?", 0);
        
        int[] flg = new int[n];
        int[][] vals = new int[n][m];
        int[][] ops = new int[n][3];
        
        for (int i = 1; i <= n; i++) {
            String s = br.readLine();
            mp.put(s, i);
            
            String[] parts = br.readLine().split(" ");
            s = parts[0];
            
            if (s.charAt(0) == '0' || s.charAt(0) == '1') {
                for (int j = 0; j < m; j++) {
                    vals[i-1][j] = s.charAt(j) - '0';
                }
            } else {
                flg[i-1] = 1;
                
                ops[i-1][0] = mp.get(s);
                s = parts[1];
                
                if (s.charAt(0) == 'X') ops[i-1][1] = 0;
                else if (s.charAt(0) == 'O') ops[i-1][1] = 1;
                else ops[i-1][1] = 2;
                
                s = parts[2];
                ops[i-1][2] = mp.get(s);
            }
        }
        
        StringBuilder ans0 = new StringBuilder();
        StringBuilder ans1 = new StringBuilder();
        
        for (int i = 0; i < m; i++) {
            int c0 = 0， c1 = 0;
            int[] cur0 = new int[n];
            int[] cur1 = new int[n];
            
            for (int j = 0; j < n; j++) {
                if (flg[j] == 1) {
                    int x = ops[j][0];
                    int o = ops[j][1];
                    int y = ops[j][2];
                    
                    int x0 = (x != 0 ? cur0[x-1] : 0);
                    int x1 = (x != 0 ? cur1[x-1] : 1);
                    
                    int y0 = (y != 0 ? cur0[y-1] : 0);
                    int y1 = (y != 0 ? cur1[y-1] : 1);
                    
                    if (o == 0) {
                        cur0[j] = x0 ^ y0;
                        cur1[j] = x1 ^ y1;
                    } else if (o == 1) {
                        cur0[j] = x0 | y0;
                        cur1[j] = x1 | y1;
                    } else {
                        cur0[j] = x0 & y0;
                        cur1[j] = x1 & y1;
                    }
                } else {
                    cur0[j] = vals[j][i];
                    cur1[j] = vals[j][i];
                }
                
                c0 += cur0[j];
                c1 += cur1[j];
            }
            
            if (c0 <= c1) ans0.append('0');
            else ans0.append('1');
            
            if (c0 >= c1) ans1.append('0');
            else ans1.append('1');
        }
        
        pw.println(ans0);
        pw.println(ans1);
        pw.flush();
    }
}
