package cf;

import java.io.*;

public class d765 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    static int maxe = 100005;
    static int n,to;
    static int[] g=new int[maxe];
    static int[] h=new int[maxe];
    public static void main(String[] args)throws Exception{
        n = nextInt();
        for(int i=1;i<=n;i++){
            int x = nextInt();
            if(g[x] == 0){
                g[x] = ++to;
                h[to] = x;
                g[i] = to;
            }else if(h[g[x]] == x){
                g[i] = g[x];
            }else{
                pw.println(-1);
                pw.flush();
                return ;
            }
        }
        pw.println(to);
        for(int i=1;i<=n;i++){
            pw.print(g[i]+" ");
        }
        pw.println();
        for(int i=1;i<=to;i++){
            pw.print(h[i]+" ");
        }
        pw.println();
        pw.flush();
    }
}
