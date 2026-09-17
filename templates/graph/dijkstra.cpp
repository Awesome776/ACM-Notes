/*
 * Dijkstra 最短路（优先队列优化）
 * Time: O((V+E) log V)  Space: O(V+E)
 *
 * 功能：非负权图单源最短路径
 * 图存储：链式前向星
 *
 * 关键步骤：
 *   - 取堆顶后若 d > dist[u] 则跳过（过期节点）
 *   - 松弛：dist[u] + w < dist[v] 时更新并入堆
 *
 * 编译：g++ -std=c++17 -O2 -o dijkstra dijkstra.cpp
 */

#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m, s;

struct Edge { int to; long long w; int next; } edge[5 * MAXN];
int head[MAXN], edge_cnt = 0;

void add_edge(int u, int v, long long w) {
    edge[++edge_cnt] = {v, w, head[u]};
    head[u] = edge_cnt;
}

long long dist[MAXN];
bool vis[MAXN];

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) { dist[i] = INF; vis[i] = false; }
    dist[s] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;  // 过期节点
        vis[u] = true;
        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to; long long w = edge[i].w;
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
        int u, v; long long w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << (i < n ? " " : "\n");
    return 0;
}
