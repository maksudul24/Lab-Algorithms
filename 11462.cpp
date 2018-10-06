#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

// void insertionSort(vector<int> &arr)
// {
// 	for(int j = 1; j != arr.size(); j++)
// 	{
// 		int key = arr[j];
// 		int	i   = j - 1;
// 		while(i >= 0 && arr[i] > key)
// 		{
// 			arr[i + 1] = arr[i];
// 			i--;
// 		}
// 		arr[i + 1] = key;
// 	}
// }

void merge(vector<int>& ivec, std::size_t low, std::size_t mid, std::size_t high)
{
	size_t n1 = mid - low + 1;
	size_t n2 = high - mid;
	vector<int> Lvec, Rvec;
	int i, j, k = low;

	for(i = 0; i != n1; ++i)
		Lvec.push_back(ivec[low + i]);
	for(j = 0; j != n2; j++)
		Rvec.push_back(ivec[mid + 1 + j]);
	
	Lvec.push_back(pow(2, 28));
	Rvec.push_back(pow(2, 28));
	i = j = 0;
    
	while(k <= high)
	{
		if(Lvec[i] <= Rvec[j])
			ivec[k] = Lvec[i++];
		else
			ivec[k] = Rvec[j++];
		++k;
	}
}


void merge_sort(vector<int> &ivec, size_t low, size_t high)
{
	if(low < high)
	{
		size_t mid = std::floor((low + high)/2);
		merge_sort(ivec, low, mid);
		merge_sort(ivec, mid+1, high);
		merge(ivec, low, mid, high);
	}
}


int main()
{
    int n;
    vector<int> ivec;
    while((cin >> n) && n != 0)
    {
        int value;
        ivec.clear();
        
        while(n--)
        {
            cin >> value;
            ivec.push_back(value);
        }
        
        //insertionSort(ivec);
        merge_sort(ivec, 0, ivec.size() - 1);

        cout << ivec[0];
        for(int i = 1; i != ivec.size(); i++)
        {
            cout << " " << ivec[i];
        }
        cout << std::endl;
    }
}