import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        int n = Integer.parseInt(in.readLine());
        int[] arr = new int[n];
        int i = -1, t = 0;
        String s = in.readLine();
        String[] strs = s.split(" ");
        for(String e : strs) arr[++i] = Integer.parseInt(e) - 1;
        
        List<Integer> flist = new ArrayList<>();
        for(i = 0; i < n; ++i){
            
            t = arr[i];
            if(arr[t] != t){
                
                out.println(-1);
                out.flush();
                return;
            }else if(t == i) flist.add(i);
        }
        int m = flist.size();
        int[] dict = new int[n];
        for(i = 0; i < m; ++i) dict[flist.get(i)] = i;
        int[] g = new int[n];
        int[] h = new int[m];
        for(i = 0; i < n; ++i){
            
            t = arr[i];
            g[i] = dict[t];
            if(t == i) h[g[i]] = i;
        }
        out.println(m);
        for(int e : g) out.print((e + 1) + " ");
        out.println();
        for(int e : h) out.print((e + 1) + " ");
        out.flush();
    }
}
