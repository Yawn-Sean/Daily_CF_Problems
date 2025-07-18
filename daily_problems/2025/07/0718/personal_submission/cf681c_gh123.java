//https://codeforces.com/problemset/submission/681/329567331
import java.util.PriorityQueue;
import java.util.Scanner;

public class C681 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();

        PriorityQueue<Integer>pq=new PriorityQueue<>();
        StringBuilder sb=new StringBuilder();
        int cnt=0;
        for (int i = 0; i < n; i++) {
            String tem=sc.next();
            if(tem.equals("insert")){
                int x=sc.nextInt();
                pq.add(x);
                sb.append("insert "+x+"\n");
                cnt++;
            }else if(tem.equals("getMin")){
                int x=sc.nextInt();
                while (!pq.isEmpty()&&pq.peek()<x) {
                    pq.poll();
                    sb.append("removeMin\n");
                    cnt++;
                }
                if(pq.isEmpty()||pq.peek()!=x){
                    pq.add(x);
                    sb.append("insert "+x+"\n");
                    cnt++;
                }
                sb.append("getMin "+x+"\n");
                cnt++;
            }else{
                if(pq.isEmpty()){
                    pq.add(1);
                    sb.append("insert 1\n");
                    cnt++;
                }
                pq.poll();
                sb.append("removeMin\n");
                cnt++;
            }
        }
        System.out.println(cnt);
        System.out.println(sb.toString());
        sc.close();
        }
       
}
