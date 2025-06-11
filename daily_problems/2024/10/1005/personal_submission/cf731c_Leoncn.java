public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), K = readInt();
		int arr[] = new int[N+1];
		for(int i = 1; i<=N; i++) arr[i] = readInt();
		int par[] = new int[N+1];
		for(int i = 1; i<=N; i++) par[i] = i;
		for(int i = 1; i<=M; i++) {
			int a = readInt(), b = readInt(), ap = find(par, a), bp = find(par, b);
			if(ap == bp) continue;
			par[ap] = bp;
		}
		int clr[] = new int[K+1];
		ArrayList<Integer> al[] = new ArrayList[N+1];
		for(int i = 1; i<=N; i++) al[i] = new ArrayList<>();
		for(int i = 1; i<=N; i++) {
			al[find(par, i)].add(arr[i]);
		}
		int tot = 0;
		for(int i = 1; i<=N; i++) {
			int max = 0;
			for(int n : al[i]) {
				clr[n]++;
				max = Math.max(clr[n], max);
			}
			tot += al[i].size()-max;
			for(int n : al[i]) clr[n] = 0;
		}
		println(tot);
		exit();
	}
	
	public static int find(int par[], int n) {
		return par[n] = par[n] == n ? n : find(par, par[n]);
	}
 
