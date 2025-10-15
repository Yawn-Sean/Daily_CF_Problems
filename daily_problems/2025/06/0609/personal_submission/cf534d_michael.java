import java.io.*;
import java.util.*;

public class a{
    private static void michael(){
        FastReader sc = new FastReader();
        int n = sc.nextInt();
        Queue<Integer>[] arr = new LinkedList[n];
        for(int i=0;i<n;i++){
            arr[i] = new LinkedList<>();
        }
        for(int i=0;i<n;i++){
            int a = sc.nextInt();
            arr[a].add(i);
        }
        int l=0;
        List<Integer> ans = new ArrayList<>();
        boolean flag = true;
        for(int i=0;i<n;i++){
            while(true){
                if(arr[l].size()>0){
                    int tmp=(int)arr[l].poll();
                    ans.add(tmp);
                    break;
                }else{
                    if(l<3){
                        flag=false;
                        break;
                    }
                    l-=3;
                }
            }
            if(flag){
                l++;
            }else{
                break;
            }
        }
        PrintWriter out = new PrintWriter(System.out);
        if(flag){
            out.println("Possible");
            for(int i=0;i<ans.size();i++){
                out.print(ans.get(i)+1+" ");
            }
        }else{
            out.println("Impossible");
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
