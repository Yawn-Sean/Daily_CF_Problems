import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.List;
//挺难的...
public class cf105327k {
    static int[]a;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
        List<List<Integer>>list=findPartition(a);
        if(list.isEmpty()){
            System.out.println(-1);
        }else{
            Collections.sort(list.get(0),Comparator.reverseOrder());
            Collections.sort(list.get(1),Comparator.reverseOrder());
            int s1=0,s2=0;
            int i=0,j=0;
            int size1=list.get(0).size();
            int size2=list.get(1).size();
            while (i<size1||j<size2) {
                if(i<size1&&s1<=s2){
                    int x=list.get(0).get(i);
                    i++;
                    s1+=x;
                    System.out.print(x+" ");
                }else{
                    int x=list.get(1).get(j);
                    j++;
                    s2+=x;
                    System.out.print(x+" ");
                }
            }
        }
       

        sc.close(); 
    }
    static List<List<Integer>>findPartition(int[]a){
        int sum=0;
        for (int x : a) {
            sum+=x;
        }
        if(sum%2==1){
            return new ArrayList<>();
        }
        int m=sum/2;
        int n=a.length;
        boolean[][]dp=new boolean[n+1][m+1];
        for (int i = 0; i <=n; i++) {
            dp[i][0]=true;
        }
        for (int i = 1; i <=n; i++) {
            for (int j = 0; j <=m; j++) {
                if(a[i-1]<=j){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(!dp[n][m]){
            return new ArrayList<>();
        }
        List<Integer>set1=new ArrayList<>();
        List<Integer>set2=new ArrayList<>();
        int w=m;
        for (int i = n; i >0&&w>0; i--) {
            if(!dp[i-1][w]){
                set1.add(a[i-1]);
                w-=a[i-1];
            }else{
                set2.add(a[i-1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if(!set1.contains(a[i])&&!set2.contains(a[i])){
                set2.add(a[i]);
            }
        }
        return Arrays.asList(set1,set2);
    }
}
