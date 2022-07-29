#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>


struct Coordinate {
    int row;
    int col;
};

class Map {
    public:
        Map () {
            start.row = 0;
            start.col = 0;
            finish.row = 0;
            finish.col = 0;
        }
        // Copy constructor (Not necessary w/o heap allocation but just in case)
        Map (const Map &old_map) {
            start = old_map.start;
            finish = old_map.finish;
        }

        void readMap();
        void printMap();
        void getInitialPositions();
        bool isWall(int row, int col); 
    private:
        std::vector<std::vector<bool>> map;
        Coordinate start;
        Coordinate finish;
};
#endif /* MAP_H */