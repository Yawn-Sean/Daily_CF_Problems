import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Task solver = new Task();
        solver.solve(in.nextInt(), in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] arr = new int[testNumber];
            for (int t = 0; t < testNumber; t++) {
                arr[t] = in.nextInt();
            }
            int[] solve = new Solution().solve(arr);
            for (int v : solve) {
                out.println(v);
            }
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}

class Solution {
    public int[] solve(int[] arr) {
        int n = arr.length;
        int[] ans = new int[n];
        int max = Arrays.stream(arr).max().orElse(0);
        int[] min = new int[max + 5];
        Arrays.fill(min, -1);
        Prime prime = new Prime(max + 5);
        for (int i = 1; i <= max; i++) {
            int sum = prime.sumDivisor(i, max);
            if (sum == -1) {
                continue;
            }
            if (min[sum] == -1) {
                min[sum] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            ans[i] = min[arr[i]];
        }
        return ans;
    }
}

class Prime {
    /**
     * 记录每个数的最小质因子，当最小质因子等于该数时，说明是质数
     */
    int[] v;

    /**
     * 质数列表
     */
    List<Integer> primeList = new ArrayList<>();

    public Prime(int n) {
        v = primes(n);
        for (int i = 2; i < v.length; i++) {
            if (v[i] == i) {
                primeList.add(i);
            }
        }
    }

    public boolean isPrime(int n) {
        return n >= 2 && v[n] == n;
    }

    /**
     * 质因数分解，key为质数，value为该质因数的个数，时间复杂度O(log(n))
     */
    public Map<Integer, Integer> divide(int n) {
        Map<Integer, Integer> map = new HashMap<>();
        while (n > 1) {
            map.put(v[n], map.getOrDefault(v[n], 0) + 1);
            n /= v[n];
        }
        return map;
    }

    public int sumDivisor(int n, int max) {
        int sum = 1;
        int cur = 1;
        int s = 1;
        int t = 1;
        while (n > 1) {
            if (v[n] == cur) {
                t *= cur;
                if (t > max) {
                    return -1;
                }
                s += t;
            } else {
                sum *= s;
                if (sum > max) {
                    return -1;
                }
                cur = v[n];
                s = 1 + cur;
                t = cur;
            }
            n /= v[n];
        }
        sum *= s;
        if (sum > max) {
            return -1;
        }
        return sum;
    }

    /**
     * 埃氏筛，时间复杂度O(n * log(log(n)))
     */
    public static int[] primes(int n) {
        int[] v = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            v[i] = i;
        }
        for (int i = 2; i * i <= n; i++) {
            if (v[i] != i) {
                continue;
            }
            for (int j = i * i; j <= n; j += i) {
                if (v[j] == j) {
                    v[j] = i;
                }
            }
        }
        return v;
    }
}
