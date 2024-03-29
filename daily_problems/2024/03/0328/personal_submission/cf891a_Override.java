
import java.util.Scanner;

public class Main3 {
	public static int gcd(int a,int b) {
		
		if(b==0) return a;
		return gcd(b, a%b);
		
	}
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int[] arr = new int[n+1];
		int cnt = 0;  //记录1的个数
		
		for(int i=1;i<=n;i++) {
			arr[i] = cin.nextInt();
			if(arr[i] == 1) {
				cnt++;
			}
		}
		if(cnt!=0) {
			System.out.print(n-cnt);
			return ;
		}
		int ans = Integer.MAX_VALUE;
		for(int i=1;i<n;i++) {
			int g = arr[i];
			for(int j=i+1;j<=n;j++) {
				if(g<arr[j]) {
					g = gcd(arr[j],g);
				}else {
					g = gcd(g,arr[j]);
				}
				
				if(g==1) {
					ans = Math.min(ans,j-i+n-1);
				}
			}
		}
		//可以考虑用羊神的思想 先算出最短的gcd
		if(ans == Integer.MAX_VALUE) {
			System.out.print(-1);
			return;
		}
		System.out.print(ans);
		
	}
}
