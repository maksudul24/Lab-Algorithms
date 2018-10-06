#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

int main()
{
    vector<int> ivec;
    int x;
    while(cin >> x)
    {
        ivec.push_back(x);
        std::sort(ivec.begin(), ivec.end());

        if(ivec.size() == 1)
        {
            cout << ivec[0] << std::endl;
        }
        else if(ivec.size() % 2 == 0) 
        {
            cout << (int) (ivec[ivec.size() / 2] + ivec[ivec.size() / 2 - 1]) / 2 << std::endl;
        }
        else 
            cout << ivec[ivec.size() / 2] << std::endl;

    }
}