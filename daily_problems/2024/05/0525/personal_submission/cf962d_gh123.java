https://codeforces.com/problemset/submission/962/262450996
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class D962 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long[]a=new long[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextLong();
        }
        Map<Long,Integer>map=new HashMap<>();
        for (int i = 0; i < n; i++) {
            long k=a[i];
            while (map.containsKey(k)) {
                a[map.get(k)]=-1;
                map.remove(k);
                k=k*2;
            }
            map.put(k, i);
            a[i]=k;
        }
        System.out.println(map.size());
        for (long k : a) {
            if(k!=-1){
                System.out.print(k+" ");
            }
        }
        sc.close();
    }
}
