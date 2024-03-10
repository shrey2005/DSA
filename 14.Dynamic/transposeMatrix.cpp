#include<iostream>
using namespace std;
int main()
{
	//write your code here
	int noOfItr;
	cin>>noOfItr;

	for(int i = 0 ; i < noOfItr; i++){

		int rows, cols;
		cin>>rows>>cols;

		int **ptr = new int*[rows];
		for(int i = 0 ; i < rows; i++){
			ptr[i] = new int[cols];
					for (int j = 0; j < cols; j++) {
					cin >> ptr[i][j];
					}
			}

		for(int i = 0; i < cols; i++){
			for(int j = 0; j < rows; j++){
				cout<<ptr[j][i]<<" ";
			}
	    	cout<<endl;
		}
    }
}