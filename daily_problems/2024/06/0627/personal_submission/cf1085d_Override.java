
//树的直径：任意两点之间的距离最大那一条
//贪心
import java.io.*;

public class d1085 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static int a;
    static int[] b = new int[100001];
    public static void main(String[] args)throws Exception{
        int n,s;
        n = nextInt();
        s = nextInt();
        for(int i=1;i<=n-1;i++){
            int x = nextInt();
            int y = nextInt();
            b[x]++;
            b[y]++;
        }
        for(int i=1;i<=n;i++) if(b[i]==1) a++; //叶子结点个数
        double aa = a, ss = s;
        double res = 2*ss/a;  //与叶子节点的赋平均值  其他赋0
        pw.println(String.format("%8f",res));
        pw.flush();
    }
}
