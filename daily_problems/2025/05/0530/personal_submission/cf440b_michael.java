package luogu;

import java.io.*;
import java.util.*;

public class a{
    private static void michael(){
        
    }
    public static void main(String[] args) throws IOException {
        FastReader sc=new FastReader();
        int n=sc.nextInt();
        long[]arr=new long[n+1];
        long sum=0;
        for(int i=1;i<=n;i++){
            arr[i]=sc.nextLong();
            sum+=arr[i];
        }
        long avg=(long)sum/n;
        long ans=0;
        for(int i=1;i<n;i++){
            arr[i]-=avg;
            arr[i]+=arr[i-1];
            ans+=Math.abs(arr[i]);
        }
        PrintWriter out=new PrintWriter(System.out);
        out.println(ans);
        out.close();
    }

    
     static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try { st = new StringTokenizer(br.readLine()); }
                catch (IOException e) { e.printStackTrace(); }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
        String nextLine() {
            String str = "";
            try { str = br.readLine(); }
            catch (IOException e) { e.printStackTrace(); }
            return str;
        }
    }
}


