
import java.io.*;
import java.util.Arrays;

public class c1029 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    static int maxe=300005;
    static int[] lpl = new int[maxe];
    static int[] lpr = new int[maxe];
    static int[] rpl = new int[maxe];
    static int[] rpr = new int[maxe];
    static int[] l = new int[maxe];
    static int[] r = new int[maxe];

    public static void main(String[] args)throws Exception{
        int n = nextInt();
        Arrays.fill(lpr, Integer.MAX_VALUE);
        Arrays.fill(rpr, Integer.MAX_VALUE);
        for(int i=1;i<=n;i++){
            l[i] = nextInt();
            r[i] = nextInt();
            lpl[i] = Math.max(lpl[i-1],l[i]);
            lpr[i] = Math.min(lpr[i-1],r[i]);
        }
        for(int i=n;i>=1;i--){
            rpl[i] = Math.max(rpl[i+1],l[i]);
            rpr[i] = Math.min(rpr[i+1],r[i]);
        }
        int maxn =0;
        for(int i=1;i<=n;i++){
            maxn = Math.max(Math.min(lpr[i-1],rpr[i+1])-Math.max(lpl[i-1],rpl[i+1]),maxn);
        }
        pw.println(maxn);
        pw.flush();
    }

}
