#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <fstream>


const std::string filename = "graph.txt";


std::vector<int> bfs(const std::vector<std::vector<int>>& g, int s) {
    int n = g.size();
    std::queue<int> q;
    std::vector<int> d(n, -1);
    d[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int to : g[v]) {
            if(d[to] != -1) {
                continue;
            }
            d[to] = d[v] + 1;
            q.push(to);
        }
    }
    return d;
}


int main() {

    int n, m;
    int s;
    
    std::ifstream in(filename);
    if(!in.is_open()) {
        return 1;
    }

    in >> n >> m;
    std::vector<std::vector<int>> g(n);
    for(size_t i = 0; i < m; i++) {
        int u, v;
        in >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    in >> s;

    in.close();

    for(auto x : bfs(g, s)) {
        std::cout << x << '\n';
    }

    return 0;
}
