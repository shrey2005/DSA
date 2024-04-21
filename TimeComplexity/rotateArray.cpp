#include <iostream>
using namespace std;


void rotate(int *input, int d, int n)
{
    //Write your code here
    int *arrCpy = new int[d];
    for(int i = 0; i < d; i++){
        *(arrCpy + i) = *(input+i);
    }
    
    int count = 0;
    for(int i = d; i < n; i++){
        *(input + count) = *(input + i);
        count++;
    }
    
    for(int j = 0; j < d; j++){
        *(input + count) = *(arrCpy + j);
        count++;
    }
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}

