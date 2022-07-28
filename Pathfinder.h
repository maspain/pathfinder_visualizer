#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Pathfinder {
public:
    void readMap();
    void printMap();
    void getInitialPositions();
private:
    class Node {
        public:
            Node()
            :east(NULL), north(NULL), south(NULL), west(){}

        private:
        Node* east;
        Node* north;
        Node* south;
        Node* west;
        
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