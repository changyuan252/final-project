#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <queue>

using namespace std;

#define INF 100000


vector<vector<array<int,2>>> readData(string fname);
vector<int> dijkstra(int start, vector<vector<array<int,2>>> adj);

int main() {
    vector<vector<array<int,2>>> adj_list = readData("routes.csv");
    vector<int> dist = dijkstra(0, adj_list);

    assert(dist[0]==0);
    cout << "Test Case #1 passed\n";
 
    assert(dist[1]==1);
    cout << "Test Case #2 passed\n";

    assert(dist[3]==2);
    cout << "Test Case #3 passed\n";

    assert(dist[13]==1);
    cout << "Test Case #4 passed\n";

    return 0;
}


vector<vector<array<int,2>>>  readData(string fname) {
    fstream fin;
    vector<vector<string>> rows；
    string line, word;
    vector<vector<array<int,2>>>  adj;


    fin.open("routes.csv", ios::in);

    map<string, int> m;

    int idx = 0;
    while (getline(fin, line)) {
        vector<string> row;
        stringstream str(line);
        while(getline(str, word, ',')) {
            row.push_back(word);
        }
        if (m.find(row[2]) == m.end()) {
            m[row[2]] = idx++;
        }
        if (m.find(row[4]) == m.end()) {
            m[row[4]] = idx++;
        }
        rows.push_back(row);
    }

    cout << "building adjacency list with " << idx << " different nodes" << endl;

    for(int i=0; i<idx; i++) {
        vector<array<int,2>> adj_row;
        adj.push_back(adj_row);
    }
    for(int i=0; i<rows.size(); i++) {
        vector<string> row_array = rows[i];
        int a = m[row_array[2]];
        int b = m[row_array[4]];
        adj[a].push_back({1,b});
        adj[b].push_back({1,a});
    }
    return adj;

}


vector<int> dijkstra(int start, vector<vector<array<int,2>>> adj_list) {
    vector<int> dist;
    for(int i=0; i<adj_list.size(); i++) {
        dist.push_back(INF);
    }

    priority_queue<array<int, 2>, vector<array<int,2>>, greater<array<int, 2>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if (dist[t[1]] <= t[0])
            continue;
        dist[t[1]] = t[0];
        for (auto neighbor : adj_list[t[1]])
            pq.push({t[0] + neighbor[0], neighbor[1]});
    }
    return dist;
}
