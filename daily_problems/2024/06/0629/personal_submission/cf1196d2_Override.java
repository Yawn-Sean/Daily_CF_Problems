import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        Map<Character, Integer> mp = new HashMap<>();
        mp.put('R', -2);
        mp.put('G', -1);
        mp.put('B', 0);

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String s = sc.next();
            int ans = n;

            for (int i = 0; i < 3; i++) {
                int cnt = 0;
                for (int j = 0; j < k; j++) {
                    if ((j - mp.get(s.charAt(j))) % 3 != i) {
                        cnt++;
                    }
                }
                ans = Math.min(ans, cnt);
                for (int j = k; j < n; j++) {
                    if ((j - mp.get(s.charAt(j))) % 3 != i) {
                        cnt++;
                    }
                    if ((j - k - mp.get(s.charAt(j - k))) % 3 != i) {
                        cnt--;
                    }
                    ans = Math.min(ans, cnt);
                }
            }
            System.out.println(ans);
        }
    }
}
