## How to compile and run the code

### Run and Test dijkstra algorithms
- Compile the code with command `g++ -std=c++17 dijkstra.cpp test/MyTestDijkstra.cpp`.
- Run the code with `./a.out`

### Run and Test tarjan's algorithms
- Compile the code with command `g++ -std=c++14 tarjans.cpp test/MyTestTarjans.cpp`.
- Run the code with `./a.out`

## Structure of the code

### Codes for dijkstra
- `dijkstra.cpp` contains the implementation of the dijkstra algorithm, including input processing, and adjacency list construction.
- `test/MyTestDijkstra.cpp` contains the unit tests to test dijkstra with the provided data in `routes.csv`

### Codes for tarjan's
- `tarjans.cpp` contains the implementation of the tarjans algorithm, including input processing, and adjacency list construction.
- `test/MyTestTarjans.cpp` contains the unit tests to test tarjans with the provided data in `routes.csv`