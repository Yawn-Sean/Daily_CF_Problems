//https://codeforces.com/problemset/submission/769/279883200
import java.util.Scanner;

public class D769 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int bit_dif=sc.nextInt();
        long[]cnt=new long[10001];
        for (int i = 0; i < n; i++) {
            cnt[sc.nextInt()]++;
        }
        long ans=0;
        for (int i = 0; i < 10001; i++) {
            if(cnt[i]==0) continue;
            for (int j = i; j < 10001; j++) {
                if(cnt[j]==0) continue;
                if(Integer.bitCount(i^j)==bit_dif){
                    if(i==j){
                        ans+=cnt[i]*(cnt[i]-1)/2;
                    }else{
                        ans+=cnt[i]*cnt[j];
                    }
                }
            }
        }
        System.out.println(ans);
        sc.close();
    }
}
