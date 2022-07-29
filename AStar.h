#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>


struct Coordinate {
    int x;
    int y;
};

class Pathfinder {
public:
    void readMap();
    void printMap();
    void getInitialPositions();
private:
    class Node {
        public:
            Node()
            : g_cost(0), h_cost(0) {}
            
        private:
        /*  
        *   G cost represents distance from starting node
        *   H cost represents distance from end node
        *   F cost sum of G and H cost
        */
        int g_cost;
        int h_cost; 
        
    };
    // currently a map representing where the walls are located (0 = free space; 1 = wall)
    std::vector<std::vector<bool>> map;
    
    // represents index in map if each element was given a unique sequential integer
    // space = row * num_rows + col
    // row = space / size
    // col = space % size
    int start;
    int finish;
};
#endif /* PATHFINDER_H */