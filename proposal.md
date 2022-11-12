## Leading Question
We want to use Dijkstra's Algorithms to find the shortest path to any airport from a given airport using routes.dat from openflights. We use a weight for each edge that is a function of number of stops and throughput on the route to approximate its cost.

## Dataset Acquisition

### Data format
The data is routes.dat acquired from open flights. The data takes csv format, where each row representing an airline information with a source airport, a destination airport, number of stop, and airline info separated by comma. The whole data contains 67663 entries. We will use the whole dataset to build a airline network with each airport as a node and use the number of stops and throughput to calculate a weight for each edge that is a reasonable estimation of cost on that route. 

### Data correction
Since the data is essentially a csv format, we decide to use python csv reader to read each row. For each row, if either destination or source airport is missing, we discart that row. If the number of stops and other info is missing, we will give the average edge weight as an estimate of the edge weight and still continue to use it in the netowrk.

### Data storage
Since we are building a weighted directed graph to calculate shortest path, we will use an adjacency list to store the edge information. Specifically, we will use `Vector<Vector<double>> adj` to store the edge info, where the double value at `adj[i][j]` stores the edge weight between node i and node j. The storage cost is `O(n^2)` where n is the total number of nodes.

## Graph Algorithms

### Function input
The input is the adjacency list described in the data storage section. For edge weight, we will compute an edge weight that is proportional to the number of stops and inversely proportional to the throughput between the two airports. We also need an input of a specific airport as the starting point for the shortest path.

### Function Outputs
Since the input already takes an arbitrary airport as the starting point, the output is just an array of size `O(n)` representing the path length of the shortest path from that starting airport to any other airport

### Function efficiency
Since we use Dijkstra's Algorithms, the target time efficiency is `O((|V|+|E|)log|V|)`. We will use a priority queue to select the next node to visit in Dijkstra's algorithms. The data reading and storage takes an optimal of `O(|E|)` . The node and edge construction takes `O((|V|+|E|))` time.

## Timeline
- [ ] Reading raw csv data into adjacency list
- [ ] Compute edge weight based on throughput and number of stops and construct node and edges of the network.
- [ ] Implement BFS structure of the Dijkstra's Algorithms
- [ ] Complete Dijkstra's Algorithms and obtain the expected output format
- [ ] Test the implementation with the dataset and some other randomly genenrated dataset
- [ ] Writeup the final report and demo PPT