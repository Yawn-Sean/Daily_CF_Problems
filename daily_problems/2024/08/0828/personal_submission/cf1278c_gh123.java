//https://codeforces.com/problemset/submission/1278/278457264
import java.util.HashMap;
import java.util.Scanner;

public class C1278 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int[]a=new int[n*2];
            int dif=0;
            for (int i = 0; i < a.length; i++) {
                a[i]=sc.nextInt();
                if(a[i]==1){
                    dif++;
                }else{
                    dif--;
                }
            }
            if(dif==0){
                System.out.println(0);
                continue;
            }
            HashMap<Integer,Integer>map=new HashMap<>();
            map.put(0, 0);
            int cur=0;
            for (int i = n; i < a.length; i++) {
                if(a[i]==1){
                    cur++;
                }else{
                    cur--;
                }
                if(!map.containsKey(cur)){
                    map.put(cur, i-n+1);
                }
            }
            cur=0;
            int ans=2*n;
            if(map.containsKey(dif)){
                ans=Math.min(ans, map.get(dif));
            }
            for (int i = n-1; i >=0; i--) {
                if(a[i]==1){
                    cur++;
                }else{
                    cur--;
                }
                if(map.containsKey(dif-cur)){
                    ans=Math.min(ans, n-i+map.get(dif-cur));
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}
