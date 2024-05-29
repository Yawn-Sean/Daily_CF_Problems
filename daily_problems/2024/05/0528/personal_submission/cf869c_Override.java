import java.io.*;

public class c869 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    static long mod = 998244353;
    static int N = 5005;
    static long[] fac = new long[N];
    static long[][] C = new long[5005][5005];
    static long calc(int x,int y){ //两个颜色的种数 Cax Cbx x！
        long ret =0;
        int mini = Math.min(x,y);
        for(int i=1;i<=mini;i++){
            ret = (ret+C[x][i]*C[y][i]%mod*fac[i]%mod)%mod;
        }
        return ret;
    }
    public static void main(String[] args)throws Exception{
        int a,b,c;
        a = nextInt();
        b = nextInt();
        c = nextInt();
        int maxn = Math.max(a,Math.max(b,c));
        fac[1] = 1; //暴力阶乘
        for(int i=2;i<=maxn;i++){
            fac[i] = (fac[i-1]*i)%mod;
        }
        C[0][0] = 1; // 杨辉三角求组合数  （数量很少的时候）
        for(int i=1;i<=maxn;i++){
            C[i][0]=C[i][i]=1;
            for(int j=1;j<i;j++){
                C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
            }
        }

        pw.println((calc(a,b)+1)*(calc(b,c)+1)%mod*(calc(c,a)+1)%mod);
        pw.flush();
    }
}
