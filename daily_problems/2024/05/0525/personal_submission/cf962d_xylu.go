package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	mp := make(map[int]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
		for j, ok := mp[a[i]]; ok && j != -1; j, ok = mp[a[i]] {
			mp[a[i]] = -1
			a[j], a[i] = -1, a[i]<<1
		}
		mp[a[i]] = i
	}

	ans := make([]int, 0, n)
	for _, v := range a {
		if v != -1 {
			ans = append(ans, v)
		}
	}
	fmt.Fprintln(out, len(ans))
	for _, v := range ans {
		fmt.Fprint(out, v, " ")
	}
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
