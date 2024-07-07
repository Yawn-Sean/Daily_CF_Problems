import java.util.*;

public class StringDeletion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 读取字符串长度n
        String s = sc.next(); // 读取字符串s

        // 从字母 'z' 到 'b' 遍历，因为题目要求删除相邻且递减的字母对
        for (char i = 'z'; i > 'a'; i--) {
            // 遍历字符串 s
            for (int j = 0; j < s.length(); j++) {
                // 如果当前字符等于 i，并且满足以下条件之一：
                // 1. j > 0 且 s[j-1] == i-1 （左边相邻字符是前一个字母）
                // 2. j < s.length()-1 且 s[j+1] == i-1 （右边相邻字符是前一个字母）
                if (s.charAt(j) == i && ((j > 0 && s.charAt(j - 1) == i - 1) || (j < s.length() - 1 && s.charAt(j + 1) == i - 1))) {
                    // 删除 s[j]
                    s = s.substring(0, j) + s.substring(j + 1);
                    
                    j=-1; 
                }
            }
        }

        // 输出删除的字符总数
        System.out.println(n - s.length());
    }
}
