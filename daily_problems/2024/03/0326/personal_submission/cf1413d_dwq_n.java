import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        int tn = n * 2, i = -1;
        String[] strs = new String[tn];
        while(--tn > -1) strs[++i] = in.readLine();
        int num = n;
        tn = 2 * n;
        int[] stack = new int[n];
        int p = -1;
        int[] res = new int[n];
        int j = n, t = 0;
        char c = 0;
        i = tn - 1;
        String s = null;
        for(; i > -1; --i){
            
            s = strs[i];
            c = s.charAt(0);
            if(c == '+'){
              
              if(p == -1){
                  out.println("NO");
                  break;
              }else{
                  
                  res[--j] = stack[p];
                  --p;
              } 
            }else{
                
                t = Integer.parseInt(s.split(" ")[1]);
                if(p > -1 && stack[p] < t){
                    
                    out.println("NO");
                    break;
                }else stack[++p] = t;
            }
        }
        if(j == 0){
            out.println("YES");
            for(int e : res) out.print(e + " ");
        }
        out.flush();
    }
}
