package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	asc := make([]int, n)
	dp_asc := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	asc[0] = a[0]
	for i := 1; i < n; i++ {
		if a[i] <= asc[i-1] {
			asc[i] = asc[i-1] + 1
		} else {
			asc[i] = a[i]
		}
		dp_asc[i] = dp_asc[i-1] + asc[i] - a[i]
	}
	desc := make([]int, n)
	dp_desc := make([]int, n)
	desc[n-1] = a[n-1]
	for i := n - 2; i >= 0; i-- {
		if a[i] <= desc[i+1] {
			desc[i] = desc[i+1] + 1
		} else {
			desc[i] = a[i]
		}
		dp_desc[i] = dp_desc[i+1] + desc[i] - a[i]
	}
	ans := min(dp_asc[n-1], dp_desc[0])
	for i := 0; i < n-1; i++ {
		var tmp int
		if asc[i] == desc[i+1] {
			tmp++
		}
		ans = min(ans, dp_asc[i]+dp_desc[i+1]+tmp)
	}
	fmt.Fprintln(out, ans)
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
