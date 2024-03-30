import java.util.*;
public class cf1045i_Leoncn {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Integer, Integer> map = new HashMap<>();
        long ans = 0;
        for (int i = 0; i < n; i++) {
            char[] cs = sc.next().toCharArray();
            int total = 0;
            for(char c: cs){
                int w = c-'a';
                total ^=(1<<w);
            }

            ans += map.getOrDefault(total, 0);
            for (int j = 0; j < 32; j++) {
                ans += map.getOrDefault((1<<j)^(total), 0);
            }

            map.merge(total, 1, Integer::sum);

        }
        System.out.println(ans);
    }
}
