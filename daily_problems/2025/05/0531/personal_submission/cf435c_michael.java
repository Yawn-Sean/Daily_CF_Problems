import java.io.*;
import java.util.*;

public class a{
    private static void michael(){
        FastReader sc=new FastReader();
        int n=sc.nextInt();
        int[]card=new int[n+1];
        int row=0;
        int col=0;
        for(int i=1;i<=n;i++){
            card[i]=sc.nextInt();
            col+=card[i];
        }
        int mx=0;
        int mn=Integer.MAX_VALUE;
        for(int i=1;i<=n;i++){
            card[i]=(i&1)==0?card[i-1]+card[i]:card[i-1]-card[i];
            mx=Math.max(mx,card[i]);
            mn=Math.min(mn,card[i]);
        }
        for(int i=0;i<=n;i++){
            card[i]-=mn;
        }
        row=mx-mn;
        char[][]ans=new char[row][col];
        for(char[]t:ans){
            Arrays.fill(t,' ');
        }
        int cur=0;
        for(int i=0;i<n;i++){
            int l=card[i],r=card[i+1];
            if(r-l>0){
                for(int j=0;j<r-l;j++){
                    ans[l+j][cur+j]='\\';
                }
                cur+=r-l;
            }else{
                for(int j=0;j<l-r;j++){
                    ans[l-j-1][cur+j]='/';
                }
                cur+=l-r;
            }
        }
        PrintWriter out=new PrintWriter(System.out);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                out.print(ans[i][j]);
            }
            out.println();
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
