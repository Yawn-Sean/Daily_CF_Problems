import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class cf106351k {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int M=100000;
        List<List<Integer>>factors=new ArrayList<>(M+1);
        for (int i = 0; i <=M; i++) {
            factors.add(new ArrayList<>());
        }
        for (int i = 1; i <=M; i++) {
            for (int j = i; j <=M; j+=i) {
                factors.get(j).add(i);
            }
        }
        int n=sc.nextInt(),x=sc.nextInt(),y=sc.nextInt();
        int[]cnt=new int[M+1];
        while (n-->0) {
            int val=sc.nextInt();
            cnt[val]++;
        }
        long ans=0;
        for (int i = x; i <=y; i++) {
            ans+=(long)cnt[i]*(cnt[i]-1)/2;
            List<Integer>cur=factors.get(i);
            int fac_cnt=cur.size();
            for (int j = 0; j < fac_cnt; j++) {
                for (int k = 0; k < j; k++) {
                    int p=cur.get(j);
                    int q=cur.get(k);
                    int gcd=gcd(p, q);
                    if(gcd>=x&&(long)p*q/gcd==i){
                        ans+=(long)cnt[p]*cnt[q];
                    }
                }
            }
        }
        System.out.println(ans);
        sc.close();
    }     
    static int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }  

}
