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
        
        int[] candy = new int[n];
        int[] dis = new int[n];
        Arrays.fill(dis, n);
        int x = 0, y = 0;
        while(--m > -1){
            
            s = in.readLine();
            strs = s.split(" ");
            x = Integer.parseInt(strs[0]) - 1;
            y = Integer.parseInt(strs[1]) - 1;
            candy[x] += 1;
            dis[x] = Min(dis[x], (y - x + n) % n);
        }
        int[] res = new int[n];
        int step = 0;
        for(x = 0; x < n; ++x){
            
            for(step = 0; step < n; ++step){
                
                y = (x + step) % n;
                if(candy[y] > 0)
                    res[x] = Max(res[x], step + (candy[y] - 1) * n + dis[y]);
            }
        }
        for(int e : res) out.print(e + " ");
        out.flush();
    }
    public static int Max(int a, int b){ return a > b ? a : b; }
    public static int Min(int a, int b){ return a < b ? a : b; }
}
