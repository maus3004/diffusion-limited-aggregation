#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    int user_seed;
    cout << "Enter seed: ";
    cin >> user_seed;
    srand(user_seed);

    // using a coordinate system
    int start_dimension_x = 100, start_dimension_y = 100;
    int cube_length = 1;

    // begin with a

    vector<vector<int>> coordinates = {{start_dimension_x / 2, start_dimension_y / 2}, {10, 10}, {5, 5}};

    for(const auto& point : coordinates){
        cout << "(" << point.at(0) << ", " << point.at(1) << ")" << endl;
    }

    // step one: make a small dla algorithm with small start dimensions
    // step two: once a certain percentage of the "board" is complete, increase the start dimensions
    // step three: scale the small board to the size of the new board
    // step four: run the algorithm again

    return 0;
}