import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        int[] nums = new int[n];
        int[] times = new int[n];
        String s = in.readLine();
        String[] strs = s.split(" ");
        int i = -1;
        for(String e : strs) nums[++i] = Integer.parseInt(e);
        i = -1;
        s = in.readLine();
        strs = s.split(" ");
        for(String e : strs) times[++i] = Integer.parseInt(e);
        
        Integer[] idxs = new Integer[n];
        for(i = 0; i < n; ++i) idxs[i] = i;
        Arrays.sort(idxs, (a, b)->nums[a] - nums[b]);
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int t = 0, num = 0, pre = 0;
        long total = 0, res = 0;
        for(int idx : idxs){
            
            num = nums[idx];
            t = num - pre;
            while(--t > -1){
                
                if(pq.isEmpty()) break;
                total += pq.poll();
                res += total;
            }
            pq.offer(-times[idx]);
            total += times[idx];
            pre = num;
        }
        
        while(!pq.isEmpty()){
            
            total += pq.poll();
            res += total;
        }
        out.println(res);
        out.flush();
    }
}
