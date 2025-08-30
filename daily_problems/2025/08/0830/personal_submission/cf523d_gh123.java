//https://codeforces.com/problemset/submission/523/336234456
import java.util.PriorityQueue;
import java.util.Scanner;
//学会一个技巧，就是先把优先队列填满，这样每次poll即可，就不用每次讨论pq的大小跟k的关系了。
public class D523 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
      PriorityQueue<Long>pq=new PriorityQueue<>();
      for (int i = 0; i < k; i++) {
        pq.add(0l);
      }
      StringBuilder sb=new StringBuilder();
        for (int i = 0; i < n; i++) {
            long s=sc.nextInt();
            long m=sc.nextInt();
            long t=pq.poll();
            t=Math.max(t, s)+m;
            sb.append(t).append("\n");
            pq.add(t);
        }
        System.out.println(sb);
        sc.close();
    }
    
}
