import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

// If AtCoder, change className to Main
public class I {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong(); // Reads the number of strings to process
        Map<Long, Long> frequencyMap = new HashMap<>();
        long totalPairs = 0;

        while (n-- > 0) {
            String s = scanner.next(); // Reads the next string
            long a = 0;

            // XOR all characters of the string after shifting
            for (int j = 0; j < s.length(); j++) {
                a ^= 1L << (s.charAt(j) - 'a');
            }

            // For each character, update totalPairs by adding the count from the map
            for (int j = 0; j < 26; j++) {
                totalPairs += frequencyMap.getOrDefault(1L << j ^ a, 0L);
            }

            // Update the totalPairs and frequency map for the current string's encoding
            totalPairs += frequencyMap.getOrDefault(a, 0L);
            frequencyMap.put(a, frequencyMap.getOrDefault(a, 0L) + 1);
        }

        System.out.println(totalPairs); // Print the total number of pairs
    }
}
