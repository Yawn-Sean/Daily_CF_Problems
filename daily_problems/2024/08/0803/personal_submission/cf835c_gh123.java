//https://codeforces.com/problemset/submission/835/274103310
//为什么我这么笨，，，不看题解或者别人的代码，就很难做出来。。。
import java.util.Scanner;


public class C835 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int views=sc.nextInt();
        int c=sc.nextInt();
        int[][][]arr=new int[c+1][101][101];
        for (int i = 0; i < n; i++) {
            int x=sc.nextInt();
            int y=sc.nextInt();
            int b=sc.nextInt();
            arr[b][x][y]++;
        }
       
        for (int b = 0; b <=c; b++) {
            for (int x = 1; x < 101; x++) 
                for (int y = 2; y < 101; y++) 
                    arr[b][x][y]+=arr[b][x][y-1];
              for (int x = 2; x < 101; x++) 
                  for (int y = 1; y < 101; y++) 
                        arr[b][x][y]+=arr[b][x-1][y];
            }
            for (int i = 1; i <=views; i++) {
                int time=sc.nextInt();
                int x1=sc.nextInt();
                int y1=sc.nextInt();
                int x2=sc.nextInt();
                int y2=sc.nextInt();
                int sum=0;
                for (int b = 0; b <=c; b++) {
                    int cnt=arr[b][x2][y2];
                    if(x1>=2)
                    cnt-=arr[b][x1-1][y2];
                    if(y1>=2)
                    cnt-=arr[b][x2][y1-1];
                    if(x1>=2&&y1>=2){
                        cnt+=arr[b][x1-1][y1-1];
                    }
                    sum+=cnt*((b+time)%(c+1));
                }
                System.out.println(sum);
            }
            sc.close();
        }
    }

