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
        exist = true;
    }
        void makeNotExist()
    {
        exist = false;
    }
    void changeExistance()
    {
        exist = !exist;
    }
    bool checkExistance(int neighboursAmount)
    {
        if ((exist == false) && (neighboursAmount == 3))
        {
            return true;
        }
        else if ((exist == true) && ((neighboursAmount == 2) || (neighboursAmount == 3)))
        {
            return false;
        }
        else return exist;
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