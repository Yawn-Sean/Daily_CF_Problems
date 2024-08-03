
//参考了gh123的题解
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class d747 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    public static void main(String[] args)throws Exception{
        int n = nextInt();
        int k = nextInt();
        int[] nums = new int[n];
        for(int i=0;i<n;i++){
            nums[i] = nextInt();
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<0) cnt++; //小于0的天数
        }
        if(cnt>k){ //小于0的天数比冬天轮胎多
            pw.println(-1);
            pw.flush();
        }else{
            int tra = k-cnt;
            int cur = 0;
            int[] b = new int[n];
            int j = 0;
            boolean start = false;
            for(int i=0;i<n;i++){
                if(nums[i]<0){
                    b[j]=cur;
                    cur=0;
                    j++;
                    start = true;
                }else if(start){
                    cur++;
                }
            }
            Arrays.sort(b);//从第一个冬天开始的  大于0的个数
            for(int i=0;i<n;i++){
                if(b[i]<=tra){
                    tra -=b[i];
                    b[i]=0;
                }else {
                    break;
                }
            }
            int change = 0;
            for(int i=0;i<n;i++){
                if(b[i]>0){
                    change+=2;
                }
            }
            if(start) change++;
            if(cur>tra) change++;
            pw.println(change);
            pw.flush();
        }

    }
}
