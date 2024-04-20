//贪心

import java.io.*;

public class c1031 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static int maxn = 100001;
    static int[] arr = new int[maxn];
    static int tot;
    static boolean used[] = new boolean[maxn];
    public static void main(String[] args) throws Exception{
        int a = nextInt();
        int b = nextInt();
        int sum = 0;
        if(a+b>=1){
            for(int i=1;;i++){
                arr[tot++] = i;
                sum+=i;
                if(sum+i+1 > a+b){
                    break;
                }
            }
        }
        int sum2 = 0,cnt2 = 0;
        for(int i=tot-1;i>=0;i--){
            if(sum2+arr[i] <= a){
                sum2 +=arr[i];
                used[i]=true;
                cnt2++;
            }
        }
        pw.println(cnt2);
        for(int i=0;i<tot;i++){
            if(used[i]){
                pw.print(arr[i]+" ");
            }
        }
        pw.println();
        pw.println(tot-cnt2);
        for(int i=0;i<tot;i++){
            if(!used[i]){
                pw.print(arr[i]+" ");
            }
        }
        pw.flush();
    }
}
