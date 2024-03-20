import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
public class A375 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        char s[] = in.nextLine().toCharArray();
        int digits[] = new int[10];
        for(int i = 0; i < s.length; i++)
            digits[s[i] - '0']++;
        digits[1]--;
        digits[6]--;
        digits[8]--;
        digits[9]--;
        int ending[] = {1689, 1896, 1869, 1698, 1968, 1986, 6198};
        int mod = 0;
        for(int i = 1; i < 10; i++)
            for(int j = 0; j < digits[i]; j++)
                mod = (mod * 10 + i) % 7;
        outer:
        for(int i = 0; i < ending.length; i++)
            if((mod * 10000 + ending[i]) % 7 == 0){
                for(int ii = 1; ii < 10; ii++)
                    for(int jj = 0; jj < digits[ii]; jj++)
                        out.print(ii);
                out.print(ending[i]);
                break outer;
            }
        if(digits[0] > 0)
            for(int i = 0; i < digits[0]; i++)
                out.print(0);
        out.close();
    }
}
