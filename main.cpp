#include <iostream>
#include <cstdlib>
#include <random>
#include <vector>
using namespace std;



// void search
int walk(vector<vector<int>> coordinates, int cube_length, int length){
    // add and delete a coordinate until we find it next to cube
    // but we can't just randomly add a random point until it's next to another point, that wouldn't be walking
    // possibly use a pointer and then make a new pointer that's a cube_length away and then delete the first pointer
    // check the second pointer

    random_device rd;
    uniform_int_distribution<int> dist(0, length);
    int init_x = dist(rd), init_y = dist(rd);

    coordinates[init_x][init_y] = 1;

    // if somehow it lands on the initial box, rerun it
    if(init_x == length / 2 || init_y == length / 2){
        walk(coordinates, cube_length, length);
    }

    // the real search algorithm

    return init_x, init_y;

}

int main() {
    // using a coordinate system
    int start_dimension = 10;
    int cube_length = 1;

    int threshold = (start_dimension ^ 2) / 7;

    // initialize an empty board
    vector<vector<int>> coordinates = {};
    for(int rows = 0; rows < start_dimension; rows++){
        for(int cols = 0; cols < rows; cols++){
            coordinates[rows][cols] = 0;
        }
    }

    // putting a "block" on
    coordinates[start_dimension/2][start_dimension/2] = 1;

    // the meat of the algorithm is here
    for(int i = 0; i < threshold; i++){
        walk(coordinates, cube_length, start_dimension);
    }

    for(const auto& point : coordinates){
    }

    // step one: make a small dla algorithm with small start dimensions
    // step two: once a certain percentage of the "board" is complete, increase the start dimensions
    // step three: scale the small board to the size of the new board
    // step four: run the algorithm again

    return 0;
}