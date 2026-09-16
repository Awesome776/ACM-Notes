/*
 * Dijkstra 最短路模板（优先队列优化）
 * 时间复杂度：O((V + E) log V)
 * 空间复杂度：O(V + E)
 *
 * 适用于：非负权图的单源最短路径
 * 图存储：链式前向星（邻接表）
 *
 * 编译：g++ -std=c++17 -O2 -o dijkstra dijkstra.cpp
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m, s;  // 顶点数、边数、源点

// 链式前向星存图
struct Edge {
    int to;
    long long w;
    int next;
} edge[5 * MAXN];  // 无向图开两倍
int head[MAXN];
int edge_cnt = 0;

void add_edge(int u, int v, long long w) {
    edge[++edge_cnt] = {v, w, head[u]};
    head[u] = edge_cnt;
}

// 距离数组
long long dist[MAXN];
bool vis[MAXN];

// 优先队列中存储 {距离, 节点}，小根堆
typedef pair<long long, int> pli;

void dijkstra(int s) {
    // 初始化
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        vis[i] = false;
    }
    dist[s] = 0;

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;  // 已确定，跳过（过期节点）
        vis[u] = true;

        // 遍历邻接边
        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            long long w = edge[i].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        // 无向图：add_edge(v, u, w);
    }

    dijkstra(s);

    for (int i = 1; i <= n; i++) {
        cout << dist[i];
        if (i < n) cout << " ";
    }
    cout << "\n";

    return 0;
}
