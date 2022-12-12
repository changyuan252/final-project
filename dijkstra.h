#include <string>
#include <vector>
#include <array>

#pragma once

#define INF 100000


using namespace std;


/*
 * @param fname the file name to read the data from
 * @return a adjacency list of the graph build. it is a 2D vector of 2-element array
 * the 2-element array functions as a pair with the first element representing the edge weight
 * and the second element representing the index of node
 */
vector<vector<array<int,2>>> readData(string fname);


/*
 * @param start the starting node index to perform the dijkstra
 * @return a vector of int representing the calculated distance from the start node to all nodes
 */
vector<int> dijkstra(int start, vector<vector<array<int,2>>> adj);