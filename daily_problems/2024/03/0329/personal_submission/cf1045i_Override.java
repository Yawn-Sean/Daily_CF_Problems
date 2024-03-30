import java.util.Scanner;
import java.util.HashMap;
import java.lang.Integer;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        HashMap<Integer, Integer> mp = new HashMap<>(); 
        long ans = 0L, num = 0L;
        
        for (int i = 0; i < T; ++i) {
            String str = scanner.next();
            num = 0L;
            for (int j = 0; j < str.length(); ++j) {
                num ^= (1L << (str.charAt(j) - 'a')); 
            }
            for (int j = 0; j < 26; ++j) {
                ans += mp.getOrDefault((int)num ^ (1 << j), 0); 
            }
            ans += mp.getOrDefault((int)num, 0); 
            mp.put((int)num, mp.getOrDefault((int)num, 0) + 1); 
        }
        System.out.println(ans);
        scanner.close();
    }
}
