import java.util.HashSet;
import java.util.Scanner;
//100 points
public class D104852 {
    static int bound;
    static HashSet<Long>set;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        set=new HashSet<>();
        bound=(int)1e9;
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                dfs(i, j, i);
            }
        }
        set.add(0l);
        int ans=0;
        for (long x : set) {
            if(set.contains(n-x)){
                ans++;
            }
        }
        System.out.println((ans+1)/2);
        sc.close();
    }
   static void dfs(int x,int y,long cur){
        if(cur>bound) return;
        set.add(cur);
        dfs(x, y, cur*10+x);
        dfs(x, y, cur*10+y);
    }

}
