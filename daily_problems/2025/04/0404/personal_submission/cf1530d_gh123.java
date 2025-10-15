//https://codeforces.com/problemset/submission/1530/313903798

import java.io.*;
import java.util.*;
public class D1530 {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
       // Random rng = new Random();

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] nums = new int[n + 1];
            int[] cnt = new int[n + 1];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
                cnt[nums[i]]++;
            }

            List<Integer> target = new ArrayList<>();
            List<Integer> position = new ArrayList<>();

            for (int i = 1; i <= n; i++) {
                if (cnt[i] == 0) target.add(i);
            }

            for (int i = 1; i <= n; i++) {
                cnt[nums[i]]--;
                if (cnt[nums[i]] > 0) position.add(i);
            }

            int k = position.size();
            pw.println(n - k);

            if (k > 1) {
                while (true) {
                    Collections.shuffle(position, rng);

                    boolean flg = true;
                    for (int i = 0; i < k; i++) {
                        if (target.get(i).equals(position.get(i))) {
                            flg = false;
                        }
                    }

                    if (flg) break;
                }

                for (int i = 0; i < k; i++) {
                    nums[position.get(i)] = target.get(i);
                }
            } else if (k == 1) {
                if (position.get(0).equals(target.get(0))) {
                    for (int i = 1; i <= n; i++) {
                        if (i != position.get(0) && nums[i] == nums[position.get(0)]) {
                            nums[i] = target.get(0);
                        }
                    }
                } else {
                    nums[position.get(0)] = target.get(0);
                }
            }

            for (int i = 1; i <= n; i++) {
                pw.print(nums[i] + " ");
            }
            pw.println();
        }

        pw.flush();
    }
}    

//跟着村长写代码就过了
