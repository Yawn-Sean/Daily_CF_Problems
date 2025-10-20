import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
public class L105129 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        boolean[]prime=new boolean[51];
        Arrays.fill(prime, true);
        prime[0]=prime[1]=false;
        for (int i = 2; i < prime.length; i++) {
            if(prime[i]==false){
                continue;
            }
            for (int j = 2*i; j < prime.length; j+=i) {
                prime[j]=false;
            }
        }   
        List<Integer>list=new ArrayList<>();
        for (int i = 0; i < prime.length; i++) {
            if(prime[i]){
                list.add(i);
            }
        }
        List<Long>to_check=new ArrayList<>();
        to_check.add(1l);
        for (int x : list) {
            int k=to_check.size();
            for (int i = 0; i < k; i++) {
                to_check.add(to_check.get(i)*x);
            }
        }
        Collections.sort(to_check);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int[]vis=new int[51];
            while (n-->0) {
                int x=sc.nextInt();
                vis[x]=1;
            }
            for (long v : to_check) {
                boolean flag=true;
                for (int i = 0; i <=50; i++) {
                    if(vis[i]==1&&gcd(i,v)==1){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    System.out.println(v);
                    break;
                }
            }
        }
        sc.close();
    }
    static long gcd(long a,long b){
        if(b==0)return a;
        return gcd(b, a%b);
    }
}
