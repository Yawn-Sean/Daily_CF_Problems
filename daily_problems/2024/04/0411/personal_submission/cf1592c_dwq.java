//提示3中的第三种情况，预留的两个连通块不做操作，两个连通块的和都为x，则两个连通块异或为0，剩余连通块合并为x也可以满足条件
import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String s =  "";
        String[] strs = null;
        int n = Integer.parseInt(in.readLine());
        int len = 0, k = 0, t = 0, i = 0, xorVal = 0;
        int x = 0, y = 0;
        int[] vals = null;
        while(--n > -1){
         
            s = in.readLine();
            strs = s.split(" ");
            len = Integer.parseInt(strs[0]);
            k = Integer.parseInt(strs[1]);
            vals = new int[len];
            s = in.readLine();
            strs = s.split(" ");
            xorVal = 0;
            for(i = 0; i < len; ++i){
                
                t = Integer.parseInt(strs[i]);
                xorVal ^= t;
                vals[i] =t;
            } 
            List<Integer>[] tree = new List[len];
            Arrays.setAll(tree, e->new ArrayList<Integer>());
            t = len - 1;
            while(--t > -1){
                
                s = in.readLine();
                strs = s.split(" ");
                x = Integer.parseInt(strs[0]) - 1;
                y = Integer.parseInt(strs[1]) - 1;
                tree[x].add(y);
                tree[y].add(x);
            }
            if(xorVal == 0) out.println("YES");
            else if(k == 2) out.println("NO");
            else{
                
                int[] pa = new int[len];
                Arrays.fill(pa, -1);
                int[] order = new int[len];
                i = 0;
                Deque<Integer> q = new ArrayDeque<>();
                q.offer(0);
                while(!q.isEmpty()){
                    
                    t = q.poll();
                    order[i] = t;
                    for(int nex : tree[t])
                        if(pa[t] != nex){
                            pa[nex] = t;
                            q.offer(nex);
                        }
                    ++i;
                }
                int[] dp = new int[len];
                for(i = len - 1; i > -1; --i){
                    
                    t = order[i];
                    if(vals[t] == xorVal){
                        
                        dp[t] += 1;
                        vals[t] = 0;
                    }
                    if(t > 0){
                        
                        dp[pa[t]] += dp[t];
                        vals[pa[t]] ^= vals[t];
                    }
                }
                //k范围从2开始 所以直接判断最后的可分割次数即可 等于2判断过了
                out.println(dp[0] > 1 ? "YES" : "NO");
            }
        }
        out.flush();
    }
}
