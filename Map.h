
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


struct Coordinate {
    int x;
    int y;
};

class Map {
    public:
        void readMap();
        void printMap();
        void getInitialPositions();
    private:
        std::vector<std::vector<bool>> map;
        Coordinate start;
        Coordinate finish;
};