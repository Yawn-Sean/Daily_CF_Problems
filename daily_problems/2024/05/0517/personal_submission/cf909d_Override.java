import java.io.BufferedReader;
import java.io.InputStreamReader;

public class d909 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] a= new int[1000005];
    static int[] size= new int[1000005];
    static int[] col= new int[1000005];
    static int cnt,ans;
    public static void main(String[] args)throws Exception{
        String s = br.readLine();
        long len = s.length();
        for(int i=0;i<len;i++){
            a[i+1] = s.charAt(i)-'a'+1;
        }
        for(int i=1;i<=len;i++){
            if(a[i]!=a[i-1]){
                size[++cnt]++;col[cnt]=a[i];
            }else{
                size[cnt]++;
            }
        }
        //cnt 组数
        while (cnt>1){
            for(int i=1;i<=cnt;i++){
                if(i==1 || i==cnt) size[i]--;//两边
                else size[i]-=2;//中间
            }
            int tt=0,lst=0;
            for(int i=1;i<=cnt;i++){
                if(size[i]<=0) continue;
                if(col[i]!=lst){
                    lst=col[i];
                    size[++tt]=size[i];
                    col[tt]=col[i];
                }else{
                    size[tt]+=size[i];//合并
                }
            }
            ans++;cnt=tt;
        }
        System.out.println(ans);
    }
}
