#include "../tarjans.h"
#include <vector>
#include <iostream>

using namespace std;
void testNumber() {
	vector<vector<int>> adj = buildAdj("routes.csv");
	vector<vector<int>> scc = tarjans(adj);
	assert(scc.size() == 8);
    cout << "Test Case #1 passed\n";
}



void runTest() {
	testNumber();
}