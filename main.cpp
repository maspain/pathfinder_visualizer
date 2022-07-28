#include "Pathfinder.h"


int main(int argc, char ** argv) {
    Pathfinder pf;
    pf.readMap();
    pf.printMap();
    pf.getInitialPositions();
}
