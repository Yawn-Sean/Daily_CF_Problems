//https://codeforces.com/problemset/submission/644/280675663
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class B644 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
            int n=sc.nextInt();
            int b=sc.nextInt();//que_maxsize
            long process=0;
            Queue<Long>que=new LinkedList<>();
            for (int i = 0; i < n; i++) {
                int t=sc.nextInt();
                int d=sc.nextInt();
                while (!que.isEmpty()&&que.peek()<=t) {
                    que.remove();//小于当前时间了，就可以出去了，
                }
                if(que.size()<=b){
                    process=Math.max(process,t)+d;
                    System.out.print(process+" ");
                    que.add(process);
                }else{//这时候没办法处理，输出-1
                    System.out.print("-1 ");
                }
            }
            System.out.println();
        sc.close();
    }
}
