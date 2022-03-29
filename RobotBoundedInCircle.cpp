//============================================================================
// Name        : RobotBoundedInCircle.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:
//               * The north direction is the positive direction of the y-axis.
//               * The south direction is the negative direction of the y-axis.
//               * The east direction is the positive direction of the x-axis.
//               * The west direction is the negative direction of the x-axis.
//               The robot can receive one of three instructions:
//               * "G": go straight 1 unit.
//               * "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
//               * "R": turn 90 degrees to the right (i.e., clockwise direction).
//               The robot performs the instructions given in order, and repeats them forever.
//               Return true if and only if there exists a circle in the plane
//               such that the robot never leaves the circle.
//============================================================================
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        bool res = false;
        int x = 0, y = 0, dirX = 0, dirY = 1; // at center, facing north
        int temp;
        for (char d : instructions)
        {
            if (d == 'G')
            {
                x = x + dirX;
                y = y + dirY;
            }
            else if (d == 'L')
            {
                temp = dirX;
                dirX = -1 * dirY;
                dirY = temp;
            }
            else
            {
                // d == 'R'
                temp = dirY;
                dirY = -1 * dirX;
                dirX = temp;
            }
        }

        // if it is at strating point or at least one direction has changed.
        if ((x == 0 && y == 0) || (dirX != 0 || dirY != 1))
        {
            res = true;
        }

        return res;
    }
};

int main()
{
    string orders = "GGLLGG";
    Solution *solution = new Solution();
    if(solution->isRobotBounded(orders)){
        cout << "True";
    }else{
        cout << "False";
    }
    return 0;
}