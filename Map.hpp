#pragma once
#include "Point.hpp"
// #include "Map.cpp"
#include <vector>
#include <iostream>
class Map
{
public:
    Map(int sizeX = 50, int sizeY = 50)
    {
        if (sizeX > 0 && sizeY > 0)
        {
            initializeMap(sizeX, sizeY);
        }
        else
            initializeMap(50, 50);
    };

    Map(std::vector<int> &initialXCoords, std::vector<int> &initialYCoords, int sizeX = 50, int sizeY = 50)
    {
        if (sizeX > 0 && sizeY > 0)
        {
            initializeMap(sizeX, sizeY);
            fillMap(initialXCoords,initialYCoords);
        }
        else
        {
            initializeMap(50, 50);
            fillMap(initialXCoords,initialYCoords);
        }
    };
    std::vector<std::vector<Point>> giveMap()
    {
        return map;
    }

private:
    std::vector<std::vector<Point>> map;

    void initializeMap(int sizeX, int sizeY)
    {
        std::vector<Point> oneRow;
        for (int i = 0; i < sizeY; i++)
        {
            for (int j = 0; j < sizeX; j++)
            {
                Point newpoint(i, j);
                oneRow.push_back(newpoint);
            }
            map.push_back(oneRow);
            oneRow.clear();
        }
    }

    void fillMap(const std::vector<int> &initialXCoords, const std::vector<int> &initialYCoords)
    {
        for (int i = 0; i < initialXCoords.size(); i++)
        {
            map.at(initialYCoords.at(i)).at(initialXCoords.at(i)).makeExist();
        }
    }
};