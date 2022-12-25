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
    testPoint.checkExistance(3);
    EXPECT_TRUE(testPoint.showExistance());
}

TEST(PointExistanceNoChange, PointTests)
{
    Point testPoint(0, 0);
    testPoint.checkExistance(2);
    EXPECT_TRUE(!testPoint.showExistance());
    testPoint.checkExistance(1);
    EXPECT_TRUE(!testPoint.showExistance());
    testPoint.checkExistance(0);
    EXPECT_TRUE(!testPoint.showExistance());
    testPoint.checkExistance(-5);
    EXPECT_TRUE(!testPoint.showExistance());
}

TEST(PointExistanceTrueFalseChange, PointTests)
{
    Point testPoint(0, 0);
    testPoint.checkExistance(3);
    EXPECT_TRUE(testPoint.showExistance());
    testPoint.checkExistance(2);
    EXPECT_TRUE(!testPoint.showExistance());
    testPoint.checkExistance(3);
    EXPECT_TRUE(testPoint.showExistance());
    testPoint.checkExistance(3);
    EXPECT_TRUE(!testPoint.showExistance());
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
{std::vector<int> X{1,2};
std::vector<int> Y{4,5};
    Map newMap(X,Y,10, 10);
    EXPECT_TRUE(newMap.giveMap().at(4).at(1).showExistance());
    EXPECT_TRUE(newMap.giveMap().at(5).at(2).showExistance());
    EXPECT_TRUE(!newMap.giveMap().at(1).at(1).showExistance());
}
TEST(WrongInputFullMapConstructor, MapCreationTests)
{std::vector<int> X{1,2};
std::vector<int> Y{4,5};
    Map newMap(X,Y,-10, -10);
    EXPECT_TRUE(newMap.giveMap().at(4).at(1).showExistance());
    EXPECT_TRUE(newMap.giveMap().at(5).at(2).showExistance());
    EXPECT_TRUE(!newMap.giveMap().at(1).at(1).showExistance());
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
