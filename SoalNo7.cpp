#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>
using namespace std;

int getIndex(string s) {
    if(s == "Medan") return 0;
    if(s == "TebingTinggi") return 1;
    if(s == "Brastagi") return 2;
    if(s == "Pematangsiantar") return 3;
    if(s == "Sidikalang") return 4;
    if(s == "Parapat") return 5;
    return -1;
}

string getName(int i) {
    if(i == 0) return "Medan";
    if(i == 1) return "TebingTinggi";
    if(i == 2) return "Brastagi";
    if(i == 3) return "Pematangsiantar";
    if(i == 4) return "Sidikalang";
    if(i == 5) return "Parapat";
    return "";
}

int main() {
    
    int V = 6;
    vector<vector<pair<int,int>>> graph(V);
    graph[0].push_back({1,70});
    graph[0].push_back({2,60});
    graph[1].push_back({3,50});
    graph[2].push_back({4,90});
    graph[2].push_back({3,80});
    graph[3].push_back({5,45});
    graph[3].push_back({4,65});
    graph[4].push_back({5,120});

    string a,b;
    cout << "Kota Yang Tersedia: Medan, Tebing Tinggi, Brastagi, Pematangsiantar, Sidikalang, Parapat" << endl ; 
    cout << "Masukan Vertex Awal: ";
    cin >> a;
    cout << "Masukan Vertex Tujuan: ";
    cin >> b;
    int start = getIndex(a);
    int goal = getIndex(b);

    vector<long long> dist(V, numeric_limits<long long>::max());
    vector<int> parent(V, -1);
    dist[start] = 0;

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto &p : graph[u]) {
            int v = p.first;
            long long w = p.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> path;
    int curr = goal;
    while(curr != -1) {
        path.push_back(curr);
        if(curr == start) break;
        curr = parent[curr];
    }

    for(int i = path.size() - 1; i >= 0; i--) {
        cout << getName(path[i]);
        if(i != 0) cout << " -> ";
    }
    cout << endl;
    cout << dist[goal] << " km" << endl;
    return 0;
}