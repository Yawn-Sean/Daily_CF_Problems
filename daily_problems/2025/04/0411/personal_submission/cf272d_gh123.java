//https://codeforces.com/problemset/submission/272/314948677
import java.util.HashMap;
import java.util.Scanner;

public class D272 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long[]a=new long[n];
        long[]b=new long[n];
        HashMap<Long,Integer>map=new HashMap<>();
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextLong();
        }
        for (int i = 0; i < n; i++) {
            b[i]=sc.nextLong();
        }
    
        int cnt=0;
        for (int i = 0; i < n; i++) {
            if(a[i]==b[i]){
                cnt++;
            }
            map.put(a[i], map.getOrDefault(a[i], 0)+1);
            map.put(b[i], map.getOrDefault(b[i], 0)+1);
        }
        int m=sc.nextInt();
        long ans=1;
        sc.close();
        for (long k : map.keySet()) {
            int val=map.get(k);
            for (int j = 1; j <=val; j++) {
                int tem=j;
                while (tem%2==0&&cnt>0) {
                    tem/=2;
                    cnt--;
                }
                ans=ans*tem%m;
            }
        }
        System.out.println(ans);
    }
}
