#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;



#include "solution.h"

class Runner
{
    int t;

    
    vector<vector<int> > arr;


public:
    void takeInput()
    {

 cin >> t;
        arr.resize(t);
        

        for (int tc = 0; tc < t; tc++)
        {
            int n;
            cin >> n;



            arr[tc].resize(n);

            for (int i = 0; i < n; i++)
            {
                cin >> arr[tc][i];
            }
        }

        
    }

    void execute()
    {
         vector<vector<int> > arrCopy = arr;
        for (int i=0;i<t;i++){
            removeDuplicates(arrCopy[i]);
        }
    }


    void executeAndPrintOutput()
    {
        for (int tt=0;tt<t;tt++){
            vector<int> v=removeDuplicates(arr[tt]);
            for (int i=0; i < v.size(); i++){
              cout<<v[i]<<" ";         
            }
            cout<<"\n";
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
