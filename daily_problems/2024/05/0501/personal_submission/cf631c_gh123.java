https://codeforces.com/problemset/submission/631/258959229
/*不会用stack处理二维数组， 因为即要保存排序的位置点， 还要保存排序的顺序是正序还是倒序，
所以还是参考其他方法写出来的，(用两个list保存一个最大数, 一个最小数)我还得多练习啊。。。
*/
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class C631 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
       
        int[]type=new int[n];
        int[]time=new int[n];
        for (int i = 1; i <=m; i++) {
            int t=sc.nextInt();
            int r=sc.nextInt()-1;
            type[r]=t;
            time[r]=i;
        }
        sc.close();
        PriorityQueue<Integer>max=new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer>min=new PriorityQueue<>();
        int p=n;
        while (p>0&&type[p-1]==0) {
            p--;
        }
        for (int i = 0; i < p; i++) {
            max.add(a[i]);
            min.add(a[i]);
        }
        int lastype=0;
        int cur=0;
        while (p-->0) {
            if(time[p]>cur){
                cur=time[p];
                lastype=type[p];
            }
            if(lastype==1){
                a[p]=max.poll();
            }
            else {
                a[p]=min.poll();
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.print(a[i]+" ");
        }

        sc.close();
    }
}
