package main

import (
	"bufio"
	"fmt"
	"io"
)

func CF831C(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, k int
	fmt.Fscan(in, &n, &k)

	a := make([]int, n)
	b := make([]int, k)

	pre := 0
	sa := make(map[int]bool)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		pre += a[i]
		sa[pre] = true
	}

	for i := 0; i < k; i++ {
		fmt.Fscan(in, &b[i])
	}

	ans := 0
	for x := range sa {
		start := b[0] - x
		ok := true
		for _, y := range b {
			if !sa[y-start] {
				ok = false
				break
			}
		}
		if ok {
			ans++
		}
	}
	fmt.Fprintln(out, ans)
}

func main() {
	CF831C(bufio.NewReader(os.Stdin), os.Stdout)
}
