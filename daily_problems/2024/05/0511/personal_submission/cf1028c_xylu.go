package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type rec struct{ x1, y1, x2, y2 int }

func solve(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	recs := make([]rec, n)
	sufmxx1, sufmxy1, sufmnx2, sufmny2 := make([]int, n+1), make([]int, n+1), make([]int, n+1), make([]int, n+1)
	for i := range recs {
		fmt.Fscan(in, &recs[i].x1, &recs[i].y1, &recs[i].x2, &recs[i].y2)
	}
	sufmxx1[n], sufmxy1[n] = int(-1e10), int(-1e10)
	sufmnx2[n], sufmny2[n] = int(1e10), int(1e10)
	for i := n - 1; i >= 0; i-- {
		sufmxx1[i] = max(sufmxx1[i+1], recs[i].x1)
		sufmxy1[i] = max(sufmxy1[i+1], recs[i].y1)
		sufmnx2[i] = min(sufmnx2[i+1], recs[i].x2)
		sufmny2[i] = min(sufmny2[i+1], recs[i].y2)
	}
	premxx1, premxy1, premnx2, premny2 := int(-1e10), int(-1e10), int(1e10), int(1e10)
	for i := 0; i < n; i++ {
		x1, y1, x2, y2 := max(premxx1, sufmxx1[i+1]), max(premxy1, sufmxy1[i+1]), min(premnx2, sufmnx2[i+1]), min(premny2, sufmny2[i+1])
		if x1 <= x2 && y1 <= y2 {
			fmt.Fprintln(out, x1, y1)
			return
		}
		premxx1, premxy1, premnx2, premny2 = max(premxx1, recs[i].x1), max(premxy1, recs[i].y1), min(premnx2, recs[i].x2), min(premny2, recs[i].y2)
	}
}

func main() {
	solve(os.Stdin, os.Stdout)
}
