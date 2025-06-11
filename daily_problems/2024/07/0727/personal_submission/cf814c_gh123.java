//https://codeforces.com/problemset/submission/814/272897747\
import java.util.Scanner;
public class C814 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String s=sc.next();
        char[]cs=s.toCharArray();
        int[][]cnt=new int[26][n+1];
        for (int i = 0; i < n; i++) {
            cnt[cs[i]-'a'][i+1]++;
        }
        
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <=n; j++) {
                cnt[i][j]+=cnt[i][j-1];
            }
        }
        int[][]res=new int[26][n+1];
        for (int i = 0; i < 26; i++) {
            for (int l = 0; l < n; l++) {
                for (int r = l; r < n; r++) {
                    int num=cnt[i][r+1]-cnt[i][l];
                    int rem=r-l+1-num;
                    res[i][rem]=Math.max(res[i][rem], r-l+1);
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <=n; j++) {
                res[i][j]=Math.max(res[i][j], res[i][j-1]);
            }
        }
        int q=sc.nextInt();
        while (q-->0) {
            int m=sc.nextInt();
            char c=sc.next().toCharArray()[0];
            System.out.println(res[c-'a'][m]);
        }
        sc.close();
    }
    //下面这个是超时的代码。。。还不太会把数据更新到二维数组里面。只是每次去查询处理然后就超时了。。。
    static int findmax(String s, int n, char c, int m){
        int max=Math.min(n, m);
        int l=0;
        int cnt=0;
        for (int i = 0; i < n; i++) {
            char in=s.charAt(i);
            if(in==c){
                max=Math.max(max, i-l+1);
            }else{
                cnt++;
            }
            while (cnt>m) {
                char out=s.charAt(l);
                if(out==c){
                    l++;
                }else{
                    cnt--;
                    l++;
                }
            }
            max=Math.max(max, i-l+1);
        }
        return max;
    }
}
