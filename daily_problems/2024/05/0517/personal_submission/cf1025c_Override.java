//化环为链
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class c1025 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args)throws Exception{
        String str = br.readLine();
        str += str;
        int len = str.length();
        int cnt = 1,maxe = 0;
        for (int i=1;i<len;i++){
            if(str.charAt(i) != str.charAt(i-1)) cnt++;
            else cnt = 1;
            maxe = Math.max(cnt,maxe);
        }
        maxe = Math.min(maxe,len/2);
        System.out.println(maxe);
    }
}
