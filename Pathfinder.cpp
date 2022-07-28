#include "Pathfinder.h"

using std::cout;
using std::cin;
using std::string;

void Pathfinder::readMap() {
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

    std::cin >> height >> width;
    map.resize(height, std::vector<bool>(width));

    std::getline(std::cin >> std::ws, buffer);
    while (std::getline(input_file, buffer)) {
        
        std::cout << buffer << "\n";
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

void Pathfinder::printMap() {
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[0].size(); j++) {
            
            std::cout << map[i][j];
        }
        std::cout << "\n";
    }
} 

void Pathfinder::getInitialPositions() {

    cout << "Enter an inital position: ";
    cin >> start;
    cout << "\n";
    cout << "Enter a final positon: ";
    cin >> finish;
    cout << "\n";
}

