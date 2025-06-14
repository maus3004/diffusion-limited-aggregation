#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;



// void search
void walk(vector<vector<int>> coordinates, int cube_length, int length_x, int length_y){
    // add and delete a coordinate until we find it next to cube
    // but we can't just randomly add a random point until it's next to another point, that wouldn't be walking
    // possibly use a pointer and then make a new pointer that's a cube_length away and then delete the first pointer
    // check the second pointer

    int row = rand(0, length_x), col = rand(0, length_y);


}

int main() {
    int user_seed;
    cout << "Enter seed: ";
    cin >> user_seed;
    srand(user_seed);

    // using a coordinate system
    int start_dimension_x = 10, start_dimension_y = 10;
    int cube_length = 1;

    int threshold = (start_dimension_x * start_dimension_y) / 7;

    // begin with a
    vector<vector<int>> coordinates = {};

    // the meat of the algorithm is here
    for(int i = 0; i < threshold; i++){
        walk(coordinates, cube_length, start_dimension_x, start_dimension_y);
    }

    for(const auto& point : coordinates){
    }

    // step one: make a small dla algorithm with small start dimensions
    // step two: once a certain percentage of the "board" is complete, increase the start dimensions
    // step three: scale the small board to the size of the new board
    // step four: run the algorithm again

    return 0;
}