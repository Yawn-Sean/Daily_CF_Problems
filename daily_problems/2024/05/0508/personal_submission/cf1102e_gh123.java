https://codeforces.com/problemset/submission/1102/259945903
import java.util.HashSet;
import java.util.Scanner;

public class E1102 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
        int[]c=new int[n+1];
        HashSet<Integer>set=new HashSet<>() ;
        for (int i = 0; i < n; i++) {
            if(!set.contains(a[i])){
                c[i]++;
                set.add(a[i]);
            }
        }
        set.clear();
        for (int i = n-1; i >=0; i--) {
            if(!set.contains(a[i])){
                c[i]--;
                set.add(a[i]);
            }
        }
        long ans=1;
        long mod=998244353;
        long tot=0;
        for (int i = 0; i < n; i++) {
            if(i>0&&tot==0){
                ans=(ans*2)%mod;    
            }
            tot+=c[i];
        }
        System.out.println(ans);
        sc.close();
    }
}
