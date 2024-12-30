import java.io.BufferedReader;
import java.io.InputStreamReader;

public class e533 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int ans1=1,ans2=1,l=Integer.MAX_VALUE,r=Integer.MIN_VALUE;
    public static void main(String[] args)throws Exception{
        int n = Integer.parseInt(br.readLine());
        String s1 = br.readLine();
        String s2 = br.readLine();
        //找不同的区间
        for (int i=0;i<n;i++){
            if(s1.charAt(i) != s2.charAt(i)){
                l=Math.min(l,i);
                r=Math.max(r,i);
            }
        }
        for(int i=l+1;i<=r;i++){
            if(s1.charAt(i)!=s2.charAt(i-1)){
                ans1=0;
            }
            if(s1.charAt(i-1)!=s2.charAt(i)){
                ans2=0;
            }
        }
        System.out.println(ans1+ans2);
    }
}
