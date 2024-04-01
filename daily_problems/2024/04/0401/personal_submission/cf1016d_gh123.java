import java.util.Scanner;
public class Solution {
	static Scanner in = new Scanner(System.in);
	
	public static void main(String []args){
		int m = in.nextInt();
		int n = in.nextInt();
		int a[] = new int[m];
		int b[] = new int[n];
		int xm = 0, xn = 0;
		for(int i = 0; i < m; i++){
			a[i] = in.nextInt();
			xm ^= a[i];
		}
		for(int i = 0; i < n; i++){
			b[i] = in.nextInt();
			xn ^= b[i];
		}
		if(xm != xn)
			System.out.println("NO");
		else{
			System.out.println("YES");
			for(int i = 0; i < m-1; i++){
				for(int j = 0; j < n-1; j++){
					System.out.print(0 + " ");
				}
				System.out.print(a[i] + "\n");
			}
			for(int i = 0; i < n-1; i++){
				System.out.print(b[i] + " ");
			}
			System.out.println(xn^a[m-1]^b[n-1]);
		}
	}
}
