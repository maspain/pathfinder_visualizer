#include "Map.h"


using std::string;
using std::cin;
using std::cout;

void Map::readMap() {
    int height, width;
    int row = 0;
    string filename;    
    string buffer;

    cout << "Enter maze filename: ";
    cin >> filename;
    std::ifstream input_file(filename);
    if (input_file.fail()) {
        std::cerr << "Error: input file not found\n";
        exit(1);
    }

    cin >> height >> width;
    map.resize(height, std::vector<bool>(width));

    //std::getline(std::cin >> std::ws, buffer);
    while (std::getline(input_file, buffer)) {
        // DEBUG std::cout << buffer << "\n"; 
        for (size_t i = 0; i < buffer.size(); i++) {

            //map is a 2D vector of boolean values representing the maze: 1 = wall; 0 = path
            if (buffer[i] == '#') {
               map[row][i] = 1;
            }
            else {
                map[row][i] = 0;
            }
        }
        row++;
    }
} //readMap()


void Map::printMap() {
    for (size_t i = 0; i < map.size(); i++) {
        cout << i << " | ";
        for (size_t j = 0; j < map[0].size(); j++) {
            
            std::cout << map[i][j];
            cout << " ";
        }
        std::cout << "\n";
    }
    cout << "    ";
    for (size_t i = 0; i < 2*map[0].size(); i++) {
        cout << "_";
    }
    cout << "\n";
    cout << "    ";
    for (size_t i = 0; i < map[0].size(); i++) {
        cout << i;
        cout << " ";
    }
    cout << "\n";
} 

void Map::getInitialPositions() {
    cout << "Enter an inital coordinate: ";
    cin >> start.row;
    cin >> start.col;
    while (isWall(start.row, start.col)) {
        cout << "Coordinate entered is a wall, please try again: ";
        cin >> start.row;
        cin >> start.col;
    }
    cout << "\n";

    cout << "Enter a final coordinate: ";
    cin >> finish.row;
    cin >> finish.col;
    while (isWall(finish.row, finish.col)) {
        cout << "Coordinate entered is a wall, please try again: ";
        cin >> finish.row;
        cin >> finish.col;
    }
    cout << "\n";    
}
// isWall: return value of 1 indicates wall at map[row][col]
bool Map::isWall(int row, int col) {
    if (map[row][col]) {
        return 1;
    }
    // default return, indicates free space
    return 0;
}

