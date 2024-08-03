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
        s = in.readLine();
        strs = s.split(" ");
        int i = -1;
        Integer[] a = new Integer[n];
        for(String e : strs) a[++i] = Integer.parseInt(e);
        s = in.readLine();
        strs = s.split(" ");
        i = -1;
        Integer[] b = new Integer[m];
        for(String e : strs) b[++i] = Integer.parseInt(e);
        Arrays.sort(a);
        Arrays.sort(b, (x, y)->y - x);
        long res = 0;
        int min = m < n ? m : n;
        for(i = 0; i < min; ++i) if(b[i] > a[i]) res += (long)b[i] - a[i];
        out.println(res);
        out.flush();
    }
}
