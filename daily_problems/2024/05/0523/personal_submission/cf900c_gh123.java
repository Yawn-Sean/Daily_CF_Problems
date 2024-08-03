// submission link....https://codeforces.com/problemset/submission/900/262354260
import java.util.Scanner;
import java.util.TreeSet;


public class C900 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]ans=new int[n];
        for (int i = 0; i < n; i++) {
            ans[i]=sc.nextInt();
        }
        sc.close();
        int[]rem=new int[n+1];
        TreeSet<Integer>set=new TreeSet<>();
        set.add(-1);
        set.add(ans[0]);
        for (int i = 1; i < n; i++) {
            int max=set.last();
            set.remove(max);
            if(ans[i]<max&&ans[i]>set.last()){
                rem[max]++;
            }
            set.add(max);
            set.add(ans[i]);
        }
        int m=-1;
        for (int i = 0; i < n; i++) {
            if(ans[i]>m){
                m=ans[i];
                rem[ans[i]]--;
            }
        }
        int max=-2;
        int num=-1;
        for (int i = 1; i <=n; i++) {
            if(rem[i]>max){
                max=rem[i];
                num=i;
            }
        }
        System.out.println(num);
    }
}
