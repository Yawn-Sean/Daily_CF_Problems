import java.io.*;
import java.util.*;

public class a{
    private static void michael(){
        FastReader sc = new FastReader();
        int n,m,d;
        n=sc.nextInt();
        m=sc.nextInt();
        d=sc.nextInt();
        int []arr=new int[n];
        Integer []tmp=new Integer[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
            tmp[i]=i;
        }
        // Arrays.sort(tmp, (a,b)->Integer.compare(arr[a],arr[b]) );
        Arrays.sort(tmp,(a,b)->arr[a]-arr[b]);
        int []ans = new int [n];
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;

            boolean flag=true;
            for(int i=mid;i<n;i++){
                if(arr[tmp[i]]-arr[tmp[i-mid]]<=d){
                    flag=false;
                }
            }
            if(flag) r=mid-1;
            else l=mid+1;
        }
        PrintWriter out = new PrintWriter(System.out);
        out.println(l);
        for(int i=0;i<n;i++){
            ans[tmp[i]]=i%l+1;
        }
        for(int i=0;i<n;i++){
            out.print(ans[i]+" ");
        }
        out.close();
        
    }

    public static void main(String[] args) throws IOException {
        michael();
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
