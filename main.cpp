#include "AStar.h"
#include "Map.h"

int main(int argc, char ** argv) {
    Map pf;
    pf.readMap();
    pf.printMap();
    pf.getInitialPositions();
}
