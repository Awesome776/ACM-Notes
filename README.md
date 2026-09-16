# ACM 竞赛知识点仓库

> 记录 ACM-ICPC / CCPC 竞赛学习笔记与竞赛代码模板，按算法分类组织，持续更新中。

## 仓库结构

```
.
├── notes/              # 知识点笔记（Markdown 格式）
│   ├── basic/           # 基础算法（排序、二分、贪心...）
│   ├── data-structure/  # 数据结构（线段树、并查集、树状数组...）
│   ├── graph/           # 图论（最短路、最小生成树、网络流...）
│   ├── dp/              # 动态规划（背包、树形DP、状压DP...）
│   ├── string/          # 字符串（KMP、Trie、AC自动机、SAM...）
│   ├── math/            # 数学（数论、组合数学、矩阵快速幂...）
│   ├── geometry/        # 计算几何（凸包、旋转卡壳、半平面交...）
│   └── misc/            # 杂项（位运算、博弈论、随机化...）
├── templates/          # 竞赛代码模板（可直接复制使用）
│   ├── basic/
│   ├── data-structure/
│   ├── graph/
│   ├── dp/
│   ├── string/
│   ├── math/
│   ├── geometry/
│   └── misc/
└── docs/
    └── study-guide.md   # 学习路线与刷题指南
```

## 分类索引

### 基础算法 (Basic)

| 笔记 | 模板 | 简介 |
|------|------|------|
| [排序算法](notes/basic/sort.md) | — | 快排、归并、堆排及 STL 排序技巧 |
| [二分查找](notes/basic/binary-search.md) | [binary_search.cpp](templates/basic/binary_search.cpp) | 整数二分、浮点二分、STL 用法 |

### 数据结构 (Data Structure)

| 笔记 | 模板 | 简介 |
|------|------|------|
| [线段树](notes/data-structure/segment-tree.md) | [segment_tree.cpp](templates/data-structure/segment_tree.cpp) | 区间修改、区间查询、懒标记 |

### 图论 (Graph)

| 笔记 | 模板 | 简介 |
|------|------|------|
| [最短路径](notes/graph/shortest-path.md) | [dijkstra.cpp](templates/graph/dijkstra.cpp) | Dijkstra、Bellman-Ford、Floyd |

### 数学 (Math)

| 笔记 | 模板 | 简介 |
|------|------|------|
| — | [fast_power.cpp](templates/math/fast_power.cpp) | 快速幂、龟速乘 |

## 使用方式

### VSCode 中编辑与提交

1. 用 VSCode 打开本仓库根目录
2. 安装推荐扩展（弹出提示时点击安装）：
   - **C/C++**（Microsoft）— 语法高亮与调试
   - **Code Runner**（Jun Han）— 一键编译运行
   - **Competitive Programming Helper**（ Agrawal）— 竞赛专用辅助
3. 编辑笔记或模板后，在 VSCode 左侧 **源代码管理** 面板提交：
   - 输入提交信息 → 点击 `✓` 提交
   - 点击 `同步更改` 推送到 GitHub

### 模板使用

竞赛模板中的 `.cpp` 文件均可直接复制使用。每个模板包含：
- 文件头注释（算法名、时间复杂度、空间复杂度）
- 完整的可编译代码（含 `main` 函数）
- 关键步骤的中文注释

## 学习进度

- [x] 基础算法（排序、二分）
- [x] 数据结构（线段树）
- [x] 图论（最短路）
- [ ] 动态规划
- [ ] 字符串算法
- [ ] 数学（数论）
- [ ] 计算几何
- [ ] 杂项

## License

本仓库为个人学习笔记，仅供学习交流使用。
