

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;

public class Main6 {
	
	
	
//	1、当n为奇数的时候，变换n个可以一次增加或减少1个负数，这样可以直到有n个负数，然后全变为整数
//	2、当n为偶数的时候，变换n个可以一次增加或减少2个负数，
//	所以当有偶数个负数时都可以变为正数，
//	当有奇数个负数时，最大和为（绝对值最小的那个为负数，其余的都为正数）。
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StreamTokenizer cin = new StreamTokenizer(br);
	static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
	
	static int nextInt()throws Exception{
		cin.nextToken();
		return (int) cin.nval;
	}
	
	public static void main(String[] args)throws Exception{
		int n = nextInt();
		int zheng = 0;
		int fu = 0;
		int min = 1000000001;
		int sum = 0;
		int m = 2*n-1;
		while(m-- != 0) {
			int key = nextInt();
			if(key<0) {
				key = -key;
				fu++;
			}else {
				zheng++;
			}
			sum+=key;
			if(key<min) min=key;
		}
		
		if(n%2==1) {
			pw.print(sum);
		}else {
			if(fu%2==0) { //偶数个负数
				pw.print(sum);
			}else{
				pw.print(sum-2*min);  //这里有点绕
			}
		}
		pw.flush();
	}
}
