import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s = in.readLine();
        String[] strs = s.split(" ");
        int n = Integer.parseInt(strs[0]);
        int m = Integer.parseInt(strs[1]);
        int[] row = new int[n];
        s = in.readLine();
        strs = s.split(" ");
        int i = -1;
        for(String e : strs) row[++i] = Integer.parseInt(e);
        i = -1;
        int[] col = new int[m];
        s = in.readLine();
        strs = s.split(" ");
        for(String e : strs) col[++i] = Integer.parseInt(e);
        
        // for(int e : row) out.print(e + " ");
        // out.println();
        // for(int e : col) out.print(e + " ");
        // out.println();
        int rowXor = 0, colXor = 0;
        for(int e : row) rowXor ^= e;
        for(int e : col) colXor ^= e;
        if(rowXor != colXor) out.println("NO");
        else{
            
            int[][] res = new int[n][m];
            res[0][0] = row[0];
            int t = 0;
            for(i = 1; i < m; ++i){
                
                t = col[i];
                res[0][i] ^= t;
                res[0][0] ^= t;
            }
            for(i = 1; i < n; ++i) res[i][0] = row[i];
            int j = 0;
            out.println("YES");
            for(i = 0; i < n; ++i){
                for(j = 0; j < m; ++j) out.print(res[i][j] + " ");
                out.println();
            }
            
        }
        out.flush();
    }
}
