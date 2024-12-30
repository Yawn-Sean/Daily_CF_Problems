package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type pair struct{ x, y int }

func solveB(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n, d int
	fmt.Fscan(in, &n, &d)
	a := make([]int, n)
	for i := 1; i < n-1; i++ {
		fmt.Fscan(in, &a[i])
	}
	points := make([]pair, n)
	for i := range points {
		fmt.Fscan(in, &points[i].x, &points[i].y)
	}

	edges := make([][]int, n)
	for i := 0; i < n; i++ {
		edges[i] = make([]int, n)
		for j := 0; j < i; j++ {
			edges[i][j] = d*(abs(points[i].x-points[j].x)+abs(points[i].y-points[j].y)) - a[j]
			edges[j][i] = edges[i][j] + a[j] - a[i]
		}
	}

	// dijkstra
	dis, vis := make([]int, n), make([]bool, n)
	for i := 1; i < n; i++ {
		dis[i] = int(1e12)
	}

	for i := 0; i < n; i++ {
		mni := n - 1
		for j := 0; j < n; j++ {
			if !vis[j] && dis[j] < dis[mni] {
				mni = j
			}
		}
		vis[mni] = true
		for j := 0; j < n; j++ {
			dis[j] = min(dis[j], dis[mni]+edges[mni][j])
		}
	}
	fmt.Fprintln(out, dis[n-1])
}

func main() {
	solveB(os.Stdin, os.Stdout)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
