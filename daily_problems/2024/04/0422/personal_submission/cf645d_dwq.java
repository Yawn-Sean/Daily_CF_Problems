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
        int[][] edges = new int[m][2];
        int l = 0, r = m + 1;
        int i = -1, t = m;
        while(--t > -1){
            
            s = in.readLine();
            strs = s.split(" ");
            edges[++i][0] = Integer.parseInt(strs[0]) - 1;
            edges[i][1] = Integer.parseInt(strs[1]) - 1;
        }
        int[] deg = new int[n];
        Deque<Integer> queue = new ArrayDeque<>();
        List<Integer>[] g = null;
        int mid = 0, x = 0, y = 0;
        boolean flag = false;
        while(l + 1 < r){
            
            mid = (l + r) >>> 1;
            deg = new int[n];
            flag = true;
            queue = new ArrayDeque<Integer>();
            g = new List[n];
            Arrays.setAll(g, e->new ArrayList<Integer>());
            for(i = 0; i < mid; ++i){
                
                x = edges[i][0];
                y = edges[i][1];
                g[x].add(y);
                ++deg[y];
            }
            for(i = 0; i < n; ++i) if(deg[i] == 0) queue.add(i);
            while(!queue.isEmpty()){
                
                if(queue.size() > 1){
                    flag = false;
                    break;
                }
                x = queue.poll();
                for(int nex : g[x])
                    if(--deg[nex] == 0)
                        queue.add(nex);
            }
            if(flag) r = mid;
            else l = mid;
        }
        
        out.println(r <= m ? r : -1);
        out.flush();
    }
}
