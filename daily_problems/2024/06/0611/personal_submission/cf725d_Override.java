import java.util.Arrays;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

public class d725 {
    static class Pair{
        long first;
        long second;
        Pair(long first,long second){
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args)throws Exception{
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long t = scanner.nextLong();
        long w = scanner.nextLong();
        //贪心策略：每次放飞一个花费气球最少的队伍
        PriorityQueue<Long> q = new PriorityQueue<>();
        Pair[] te = new Pair[300005];
        for(int i=2;i<=n;i++){
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            te[i] = new Pair(x,y);
        }

        Arrays.sort(te,2,n+1,(a,b)-> Long.compare(a.first,b.first));

        int i = n;
        int rank = Integer.MAX_VALUE;
        while (true){
            for(;i>=2&&te[i].first>t;i--){
                q.offer(te[i].second-te[i].first+1);
            }

            rank = Math.min(rank,q.size()+1);
            if(!q.isEmpty() && t>=q.peek()){
                t-=q.poll();
            }else {//当无力迫害或已经rk1的时候退出
                System.out.println(rank);
                break;
            }
        }
    }
}
