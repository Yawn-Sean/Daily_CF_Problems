//https://codeforces.com/problemset/submission/1472/284105646
import java.util.Arrays;
import java.util.Scanner;

public class E1472 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int[][]arr=new int[n][3];
            for (int i = 0; i < n; i++) {
                int h=sc.nextInt();
                int w=sc.nextInt();
                arr[i][0]=Math.max(h,w);
                arr[i][1]=Math.min(h, w);
                arr[i][2]=i;
            }
            Arrays.sort(arr,(a,b)->a[0]==b[0]?a[1]-b[1]:a[0]-b[0]);
            int[]arr2=new int[n];
            int minw=arr[0][1],minj=0,lowerhmj=-1;
            for (int i = 0; i < n; i++) {
                if(arr[i][1]>minw&&arr[i][0]>arr[minj][0]){
                    arr2[arr[i][2]]=arr[minj][2];
                }else if(lowerhmj>-1&&arr[i][1]>arr[lowerhmj][1]){
                    arr2[arr[i][2]]=arr[lowerhmj][2];
                }else{
                    if(arr[i][1]<minw){
                        if(arr[i][0]>arr[minj][0]){
                            lowerhmj=minj;
                        }
                        minj=i;
                        minw=arr[i][1];
                    }
                    arr2[arr[i][2]]=-2;
                }
            }
            for (int i = 0; i < n; i++) {
                System.out.print(arr2[i]+1+" ");
            }
            System.out.println();
        }
        sc.close();
    }
}
