//https://codeforces.com/problemset/submission/1267/280802746
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.awt.Point;

public class E1267 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[][]votes=new int[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                votes[j][i]=sc.nextInt();
            }
        }
        Point[]diff=new Point[m];
        List<Integer>ans=null;
        for (int i = 0; i < n-1; i++) {
            int sum=0;
            for (int j = 0; j < m; j++) {
                int d=votes[i][j]-votes[n-1][j];
                diff[j]=new Point(d,j+1);
                sum+=d;
            }
            Arrays.sort(diff,(a,b)->a.x-b.x);
            List<Integer>list=new ArrayList<>();
            for (int j = 0; j < m; j++) {
                if(sum>=0) break;
                sum-=diff[j].x;
                list.add(diff[j].y);
            }
            if(ans==null||ans.size()>list.size()){
                ans=list;
            }
        }
        System.out.println(ans.size());
        StringBuilder sb=new StringBuilder();
        for (int id : ans) {
            sb.append(id).append(" ");
        }
        System.out.println(sb.toString());
        sc.close();
    }
   
}
