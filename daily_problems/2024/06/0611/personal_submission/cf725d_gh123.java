//https://codeforces.com/problemset/submission/725/265136984
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class D725 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long[]t=new long[n];
        long[]w=new long[n];
        for (int i = 0; i < n; i++) {
            t[i]=sc.nextLong();
            w[i]=sc.nextLong();
        }
        PriorityQueue<Long>q=new PriorityQueue<>();
        List<long[]>bot=new ArrayList<long[]>();
        for (int i = 1; i < n; i++) {
            if(t[i]>t[0]){
                q.offer(w[i]-t[i]+1);
            }else{
                bot.add(new long[]{t[i],w[i]});
            }
        }
        Collections.sort(bot,(a,b)->Long.compare(b[0], a[0]));
        long[][]b=new long[2][bot.size()];
        for (int i = 0; i < b[0].length; i++) {
            b[0][i]=bot.get(i)[0];
            b[1][i]=bot.get(i)[1];
        }
        int ans=q.size()+1,pos=0;
        while (!q.isEmpty()) {
            t[0]-=q.poll();
            if(t[0]<0){
                break;
            }
            while (pos<b[0].length&&b[0][pos]>t[0]) {
                q.offer(b[1][pos]-b[0][pos]+1);
                pos++;
            }
            ans=Math.min(ans,q.size()+1);
        }
        System.out.println(ans);
    }   
}
