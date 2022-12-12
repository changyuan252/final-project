#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>
#include "tarjans.h"
#include "test/MyTestTarjans.h"

using namespace std;



int main() {
	// vector<vector<int>> adj = buildAdj("routes.csv");

	// // for (int i = 0; i < (int) adj.size(); ++i){
 // //        std::cout << "{ ";
 // //        for(int j = 0; j < (int) adj[i].size()-1; ++j){
 // //        std::cout << adj[i][j] << ", ";
 // //        }
 // //        std::cout << adj[i][adj[i].size()-1] << "}, \\" << std::endl;
 // //    }

	// vector<vector<int>> scc = tarjans(adj);
	// // for (int i = 0; i < (int) scc.size(); ++i){
 // //        std::cout << "{ ";
 // //        for(int j = 0; j < (int) scc[i].size()-1; ++j){
 // //        std::cout << scc[i][j] << ", ";
 // //        }
 // //        std::cout << scc[i][adj[i].size()-1] << "}, \\" << std::endl;
 // //    }
 // 	cout << scc[1].size() << endl;	
	runTest();
    return 0;
}

vector<vector<int>> buildAdj(string fname) {
	fstream fin;

    // used to store the temporary parsing results of text data
    //each vector<string> represents a row in rows
    vector<vector<string>> rows;

    // line is used to read and store each line in file during the loop
    // word is used to store each word separate by the comma in a line 
    string line, word;

    // store adjacency list in adj
    vector<unordered_set<int>>  adj_list;


    fin.open(fname, ios::in);

    // used to the the mapping from each airport name to a node index
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

    for(int i=0; i<idx; i++) {
        unordered_set<int> neighbors;
        adj_list.push_back(neighbors);
    }

    for(int i=0; i< (int) rows.size(); i++) {
        vector<string> row_array = rows[i];
        int a = m[row_array[2]];
        int b = m[row_array[4]];
        adj_list[a].insert(b);
        adj_list[b].insert(a);
    }

    vector<vector<int>> adj;
    for(int i=0; i<idx; i++) {
        vector<int> neighbors;
        neighbors.insert(neighbors.end(), adj_list[i].begin(), adj_list[i].end());
        adj.push_back(neighbors);
    }
    return adj;
}



vector<vector<int>> tarjans(vector<vector<int>> adj) {
	int n = (int) adj.size();
	int index[n], lowlink[n];
	bool current[n];
	int idx = 0;
	stack<int> curVis;
	for(int i=0; i < n; i++) {
		index[i] = -1;
		lowlink[i] = -1;
	}
	vector<vector<int>> scc;
	for (int i = 0; i < n; i++) {
        if (index[i] == -1)
            dfs(scc, adj, idx, i, index, lowlink, curVis, current);
	}
	return scc;
}

void dfs(vector<vector<int>> &scc, vector<vector<int>> &adj, int &idx, int cur, int index[], int lowlink[], stack<int> &curVis, bool current[]) {
	index[cur] = lowlink[cur] = idx++;
    current[cur] = true;
    curVis.push(cur);
    for (auto v : adj[cur]) {
        if (index[v] == -1)
            dfs(scc, adj, idx, v, index, lowlink, curVis, current);
        if (current[v])
            lowlink[cur] = min(lowlink[cur], lowlink[v]);
    }

    if (index[cur] == lowlink[cur]) {
    	vector<int> component; 
        while (curVis.top() != cur) {
            int t = curVis.top();
            component.push_back(t);
            curVis.pop();
            lowlink[t] = lowlink[cur];
            current[t] = false;
        }
        component.push_back(curVis.top());
        curVis.pop();
        current[cur] = false;
        scc.push_back(component);
    }
}