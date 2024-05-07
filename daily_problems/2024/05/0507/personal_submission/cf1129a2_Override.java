import java.io.*;
import java.util.Arrays;

public class a21129 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static int n,m;
    static int[] to_move,cnt;

    public static void main(String[] args)throws Exception{
        n = nextInt();
        m = nextInt();
        to_move = new int[n];
        Arrays.fill(to_move,n);
        cnt = new int[n];
        Arrays.fill(cnt,0);
        for(int i=0;i<m;i++){
            int a = nextInt();
            a--;
            int b = nextInt();
            b--;
            //(b-a+n)%n表示在环上从a走到b所需步数
            to_move[a] = Math.min(to_move[a],(b-a+n)%n );
            cnt[a] += 1;
        }
        int[] ans = new int[n];
        for(int i=0;i<n;i++){//每个站点遍历
            for(int step=0;step<n;step++){
                int j = (i+step)%n;
                if(cnt[j]!=0){
                    ans[i] = Math.max(ans[i],step+(cnt[j]-1)*n+to_move[j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            pw.print(ans[i]+" ");
        }
        pw.println();
        pw.flush();
    }
}
