#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define INF numeric_limits<double>::infinity()


vector<vector<double>> readData(string fname);
vector<int> dijkstra(int start, vector<vector<double>> adj);

int main() {
    readData("routes.csv");
    return 0;
}



vector<vector<double>> readData(string fname) {
    fstream fin;
    vector<vector<string>> rows; 
    string line, word;
    vector<vector<double>> adj;


    fin.open("routes.csv", ios::in);
    map<string, int> m;

    int idx = 0;
    while (getline(fin, line)) {
        vector<string> row;
        stringstream str(line);
        while(getline(str, word, ',')) {
            row.push_back(word);
        }
        // used for print out the content of a vector 
        // for (int i = 0; i < row.size(); i++) {
        //     cout << row[i] << " ";
        // }
        // cout << endl;

        if (m.find(row[2]) == m.end()) {
            m[row[2]] = idx++;
        }
        if (m.find(row[4]) == m.end()) {
            m[row[4]] = idx++;
        }
        rows.push_back(row);
    }

    cout << "building adjacency matrix with " << idx << " different nodes" << endl;
    for(int i=0; i<m.size(); i++) {
        vector<double> adj_row;
        for(int j=0; j<m.size(); j++) {
            if (i==j) {
                adj_row.push_back(0);
            } else {
                adj_row.push_back(INF);
            }
        }
        adj.push_back(adj_row);
    }

    for(int i=0; i<rows.size(); i++) {
        vector<string> row_array = rows[i];
        int a = m[row_array[2]];
        int b = m[row_array[4]];
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    // used for print out the content of a whole map
    // for (const auto& [key, value] : m)
    //         std::cout << '[' << key << "] = " << value << "; ";
    return adj;

}


// vector<int> dijkstra(int start, vector<vector<double>> adj) {
//     int dist[adj.size()];
//     fill(begin(dist), end(dist), INF);
//     priority_queue<array<int, 2>, vector<array<int,2>>, greater<array<int, 2>>> pq;
//     pq.push({0, start});
//     while (!pq.empty()) {
//         auto t = pq.top();
//         pq.pop();
//         if (dist[t[1]] <= t[0])
//             continue;
//         dist[t[1]] = t[0];
//         for (auto i : adj[t[1]])
//             pq.push({t[0] + i[0], i[1]});
//     }
// }