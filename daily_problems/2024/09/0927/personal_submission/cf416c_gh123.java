//https://codeforces.com/problemset/submission/416/283148691
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class C416 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[][]arr=new int[n][3];
        for (int i = 0; i < n; i++) {
            arr[i][0]=sc.nextInt();
            arr[i][1]=sc.nextInt();
            arr[i][2]=i+1;
        }
        int m=sc.nextInt();
        int[][]table=new int[m][2];
        for (int i = 0; i < m; i++) {
            table[i][0]=sc.nextInt();
            table[i][1]=i+1;
        }
        Arrays.sort(table,(a,b)->a[0]-b[0]);
        Arrays.sort(arr,(a,b)->b[1]-a[1]);
        sc.close();
        int cost=0;
        ArrayList<int[]>list=new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int p=arr[i][0];
            for (int j = 0; j < m; j++) {
                if(table[j][0]>=p){
                    table[j][0]=-1;
                    cost+=arr[i][1];
                    list.add(new int[]{arr[i][2],table[j][1]});
                    break;
                }
            }
        }
        System.out.println(list.size()+" "+cost);
        for (int[] a : list) {
            System.out.println(a[0]+" "+a[1]);
        }
    }
}
