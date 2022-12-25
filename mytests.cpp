#include <gtest/gtest.h>
#include "Point.hpp"
#include "Map.hpp"
#include <iostream>

TEST(PointExistanceFalseStart, PointTests)
{
    Point testPoint(0, 0);
    EXPECT_TRUE(!testPoint.showExistance());
}
TEST(PointExistanceTrueStart, PointTests)
{
    Point testPoint(0, 0, 1);
    EXPECT_TRUE(testPoint.showExistance());
}
TEST(PointExistanceFalseToTrueChange, PointTests)
{
    Point testPoint(0, 0);
    ;
    EXPECT_TRUE(testPoint.checkExistance(3));
}

TEST(PointExistanceNoChange, PointTests)
{
    Point testPoint(0, 0);
    EXPECT_TRUE(!testPoint.checkExistance(2));
    EXPECT_TRUE(!testPoint.checkExistance(0));
    EXPECT_TRUE(!testPoint.checkExistance(4));
}

TEST(PointExistanceTrueFalseChange, PointTests)
{
    Point testPoint(0, 0, true);
    EXPECT_TRUE(!testPoint.checkExistance(3));
    EXPECT_TRUE(!testPoint.checkExistance(2));
    EXPECT_TRUE(testPoint.checkExistance(4));
    EXPECT_TRUE(testPoint.checkExistance(0));
}

TEST(DefaultEmptyMapConstructor, MapCreationTests)
{
    Map newMap;
    EXPECT_EQ(50, newMap.giveMap().at(0).size());
    EXPECT_EQ(50, newMap.giveMap().size());
}

TEST(CorrectEmptyMapConstructor, MapCreationTests)
{
    Map newMap(40, 30);
    EXPECT_EQ(40, newMap.giveMap().at(0).size());
    EXPECT_EQ(30, newMap.giveMap().size());
}
TEST(WrongInputEmptyMapConstructor, MapCreationTests)
{
    Map newMap(0, -17);
    EXPECT_EQ(50, newMap.giveMap().at(0).size());
    EXPECT_EQ(50, newMap.giveMap().size());
}
TEST(CorrectInputFullMapConstructor, MapCreationTests)
{
    std::vector<int> X{1, 2};
    std::vector<int> Y{4, 5};
    Map newMap(X, Y, 10, 10);
    EXPECT_TRUE(newMap.giveMap().at(4).at(1).showExistance());
    EXPECT_TRUE(newMap.giveMap().at(5).at(2).showExistance());
    EXPECT_TRUE(!newMap.giveMap().at(1).at(1).showExistance());
}
TEST(WrongInputFullMapConstructor, MapCreationTests)
{
    std::vector<int> X{1, 2};
    std::vector<int> Y{4, 5};
    Map newMap(X, Y, -10, -10);
    EXPECT_TRUE(newMap.giveMap().at(4).at(1).showExistance());
    EXPECT_TRUE(newMap.giveMap().at(5).at(2).showExistance());
    EXPECT_TRUE(!newMap.giveMap().at(1).at(1).showExistance());
}

TEST(MapNeighboursMethodWorkingCorrectly, MapMethods)
{
    std::vector<int> X{0, 1, 0, 2, 0, 1, 2, 9};
    std::vector<int> Y{0, 0, 1, 1, 2, 3, 3, 9};
    Map newMap(X, Y, 10, 10);
    EXPECT_EQ(newMap.countNeighbours(1, 1), 5);
    EXPECT_EQ(newMap.countNeighbours(0, 0), 2);
    EXPECT_EQ(newMap.countNeighbours(3, 3), 1);
    EXPECT_EQ(newMap.countNeighbours(1, 2), 5);
    EXPECT_EQ(newMap.countNeighbours(9, 9), 0);
    EXPECT_EQ(newMap.countNeighbours(8, 9), 1);
}

TEST(MapNeighboursMethodWorkingCorrectlyTwo, MapMethods)
{
    std::vector<int> X{0, 1, 2, 0};
    std::vector<int> Y{0, 1, 2, 2};
    Map newMap(X, Y, 10, 10);
    EXPECT_EQ(newMap.countNeighbours(2, 2), 1);
}

TEST(MapCountNeighboursWorksCorrectly, MapMethods)
{
    std::vector<int> X{0, 1, 0, 2, 0, 1, 2, 9};
    std::vector<int> Y{0, 0, 1, 1, 2, 3, 3, 9};
    Map newMap(X, Y, 10, 10);
    EXPECT_EQ(newMap.countNeighbours(1, 1), 5);
    EXPECT_EQ(newMap.countNeighbours(0, 0), 2);
    EXPECT_EQ(newMap.countNeighbours(3, 3), 1);
    EXPECT_EQ(newMap.countNeighbours(1, 2), 5);
    EXPECT_EQ(newMap.countNeighbours(9, 9), 0);
    EXPECT_EQ(newMap.countNeighbours(8, 9), 1);
}
TEST(MapUpdateKillWorksCorrectly, MapMethods)
{
    std::vector<int> X{0, 1, 2, 0};
    std::vector<int> Y{0, 1, 2, 2};
    Map newMap(X, Y, 10, 10);
    newMap.updateMap();

    EXPECT_TRUE(newMap.giveMap().at(0).at(0).showExistance());
    EXPECT_TRUE(!newMap.giveMap().at(1).at(1).showExistance());
    EXPECT_TRUE(newMap.giveMap().at(2).at(2).showExistance());
    EXPECT_TRUE(!newMap.giveMap().at(1).at(2).showExistance());
    EXPECT_TRUE(newMap.giveMap().at(1).at(0).showExistance());
    EXPECT_TRUE(!newMap.giveMap().at(0).at(2).showExistance());
    EXPECT_TRUE(newMap.giveMap().at(2).at(1).showExistance());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
