#include "coordinate.h"
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

static int id_counter = 1; // Global counter for coord_id

void add_coordinate(Coordinate*& list_end, float x, float y) {
    Coordinate* new_coord = new Coordinate{x, y, id_counter++, nullptr, list_end};

    if (list_end) {
        list_end->next = new_coord;
    }
    list_end = new_coord;
}

void forward_display(Coordinate* list_beginning) {
    cout << "Forward List Display:" << endl;
    while (list_beginning) {
        cout << "ID: " << list_beginning->coord_id 
             << " (X: " << list_beginning->x 
             << ", Y: " << list_beginning->y << ")" << endl;
        list_beginning = list_beginning->next;
    }
}

void backward_display(Coordinate* list_end) {
    cout << "Backward List Display:" << endl;
    while (list_end) {
        cout << "ID: " << list_end->coord_id 
             << " (X: " << list_end->x 
             << ", Y: " << list_end->y << ")" << endl;
        list_end = list_end->previous;
    }
}

void delete_coordinate(Coordinate*& list_beginning, int coord_id_to_delete) {
    Coordinate* current = list_beginning;

    while (current) {
        if (current->coord_id == coord_id_to_delete) {
            if (current->previous) {
                current->previous->next = current->next;
            } else {
                list_beginning = current->next;
            }

            if (current->next) {
                current->next->previous = current->previous;
            }

            delete current;
            cout << "Coordinate ID " << coord_id_to_delete << " deleted." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Coordinate ID " << coord_id_to_delete << " not found." << endl;
}

int list_length(Coordinate* list_beginning) {
    int count = 0;
    while (list_beginning) {
        count++;
        list_beginning = list_beginning->next;
    }
    return count;
}

void closest_to(Coordinate* list_beginning, float x, float y) {
    if (!list_beginning) {
        cout << "The list is empty." << endl;
        return;
    }

    Coordinate* closest = list_beginning;
    float min_distance = numeric_limits<float>::max();

    while (list_beginning) {
        float dist = sqrt(pow(list_beginning->x - x, 2) + pow(list_beginning->y - y, 2));
        if (dist < min_distance) {
            min_distance = dist;
            closest = list_beginning;
        }
        list_beginning = list_beginning->next;
    }

    cout << "Closest coordinate to (" << x << ", " << y << ") is ID: " 
         << closest->coord_id << " (X: " << closest->x 
         << ", Y: " << closest->y << ") with distance: " << min_distance << endl;
}

void free_memory(Coordinate*& list_beginning) {
    while (list_beginning) {
        Coordinate* temp = list_beginning;
        list_beginning = list_beginning->next;
        delete temp;
    }
}

