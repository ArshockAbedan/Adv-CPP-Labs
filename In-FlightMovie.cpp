#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    pair<int, int> inFlightmovieServiceProvider(vector<int> movieLenghts, int flightDuration)
    {
        pair<int, int> result(0, 0);
        if ((movieLenghts.size() == 0) || (flightDuration == 0))
        {
            return result;
        }

        pair<int, int> myPair;
        int max = 0;

        for (int i = 0; i < movieLenghts.size() - 1; i++)
        {
            for (int j = i + 1; j < movieLenghts.size(); j++)
            {
                if (movieLenghts[i] + movieLenghts[j] <= flightDuration)
                {
                    if ((movieLenghts[i] >= max) || movieLenghts[j] >= max)
                    {
                        myPair.first = movieLenghts[i];
                        myPair.second = movieLenghts[j];
                        if (myPair.first >= max)
                        {
                            max = myPair.first;
                        }
                        if (myPair.second >= max)
                        {
                            max = myPair.second;
                        }
                    }
                }
            }
        }

        return myPair;
    }
};

int main()
{
    Solution *solution = new Solution();
    vector<int> movieLenghts = {90, 85, 75, 60, 120, 150, 125};
    int flightDuration = 250;
    pair<int, int> result = solution->inFlightmovieServiceProvider(movieLenghts, flightDuration);
    cout << "(" << result.first << "," << result.second << ")";
}