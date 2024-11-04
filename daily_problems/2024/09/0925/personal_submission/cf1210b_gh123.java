//https://codeforces.com/problemset/submission/1210/282867422
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B1210 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long[]a=new long[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextLong();
        }
        long[]b=new long[n];
        for (int i = 0; i < b.length; i++) {
            b[i]=sc.nextLong();
        }
        Set<Long>set=new HashSet<>();
        Set<Long>set2=new HashSet<>();
        sc.close();
        for (Long v : a) {
            if(!set.add(v)){
                set2.add(v);
            }
        }
        long[]tw=new long[set2.size()];
        int k=0;
        for (long l : set2) {
            tw[k++]=l;
        }
        long ans=0;
        for (int i = 0; i < n; i++) {
            long v=a[i];
            for (long q : tw) {
                if((q&v)==v){
                    ans+=b[i];
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}
