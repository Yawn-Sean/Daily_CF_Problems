import java.util.*;
import java.io.*;
public class Test{
    
    public static void main(String[] args) throws Exception{
        
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int n = Integer.parseInt(in.readLine());
        int[] arr = new int[n];
        String s = in.readLine();
        String[] strs = s.split(" ");
        int i = -1, t = 0;
        for(String e : strs) arr[++i] = Integer.parseInt(e);
        arr[0] = 1;
        arr[n - 1] = 1;
        for(i = 1; i < n; ++i) arr[i] = Min(arr[i], arr[i - 1] + 1);
        for(i = n - 2; i > 0; --i) arr[i] = Min(arr[i], arr[i + 1] + 1);
       
        int res = 0;
        for(int e : arr) res = Max(res, e);
        out.println(res);
        out.flush();
    }
    public static int Max(int a, int b){ return a > b ? a : b; }
    public static int Min(int a, int b){ return a < b ? a : b; }
}
