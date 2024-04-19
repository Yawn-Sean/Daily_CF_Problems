import java.util.*;
import java.io.*;
public class Test{
    
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s = in.readLine();
        String[] strs = s.split(" ");
        int n = Integer.parseInt(strs[0]), m = Integer.parseInt(strs[1]);
        int[] res = new int[n];
        int[][] g = new int[n][n];
        int i = 0, x = 0, y = 0;
        for(; i < n; ++i){
            
            Arrays.fill(g[i], 1);
            g[i][i] = 0;
        } 
        while(--m > -1){
            
            s = in.readLine();
            strs = s.split(" ");
            x = Integer.parseInt(strs[0]) - 1;
            y = Integer.parseInt(strs[1]) - 1;
            g[x][y] = 0;
            g[y][x] = 0;
        }
        
        Arrays.fill(res, 1);
        for(i = 0; i < n; ++i){
            
            x = 0;
            for(int e : g[i]) x += e;
            if(res[i] == 1 && x > 0){
                
                Deque<Integer> q = new ArrayDeque<>();
                q.offer(i);
                res[i] = 0; //先确定一个点
                while(!q.isEmpty()){
                    
                    x = q.poll();
                    for(y = x; y < n; ++y)
                        if(g[x][y] > 0 && res[y] == 1){
                          res[y] = res[x] ^ 2;
                          q.offer(y);
                        }
                }
            }
        }
        for(x = 0; x < n; ++x)
            for(y = 0; y < x; ++y)
                if(((res[x] ^ res[y]) == 2 && g[x][y] == 0) ||
                   ((res[x] ^ res[y]) != 2 && g[x][y] == 1)){
                        out.println("No");
                        out.flush();
                        return;
                   }
                    
        out.println("Yes");
        for(int e : res) out.print((char)(97 + e));
        out.flush();
    }

}
