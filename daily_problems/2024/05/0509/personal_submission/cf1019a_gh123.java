https://codeforces.com/problemset/submission/1019/260069491
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class A1019 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        ArrayList<Integer>[]team=new ArrayList[m];
        for (int i = 0; i < m; i++) {
            team[i]=new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            team[sc.nextInt()-1].add(sc.nextInt());
        }
        sc.close();
        for (int i = 0; i < m; i++) {
            Collections.sort(team[i]);
        }
        long ans=Long.MAX_VALUE;
        for (int vote = 0; vote <=n/2; vote++) {
            long temp=0;
            int cur=team[0].size();
            PriorityQueue<Integer>pq=new PriorityQueue<>();
            for (int j = 1; j < m; j++) {
                int start=0;
                while (team[j].size()-start>vote) {
                    cur++;
                    temp+=team[j].get(start++);
                }
                while (team[j].size()-start>0) {
                    pq.add(team[j].get(start++));
                }
            }
            while (cur<=vote) {
                cur++;
                temp+=pq.poll();
            }
            ans=Math.min(ans, temp);
        }
        System.out.println(ans);
    }
}
