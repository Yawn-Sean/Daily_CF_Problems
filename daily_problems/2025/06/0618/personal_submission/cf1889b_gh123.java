//https://codeforces.com/problemset/submission/1889/324965559
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class B1889 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
              int n=sc.nextInt();
        int c=sc.nextInt();
        long[]a=new long[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextLong();
        }   
        long sum=a[0];
        Queue<Integer>que=new LinkedList<>();
        for (int i = 1; i < n; i++) {
            if(sum+a[i]>=(long)(i+1)*c){
                sum+=a[i];
                while (!que.isEmpty()) {
                    sum+=a[que.poll()-1];//已经大于现在的i了，那肯定就大于之前的索引
                }
            }else{
                que.add(i+1);
            }
        }
        System.out.println(que.isEmpty()?"YES":"NO"); 
        }
     
        sc.close();
        
    }
}
