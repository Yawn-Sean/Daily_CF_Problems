import java.util.Scanner;

//数论莫比乌斯反演
//整除分块  https://blog.csdn.net/qq_58207591/article/details/123883428
// r=n/(n/l)  res+= n/l *(r-l+1)  单值乘区间长度   这样对于大数据而言  时间复杂度为根号n
//DP  分成两种状态
public class d1_1561 {
    static int B = 300009;
    static long[] f = new long[B];
    static long n,mod;
    static long[] sum = new long[B];
    public static void main(String[] args)throws Exception{
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();
        mod = sc.nextLong();
        f[1]=1;sum[1]=1;
        for(int i=2;i<=n;i++){
            long last=0,res=0;
            for(long j=1;j<=i;j=last+1){
                long a=i/j;//key
                last = i/a;//分块的右边界
                res = res%mod + f[(int)a]*(last-j+1)%mod;
            }
            f[i] = f[i]%mod+res%mod;
            f[i] = f[i]%mod+sum[i-1]%mod;
            sum[i] = (sum[i-1]%mod + f[i]%mod +mod)%mod;//前缀和
        }
        System.out.println(f[(int)n]%mod);
    }
}
