https://codeforces.com/problemset/submission/960/261134681
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class C960 {
    static PriorityQueue<Integer>que=new PriorityQueue<>(Collections.reverseOrder());
    static Queue<Long>q=new LinkedList<>();
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long d; int x;
        x=sc.nextInt();
        d=sc.nextLong();
        long pre=1;
        int cnt=1;
        long[]a=new long[1100];//没用到
        long sum=d-1;//没用到
        while (x>0) {
            if(x>=Math.pow(2, cnt)-1){
                q.offer(pre);
                cnt++;
            }else{
                x-=(long)Math.pow(2, cnt-1)-1;
                if(x==0) break;
                pre+=d;
                cnt=1;
                q.offer(pre);
                cnt++;
            }
        }
        System.out.println(q.size());
        while (!q.isEmpty()) {
            System.out.print(q.poll()+" ");
        }
        sc.close();
    }
}
