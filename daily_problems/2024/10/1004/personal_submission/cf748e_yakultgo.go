package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)
	mx := 0
	cnt := [int(1e7) + 1]int{}
	sum := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		mx = max(mx, a[i])
		cnt[a[i]]++
		sum += a[i]
	}
	if sum < k {
		fmt.Fprintln(out, -1)
		return
	}
	sum = 0
	for i := mx; i > 0; i-- {
		sum += cnt[i]
		if i*2 <= mx {
			sum -= cnt[i*2]
		}
		if i*2-1 <= mx && i != 1 {
			sum -= cnt[i*2-1]
		}
		if sum >= k {
			fmt.Fprintln(out, i)
			return
		}
		cnt[i/2] += cnt[i]
		cnt[(i+1)/2] += cnt[i]
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
