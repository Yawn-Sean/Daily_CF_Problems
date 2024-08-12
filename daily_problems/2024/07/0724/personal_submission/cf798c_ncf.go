package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF798C(os.Stdin, os.Stdout) }

func CF798C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	gd := a[0]
	for i := 1; i < n; i++ {
		gd = gcd(gd, a[i])
		if gd == 1 {
			break
		}
	}
	if gd > 1 {
		fmt.Fprintf(out, "YES\n0")
		return
	}
	ans := 0
	for i := 0; i < n-1; {
		if a[i]%2 != 0 {
			a[i], a[i+1] = a[i]-a[i+1], a[i]+a[i+1]
			ans += 1
		} else {
			i++
		}
	}
	if a[n-1]%2 != 0 {
		ans += 2
	}
	fmt.Fprintf(out, "YES\n%d", ans)
}

func gcd(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
