#include "Grid.hpp"

#include <iostream>
using namespace std;

int main()
{
    Grid<int> grid;
    grid.LoadGrid("Grid1.txt");
    grid.SaveGrid("OutGrid.txt");

    cout << grid << endl;
}