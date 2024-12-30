import java.util.Scanner;

/**
 * @Description:
 * @Author: Leon
 * @Date: 2024/5/2
 */
public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] cs = sc.next().toCharArray();
        int[] cnt = new int[26];
        for(char c: cs){
            cnt[c-'a']++;
        }
        int ans = 0;
        for(int c: cnt){
            if(c>0){
                ans++;
            }
        }
        System.out.println(ans);
        for (int i = 1; i <=ans ; i++) {
            System.out.println(cal(i, cs));
        }
    }
    private static long cal(int k, char[] cs){
        long res = 0;
        int loc = 0, soc = 0;
        int n = cs.length;
        int[] cnt = new int[26];
        int[] snt = new int[26];
        int c = 0, s = 0;
        for (int i = 0; i < n; i++) {
            int w = cs[i]-'a';
            cnt[w]++;
            snt[w]++;
            if(cnt[w]==1){
                c++;
            }
            if(snt[w]==1){
                s++;
            }
            while (c==k){
                int h = cs[loc] - 'a';
                cnt[h]--;
                if(cnt[h]==0){
                    c--;
                }
                loc++;
            }
            while (s>k){
                int h = cs[soc] - 'a';
                snt[h]--;
                if(snt[h]==0){
                    s--;
                }
                soc++;
            }
            res += loc - soc;
        }
        return res;
    }
}
