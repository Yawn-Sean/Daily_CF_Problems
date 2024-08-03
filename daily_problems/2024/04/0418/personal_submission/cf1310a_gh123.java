import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class A1310 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[][]ans=new int[n][2];
        for (int i = 0; i < n; i++) {
            ans[i][0]=sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            ans[i][1]=sc.nextInt();
        }
        Arrays.sort(ans,(a,b)->a[0]-b[0]);
        PriorityQueue<Integer>pq=new PriorityQueue<>(Collections.reverseOrder());
        int i=0;
        long cur_sum=0;
        long ann=0;
        int curr=0;
        while (i<n||!pq.isEmpty()) {
          if(!pq.isEmpty()){
            cur_sum-=pq.poll();
            ann+=cur_sum;
            curr++;
          }else{
            curr=ans[i][0];
          }
          while (i<n&&curr==ans[i][0]) {
            cur_sum+=ans[i][1];
            pq.add(ans[i][1]);
            i++;
          }
        }
        System.out.println(ann);
        sc.close();
    }   
}
