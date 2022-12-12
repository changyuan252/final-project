## Dijkstra Algorithm

### Output and correctness
- Eventually we build a undirected graph with 3425 nodes from `routes.csv`
- We have output the shortest distance of every node in the graph from node 0, we discover that: 
- 1. there are 28 nodes in total that is not reachable 
- 2. for all the reachable nodes, the average distance is 3.537
- The correctness is tested by investigating several points that we can find the shortest path through brute force (bfs); all test cases pass so the algorithms is fairly robust

### Leading question
- Our leading question is to find the shortest path to each node: (we display the distance to first several nodes for reference)
```
0 1 2 2 2 2 1 2 2 2 2 2 2 1 1 2 2 2 2 2 3 3 3 3 2 2 4 3 4 4 4 4 4 4 2 3 2 2 3 2 3 3 2 3 3 3 3 4 4 3 2 3 3 2 3 2 3 2 4 3 2 3 3 3 3 3 3 3 3 3 3 3 3 4 3 3 2 4 5 5 5 5 5 6 6 6 5 7 4 3 4 4 4 4 4 2 4 3 4 4 4 4 4 4 4 4 4 4 4 3 3 4 3 3 2 3 3 3 3 3 3 3 3 3 3 3 2 3 3 4 5 5 4 5 5 2 3 2 3 3 3 3 2 2 6 7 5 5 4 4 4 3 5 4 5 4 8 5 5 6 4 3 4 4 5 7 2 2 2 3 2 2 2 3 3 3 2 2 2 3 2 3 3 3 3 3 2 3 3 3 2 2 2 2 2 3 2 3 3 2 3 2 3 3 4 4 4 4 4 4 3 3 3 3 3 3 3 3 4 3 3 4 5 3 3 3 3 2 3 3 2 3 2 2 2 3 2 3 2 2 2 3 2 3 4 3 3 3 2 2 2 2 2 2 2 3 3 3 3 3 4 3 4 4 4 3 3 2 3 3 3 3 3 2 3 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 2 2 4 3 2 3 3 3 3 3 3 3 3 3 3 3 3 4 3 3 3 3 2 4 3 3 3 3 3 4 3 3 3 3 4 3 3 3 3 3 4 2 3 4 3 3 3 3 3 3 3 3 3 3 3 2 2 2 4 5 5 5 2 1 2 2 2 2 2 2 2 3 3 3 2 3 3 2 3 3 3 7 6 3 3 2 2 2 3 4 3 3 4 3 3 3 3 3 4 4 3 4 4 4 2 3 3 3 3 3 3 3 3 3 2 3 3 4 3 4 3 3 4 3 3 3 3 3 3 3 3 3 3 3 2 3 2 2 2 2 2 2 2 2 2 2 2 3 2 2 2 3 2 3 2 2 3 2 3 2 2 3 2 3 2 2 3 2 3 2 3 3 3 2 3 3 2 2 2 2 2 2 2 2 2 2 3 2 3 3 2 2 3 2 3 2 2 2 2 2 3 2 3 3 3 2 3 2 3 2 3 2 2 2 2 3 5 4 5 6 5 5 5 5 5 5 5 5 5 5 6 5 5 5 4 5 5 5 5 5 5 5 5 5 5 5 5 5 6 5 5 5 6 5 5 4 4 4 4 4 4 3 4 4 3 4 4 4 4 3 3 3 3 3 4 3 2 3 4 3 3 3 3 4 3 4 4 3 4 3 4 4 3 3 4 3 2 4 3 2 4 4 4 4 4 2 3 2 3 1 3 2 3 4 4 4 3 3 3 4 3 3 3 5 5 5 5 5 5 4 5 4 6 5 4 6 5 5 5 5 5 5 5 5 4 6 3 3 4 3 3 3 3 3 3 2 3 3 3 2 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 4 4 3 3 3 3 3 4 2 2 2 3 6 7 7 7 7 1 2 1 4 4 4 3 6 5 4 4 4 2 1 2 3 3 3 3 3 3 5 5 5 4 3 4 5 4 5 3 5 5 4 4 4 4 4 4 4 4 5 5 5 5 5 6 6 6 5 5 5 5 5 5 5 5 5 4 6 6 5 5 5 4 5 5 5 6 6 6 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 6 5 5 5 5 5 5 5 5 3 3 4 4 3 3 3 3 3 3 1 2 1 2 2 1 2 2 6 5 6 6 5 4 6 6 6 6 6 6 6 6 6 7 2 2 2 2 2 ...
```
- So our leading questions are solved and we even get some further logisitc: the average shortest path from starting airport to any other reachable airport is 3.537, meaning on average it takes around 3 to 4 flights to get from one airport to any other airport through OpenFlights network

## Tarjan's Question

### Output and correctness
- We find there are 8 strongly connected components, and test this against our algorithms.
- If time allows, we should also run a dfs to confirm that each points in our SCC is reachable from any other points in the same SCC. But we only verify several of them by hands and not write additional DFS to verify.

### Leading question
- Our leading question is to find all strongly connected components in the OpenFlight network, and we succeed to detect 8 SCC:
```
{ 3006, 3198, 3197, 677, 2527, 676, 3267, 2698, 2699, 3303, 2098, 2681, 2682, 3321, 3300, 3302, 3301, 2093, 2101, 681, 2091, 1844, 2278, 1783, 1772, 1782, 1417, 1440, 892, 710, 889, 984, 1428, 1438, 3330, 1415, 711, 979, 980, 854, 1436, 853, 847, 848, 379, 1411, 1425, 849, 852, 851, 857, 858, 859, 1412, 985, 855, 1437, 982, 977, 981, 978, 983, 987, 986, 3180, 3154, 3178, 2614, 2318, 1700, 1688, 1711, 2693, 2689, 2687, 2688, 2691, 2545, 2546, 2692, 3147, 3148, 2679, 3152, 3153, 3172, 2680, 2858, 2620, 948, 959, 962, 951, 960 ... }, \
{ 1825, 0}, \
{ 2426, 2425, 2417, 2686}, \
{ 2455, 3094}, \
{ 2685, 2690, 2686, 805306368}, \
{ 2937, 3134}, \
{ 3095, 3096, 3097, 3172}, \
{ 3135, 3136, 3138, 3140, 3139, 3137, 3141, 3133, 3134, 3141}, \
```
- We have discovered that the OpenFlight Network contains a very large SCC together with 7 pretty small SCC. Such pattern meets our original expectation, since we think flights network should be strongly connected for the most part to allow flights to be able to flow smoothly through each airport. 