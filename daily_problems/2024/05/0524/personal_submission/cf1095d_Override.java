import java.io.*;

public class d1095 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static int N = 300005;
    static int n;
    static int[] a = new int[N];
    static int[] b = new int[N];
    static boolean suf(int u,int v){
        return a[u] == v || b[u] == v;
    }
    public static void main(String[] args) throws Exception{
        n = nextInt();
        if( n==3){
            pw.print("1 2 3\n");
            pw.flush();
            return;
        }
        for(int i=1;i<=n;i++){
            a[i] = nextInt();
            b[i] = nextInt();
        }
        int p =1;
        for(int i=1;i<=n;i++){
            pw.print(p+" ");  //不能是‘ ’
            if(suf(a[p],b[p])) p = a[p];
            else p=b[p];
        }
        pw.flush();
    }
}
