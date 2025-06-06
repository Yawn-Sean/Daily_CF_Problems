//! core logic only
//! submission: https://codeforces.com/problemset/submission/237/307418889
const MULTIPLE_TEST: bool = false;

fn solver(t: String, n: usize, scanner: &mut Scanner) -> impl Printable {
    fn count(s: &str) -> [usize; 26] {
        let mut cnt = [0; 26];
        s.bytes().for_each(|b| cnt[(b - b'a') as usize] += 1);
        cnt
    }

    let src = n + 26;
    let dst = src + 1;
    let mut graph = Graph::new(dst + 1);

    for (i, &c) in count(&t).iter().enumerate() {
        if c > 0 {
            graph.add_edge(src, i, c, 0);
        }
    }

    for (i, (si, ai)) in scanner.iter::<(String, usize)>(n).enumerate() {
        graph.add_edge(26 + i, dst, ai, 0);
        let cost = (i + 1) as i64;
        for (j, &c) in count(&si).iter().enumerate() {
            if c > 0 {
                graph.add_edge(j, 26 + i, c, cost);
            }
        }
    }

    let (cost, flow) = graph.min_cost_max_flow(src, dst);
    if flow != t.len() {
        -1
    } else {
        cost
    }
}

struct Edge {
    from: usize,
    to: usize,
    flow: usize,
    cost: i64,
}

impl Edge {
    fn new(from: usize, to: usize, flow: usize, cost: i64) -> Self {
        Self {
            from,
            to,
            flow,
            cost,
        }
    }
}

struct Graph {
    edges: Vec<Edge>,
    nodes: Vec<Vec<usize>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        Self {
            edges: vec![],
            nodes: vec![vec![]; n],
        }
    }
    fn add_edge(&mut self, from: usize, to: usize, flow: usize, cost: i64) {
        let eidx = self.edges.len();
        let e = Edge::new(from, to, flow, cost);
        self.edges.push(e);
        self.nodes[from].push(eidx);

        let re = Edge::new(to, from, 0, -cost);
        self.edges.push(re);
        self.nodes[to].push(eidx ^ 1);
    }
    fn min_cost_max_flow(&mut self, src: usize, dst: usize) -> (i64, usize) {
        let (mut cost, mut flow) = (0, 0);
        loop {
            let (c, f) = self.spfa(src, dst);
            if f == 0 {
                return (cost, flow);
            }
            cost += c;
            flow += f;
        }
    }
    fn spfa(&mut self, src: usize, dst: usize) -> (i64, usize) {
        let n = self.nodes.len();
        let mut inq = vec![false; n];
        inq[src] = true;
        let mut dist = vec![i64::MAX; n];
        dist[src] = 0;
        let mut queue = std::collections::VecDeque::from([src]);
        let mut from = vec![usize::MAX; n];

        while let Some(cur) = queue.pop_front() {
            inq[cur] = false;
            for &eidx in &self.nodes[cur] {
                let e = &self.edges[eidx];
                if e.flow == 0 {
                    continue;
                }
                let d = dist[cur] + e.cost;
                if d < dist[e.to] {
                    dist[e.to] = d;
                    from[e.to] = eidx;
                    if !inq[e.to] {
                        queue.push_back(e.to);
                    }
                }
            }
        }
        if dist[dst] == i64::MAX {
            return (0, 0);
        }
        let mut flow = usize::MAX;
        let mut cur = dst;
        while cur != src {
            let eidx = from[cur];
            let e = &self.edges[eidx];
            flow = flow.min(e.flow);
            cur = e.from;
        }

        cur = dst;
        while cur != src {
            let eidx = from[cur];
            self.edges[eidx].flow -= flow;
            self.edges[eidx ^ 1].flow += flow;
            cur = self.edges[eidx].from;
        }
        (dist[dst] * (flow as i64), flow)
    }
}
