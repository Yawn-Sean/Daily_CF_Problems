//https://codeforces.com/problemset/submission/305/328602609
import java.util.HashSet;
import java.util.Scanner;

public class C305 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        HashSet<Integer>set=new HashSet<>();
        int max=0;
        for (int i = 0; i < n; i++) {
            int x=sc.nextInt();
            while (set.contains(x)) {
                set.remove(x);
                x++;
            }
            if(!set.contains(x)){
                max=Math.max(max, x);
                set.add(x);
            }
        }
        max++;
        System.out.println(max-set.size());
        sc.close();
    }
}
