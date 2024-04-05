#include <iostream>

using namespace std;

int chechExists(char large[], int lsize, char *small, int ssize){
    cout<<large<<" "<<lsize<<" "<<small<<" "<<ssize<<endl;
    if(small[0] == '\0'){
        return 0;
    }
    int index = chechExists(large, lsize + 1, small + 1, ssize +1);
    cout<<"Index : "<<index<<endl;
    if(index == 0){
        return 0;
    }
    else{
        return 1;
    }
    return chechExists(large, lsize + 1, small + 1, ssize +1);
}

bool checksequenece(char large[] , char*small) {
    return chechExists(large, 0, small, 0);
}

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}