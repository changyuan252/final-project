#include <string>
#include <vector>
#include <array>
#include <stack>

#pragma once


using namespace std;


/*
 * @param fname the file name to read the data from
 * @return the adjacency list
 */
vector<vector<int>> buildAdj(string fname);


/*
 * @param the adjacency list
 * @return a 2D vector, each inner vector repsenting nodes inside one SCC
 */ 
vector<vector<int>> tarjans(vector<vector<int>> adj);


/*
 * @param pass in reference to store the SCC
 * @param the adj list
 * @param pass in idx to keep current index number of dfs
 * @param the current int
 * @param the dfs number saved for each node
 * @param the lowlink array
 * @param current stack of dfs
 * @param a bool array to keep track of which vertex has been visited
 */ 
void dfs(vector<vector<int>> &scc, vector<vector<int>> &adj, int &idx, int cur, int index[], int lowlink[], stack<int> &curVis, bool current[]);