package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1954D(os.Stdin, os.Stdout) }

func CF1954D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	mx := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		mx = max(mx, a[i])
	}
	sort.Ints(a)
	ans := 0
	sm := make([]int, 5001)
	sm[0] = 1
	mod := 998244353
	csm := 0
	for i := 0; i < n; i++ {
		csm += a[i]
		for j := csm; j >= a[i]; j-- {
			ans = (ans + sm[j-a[i]]*max((j+1)/2, a[i])) % mod
			sm[j] = (sm[j] + sm[j-a[i]]) % mod
		}
	}
	fmt.Fprintf(out, "%d", ans)
}
