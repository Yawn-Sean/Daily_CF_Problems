import java.io.*;
import java.util.*;

public class a{
    private static void michael(){
        FastReader sc=new FastReader();
        int n=sc.nextInt();
        Map<Integer,Integer> m=new HashMap<>();
        for(int i=0;i<n;i++){
            int a=sc.nextInt();
            if(m.get(a)==null){
                m.put(a,1);
            }else{
                int b=m.get(a);
                m.put(a,b+1);
            }
        }
        PrintWriter out=new PrintWriter(System.out);
        Set<Integer> key=m.keySet();
        PriorityQueue<pair> q = new PriorityQueue<>((p1, p2) -> p2.y - p1.y);
        for(int k:key){
            q.add(new pair(k,m.get(k)));
        }
        ArrayList<Integer> ans =new ArrayList<>();
        while(q.size()>=3){
            pair p1=q.poll();
            pair p2=q.poll();
            pair p3=q.poll();
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(p1.x);
            temp.add(p2.x);
            temp.add(p3.x);
            Collections.sort(temp, Collections.reverseOrder());  // 从大到小
            ans.add(temp.get(0));
            ans.add(temp.get(1));
            ans.add(temp.get(2));
            int v1=p1.y-1;
            int v2=p2.y-1;
            int v3=p3.y-1;
            if(v1>0) q.add(new pair(p1.x, v1));
            if(v2>0) q.add(new pair(p2.x, v2));
            if(v3>0) q.add(new pair(p3.x, v3));
        }
        out.println(ans.size()/3);
        for(int i=0;i<ans.size();i++){
            out.print(ans.get(i)+" ");
            if(i%3==2){
                out.println();
            }
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
    static class pair{
        int x;
        int y;
        public pair(int first,int second){
            x=first;
            y=second;
        }
        int getFirst(){
            return x;
        }
        int getSecond(){
            return y;
        }
    }
}
