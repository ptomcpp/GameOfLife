#pragma once
class Point
{
public:
    Point(int X, int Y, bool doesExist = false)
        : coordX{X}, coordY{Y}
    {
        exist = doesExist;
    };

    void makeExist()
    {
        exist=true;
    }
    void checkExistance(int neighboursAmount)
    {
        if ((exist == false) && (neighboursAmount == 3))
        {
            exist = true;
        }
        else if ((exist == true) && ((neighboursAmount == 2) || (neighboursAmount == 3)))
        {
            exist = false;
        }
    }
    bool showExistance()
    {
        return exist;
    }

private:
    int coordX;
    int coordY;
    bool exist;
};