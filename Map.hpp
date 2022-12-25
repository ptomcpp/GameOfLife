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
            fillMap(initialXCoords, initialYCoords);
        }
        else
        {
            initializeMap(50, 50);
            fillMap(initialXCoords, initialYCoords);
        }
    };
    std::vector<std::vector<Point>> giveMap()
    {
        return map;
    }

    int countNeighbours(int Xcord, int Ycord)
    {
        int neighbours{};
        for (int j = -1; j < 2; j++)
        {
            for (int i = -1; i < 2; i++)
            {
                int Ycoord = Ycord + j;
                int Xcoord = Xcord + i;
                if (Ycoord >= 0 && Ycoord < map.size() && Xcoord >= 0 && Xcoord < map.at(0).size())
                {
                    if (map.at(Ycord + j).at(Xcord + i).showExistance())
                        neighbours++;
                }
            }
        }
        if (map.at(Ycord).at(Xcord).showExistance())
            neighbours--;
           //std::cout<<"X: "<<Xcord<<"Y : "<<Ycord<<"neighbors: "<<neighbours<<std::endl;
        return neighbours;
    }

    void updateMap()
    {
        std::vector<std::vector<Point>> NewMap = map;
        for (int y = 0; y < map.size(); y++)
        {
            for (int x = 0; x < map.at(0).size(); x++)
            {
                if (map.at(y).at(x).checkExistance(countNeighbours(x, y)))
                {
                    NewMap.at(y).at(x).makeExist();
                }
                else
                    NewMap.at(y).at(x).makeNotExist();
            }
        }
        map=NewMap;
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