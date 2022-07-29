#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Map.h"

class AStar: public Map {
public:
    AStar(Map in_maze)
    : maze(in_maze) {}
    void initAlgorithim() {

    }

private:
    class Node {
        public:
            Node()
            : g_cost(0), h_cost(0){}
            
        private:
        /*  
        *   G cost represents distance from starting node
        *   H cost represents distance from end node
        *   F cost sum of G and H cost
        */
        int g_cost;
        int h_cost; 
        int f_cost;
    };
    // currently a map representing where the walls are located (0 = free space; 1 = wall)
    
    // represents index in map if each element was given a unique sequential integer
    // space = row * num_rows + col
    // row = space / size
    // col = space % size
    Map maze;
    Coordinate start;
    Coordinate finish;
};
#endif /* ASTAR_H */