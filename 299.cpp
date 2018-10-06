#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

//int insertionSort(vector<int> &arr, int &count)
void insertionSort(vector<int> &arr, int &count)
{
    //int count = 0;
	for(int j = 1; j != arr.size(); j++)
	{
		int key = arr[j];
		int	i   = j - 1;
		while(i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i--;
            count++;
		}
		arr[i + 1] = key;
	}
    //return count;
}

int main() 
{
    int T;
    cin >> T;
    vector<int> ivec;
    while(T--)
    {
        int n, val;
        int count = 0;
        cin >> n;
        if(n == 0)
        {
            cout << "Optimal train swapping takes 0 swaps." << std::endl;    
            continue;
        }
        ivec.clear();

        while(n--)
        {
            cin >> val;
            ivec.push_back(val);
        }

        insertionSort(ivec, count);
        cout << "Optimal train swapping takes " << count << " swaps." << std::endl;

    }
}