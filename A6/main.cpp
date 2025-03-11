#include "coordinate.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./main <number_of_coordinates>" << endl;
        return 1;
    }

    int num_coords = atoi(argv[1]);
    if (num_coords <= 0) {
        cout << "Please enter a valid number of coordinates." << endl;
        return 1;
    }

    srand(time(0));

    Coordinate* list_beginning = nullptr;
    Coordinate* list_end = nullptr;

    for (int i = 0; i < num_coords; i++) {
        float x = static_cast<float>(rand() % 100);
        float y = static_cast<float>(rand() % 100);

        if (!list_beginning) {
            list_beginning = list_end = new Coordinate{x, y, i + 1, nullptr, nullptr};
        } else {
            add_coordinate(list_end, x, y);
        }
    }

    forward_display(list_beginning);
    backward_display(list_end);

    cout << "List Length: " << list_length(list_beginning) << endl;

    float test_x, test_y;
    cout << "Enter x and y coordinates to find the closest point: ";
    cin >> test_x >> test_y;

    closest_to(list_beginning, test_x, test_y);

    int delete_id;
    cout << "Enter coordinate ID to delete: ";
    cin >> delete_id;
    delete_coordinate(list_beginning, delete_id);

    forward_display(list_beginning);

    free_memory(list_beginning);

    return 0;
}
