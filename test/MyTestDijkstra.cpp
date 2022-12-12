#include <vector>
#include <iostream>
#include "../dijkstra.h"
#include "MyTestDijkstra.h"

#include <string>
using namespace std;

// start node should have 0 distance from itself
void test1() {
	vector<vector<array<int,2>>> adj_list = readData("routes.csv");
	vector<int> dist = dijkstra(0, adj_list);
	assert(dist[0]==0);
    cout << "Test Case #1 passed\n";
}


void test2() {
	vector<vector<array<int,2>>> adj_list = readData("routes.csv");
	vector<int> dist = dijkstra(0, adj_list);
    assert(dist[1]==1);
    cout << "Test Case #2 passed\n";
}


void test3() {
	vector<vector<array<int,2>>> adj_list = readData("routes.csv");
	vector<int> dist = dijkstra(0, adj_list);
    assert(dist[3]==2);
    cout << "Test Case #3 passed\n";
}


void test4() {
	vector<vector<array<int,2>>> adj_list = readData("routes.csv");
	vector<int> dist = dijkstra(0, adj_list);
    assert(dist[13]==1);
    cout << "Test Case #4 passed\n";
}

void runTest() {
	test1();
	test2();
	test3();
	test4();

	// vector<vector<array<int,2>>> adj_list = readData("routes.csv");
	// vector<int> dist = dijkstra(0, adj_list);
	// int notp = 0;
	// double s = 0;
	// double l = 0;
 //    for (int i = 0; i < dist.size(); i++) {
 //        cout << dist[i] << " ";
 //        if (dist[i] == 100000)
 //        	notp++;
 //        else {
 //        	l++;
 //        	s += dist[i];
 //        }
 //    }
 //    cout << notp << endl;
 //    cout << s/l << endl;

}