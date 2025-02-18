//https://codeforces.com/problemset/submission/729/275170816
import java.util.ArrayList;
import java.util.Scanner;

public class D729 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a=sc.nextInt();
        int b=sc.nextInt();
        int k=sc.nextInt();
        String s=sc.next();
        int []arr=new int[n];
        for (int i = 0; i < n; i++) {
            arr[i]=s.charAt(i)-'0';
        }
        int cnt=0;
        int sum=0;
        ArrayList<Integer>list=new ArrayList<>();
        sc.close();
        for (int i = b-1; i < n; i++) {
            sum=0;
            for (int j = 0; j < b; j++) {
                sum+=arr[i-j];
            }
            if(sum==0){
                arr[i]=1;
                cnt++;
                list.add(i+1);
            }
        }
        System.out.println(cnt-a+1);
        for (int i = 0; i < list.size()-a+1; i++) {
            System.out.print(list.get(i)+" ");
        }
    }
}
