#include <iostream>
#include <random>
#include <vector>
using namespace std;

void printBoard(vector<vector<int>> coordinates){
    for(int i = 0; i < coordinates.size(); i++){
        for(int j = 0; j < coordinates[0].size(); j++){
            cout << coordinates[i][j] << "   ";
        }
        cout << endl;
    }
}

// check next to a dot
bool check(vector<vector<int>> coordinates, int new_point_x, int new_point_y){
    int size = coordinates.size();

    if (new_point_x + 1 < size && coordinates[new_point_x + 1][new_point_y] == 1) return true;
    if (new_point_x - 1 >= 0 && coordinates[new_point_x - 1][new_point_y] == 1) return true;
    if (new_point_y + 1 < size && coordinates[new_point_x][new_point_y + 1] == 1) return true;
    if (new_point_y - 1 >= 0 && coordinates[new_point_x][new_point_y - 1] == 1) return true;

    return false;
}

// void search
pair<int, int> walk(vector<vector<int>> coordinates, int length){
    // add and delete a coordinate until we find it next to cube
    // but we can't just randomly add a random point until it's next to another point, that wouldn't be walking
    // possibly use a pointer and then make a new pointer that's a cube_length away and then delete the first pointer
    // check the second pointer

    random_device rd;
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dist(0, length - 1); // distribution for coordinates
    uniform_int_distribution<> walk_dist(0, 3);      // distribution for walk direction

    int init_x = dist(rd), init_y = dist(rd);

    coordinates[init_x][init_y] = 1;

    // if somehow it lands on the initial box, rerun it
    if(init_x == length / 2 || init_y == length / 2){

        // walk(coordinates, length);
    }

    // the real search algorithm

    while(!check(coordinates, init_x, init_y)){
        int rand_walk = dist(rd) % 4;
        switch(rand_walk){
            default:
                break;
            case 0:
                init_x += 1;
            case 1:
                init_y += 1;
            case 2:
                init_x -= 1;
            case 3:
                init_y -= 1;
        }
    }

    return make_pair(init_x, init_y);
}

int main() {
    // using a coordinate system
    int start_dimension = 10;
    int cube_length = 1;

    int threshold = (start_dimension ^ 2) / 7;

    // initialize an empty board
    vector<vector<int>> coordinates(start_dimension, vector<int>(start_dimension, 0));
    for(int rows = 0; rows < start_dimension; rows++){
        for(int cols = 0; cols < rows; cols++){
            coordinates[rows][cols] = 0;
        }
    }

    // putting a "block" on
    coordinates[start_dimension/2][start_dimension/2] = 1;

    // the meat of the algorithm is here
    for(int i = 0; i < threshold; i++){
        pair<int, int> coords = walk(coordinates, start_dimension);
        coordinates[coords.first][coords.second] = 1;
        printBoard(coordinates);
    }

    // step one: make a small dla algorithm with small start dimensions
    // step two: once a certain percentage of the "board" is complete, increase the start dimensions
    // step three: scale the small board to the size of the new board
    // step four: run the algorithm again

    return 0;
}
