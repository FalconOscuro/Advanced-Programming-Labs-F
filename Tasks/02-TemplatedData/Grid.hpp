#ifndef GRID_HPP
#define GRID_HPP

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class Grid
{
public:
    Grid():
        m_Grid()
    { };

    ~Grid()
    { };

    bool LoadGrid(const char filename[])
    {
        ifstream gridFile(filename);
        if (!gridFile)
            return false;

        // Temp array in case read fails due to improperly formatted file
        int grid[9][9];
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                // Ensure end of file has not been reached yet
                if (gridFile.peek() == EOF)
                    return false;

                gridFile >> grid[i][j];
            }

        if (gridFile.peek() != EOF)
            return false;

        // Copy temp array
        copy(&grid[0][0], &grid[0][0] + (9 * 9), &m_Grid[0][0]);
        return true;
    };

    void SaveGrid(const char filename[])
    {
        ofstream outFile(filename);
        if (!outFile)
            return;

        // Can just re-use overloaded << operator
        outFile << *this;
    };

    friend ostream& operator<<(ostream& os, const Grid& grid)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                os << grid.m_Grid[i][j];

                if (j < 8)
                    os << ' ';
            }

            if (i < 8)
                os << '\n';
        }
        return os;
    };

    friend istream& operator>>(istream& is, Grid<T>& grid)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                is >> grid.m_Grid[i][j];

        return is;
    };

private:
    T m_Grid[9][9];
};

#endif // GRID_HPP