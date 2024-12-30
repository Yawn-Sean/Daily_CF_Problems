import java.util.*;
//参考https://www.luogu.com.cn/problem/solution/CF678D
public class d678 {
    static final long MOD = 1000000007; // 定义模数

    static long pw(long a, long b) { // 快速幂函数，计算 a 的 b 次方模 MOD
        long ans = 1, base = a;
        while (b != 0) {
            if ((b & 1) != 0) { // 如果 b 的最低位为 1
                ans = ans * base % MOD; // 将 ans 乘以 base，并模 MOD
            }
            base = base * base % MOD; // 将 base 平方，并模 MOD
            b >>= 1; // 将 b 右移一位
        }
        return ans % MOD; // 返回结果模 MOD
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long n = scanner.nextLong();
        long x = scanner.nextLong();

        if (a == 1) { // 如果 a 等于 1
            System.out.println((x + n % MOD * b % MOD) % MOD); // 直接计算结果
            return;
        }

        long inv = pw(a - 1, MOD - 2); // 计算 a-1 的逆元
        long power = pw(a, n); // 计算 a 的 n 次方
        long ans = ((power - 1) * inv % MOD * b % MOD + x % MOD * power % MOD) % MOD; // 计算最终结果
        System.out.println(ans);
    }
}
