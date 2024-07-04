
import java.io.*;

public class d1672 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    public static void main(String[] args)throws Exception{
        int t = nextInt();
        while (t-->0){
            int n = nextInt();
            int[] nums1 = new int[n];//注意不能多开空间 否则for(nu :nums)有误
            int[] nums2 = new int[n];
            for(int i=0;i<n;i++) nums1[i] = nextInt();
            for(int i=0;i<n;i++) nums2[i] = nextInt();

            int[] save = new int[n+1];
            int pt = 0;

            for(int nu  : nums1){
                if(nu == nums2[pt]) pt++;
                else save[nu]++;
                while (pt<n && pt>0 && nums2[pt]==nums2[pt-1] && save[nums2[pt]]>0){
                    save[nums2[pt]]--;pt++;
                }
            }
            String res = pt==n? "YES":"NO";
            pw.println(res);
        }
        pw.flush();
    }
}
