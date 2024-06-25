import java.io.*;
import java.util.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s = in.readLine();
        String[] strs = s.split(" ");
        int[] nums = new int[4];
        int i = -1;
        for(String e : strs) nums[++i] = Integer.parseInt(e);
        
        char[] cs = {'A', 'B', 'C', 'D'};
        char[][] res = new char[50][50];
        int j = 0;
        out.println("50 50");
        for(i = 0; i < 50; ++i)
            for(j = 0; j < 50; ++j)
                res[i][j] = cs[(i > 24 ? 1 : 0) * 2 + (j > 24 ? 1 : 0)];
        
        int div = 0, mod = 0;
        for(int k = 0; k < 4; ++k){
            
            div = (k + 1) % 4 / 2;
            mod = (k + 1) % 4 % 2;
            for(i = 1; i < 21; i += 2)
                for(j = 1; j < 21; j += 2){
                    
                    if(--nums[k] > 0){
                        
                        res[i + div * 25][j + mod * 25] = cs[k];
                    }
                }
        }
        
        for(i = 0; i < 50; ++i){
                
            for(char e : res[i]) out.print(e);
            out.println();
        }
        out.flush();
    }
}
