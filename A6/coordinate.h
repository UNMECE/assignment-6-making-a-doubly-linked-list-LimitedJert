#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <cmath>

struct Coordinate {
    float x;
    float y;
    int coord_id;
    Coordinate* next;
    Coordinate* previous;
};

void add_coordinate(Coordinate*& list_end, float x, float y);
void forward_display(Coordinate* list_beginning);
void backward_display(Coordinate* list_end);
void delete_coordinate(Coordinate*& list_beginning, int coord_id_to_delete);
int list_length(Coordinate* list_beginning);
void closest_to(Coordinate* list_beginning, float x, float y);
void free_memory(Coordinate*& list_beginning);

#endif
