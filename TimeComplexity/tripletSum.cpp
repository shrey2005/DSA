#include <iostream>
#include <algorithm>
using namespace std;

#include <iostream>
#include <algorithm>
using namespace std;

int pairSum(int *arr, int n, int num)
{
    int startIndex = 0;
    int endIndex = n - 1;
    int count  = 0;
    while (startIndex < endIndex){
        if (arr[startIndex] + arr[endIndex] < num){
            startIndex++;
        }
    
        else if (arr[startIndex] + arr[endIndex] > num){
            endIndex--;
        }
        else 
        {
            int elementAtStart = arr[startIndex];
            int elementAtEnd = arr[endIndex];
            if (elementAtStart == elementAtEnd){
                int elementFromStartToEnd = endIndex - startIndex + 1;
            count += (elementFromStartToEnd * (elementFromStartToEnd - 1) / 2);
                return count;
            }
            int tempStartIndex = startIndex + 1;
            int tempEndIndex = endIndex - 1;
            while (tempStartIndex <= tempEndIndex && arr[tempStartIndex] == elementAtStart){
                tempStartIndex++;
            }
             while (tempEndIndex >= tempStartIndex && arr[tempEndIndex] == elementAtEnd){
                tempEndIndex--;
            }
            int elementFromStart = tempStartIndex - startIndex;
            int elementFromEnd = endIndex - tempEndIndex;
            count += (elementFromStart * elementFromEnd);
            startIndex = tempStartIndex;
            endIndex = tempEndIndex;
        }
    }
	return count;
}

int tripletSum(int *arr, int n, int num)
{
    sort(arr, arr + n);
    int count = 0;
    for (int i = 0; i < n - 2; i++)
        {
            int x = pairSum(arr + i + 1, n - i - 1, num - arr[i]);
            count += x;
        }
  
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}