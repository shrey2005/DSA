#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool reachValidDestination(int sx, int sy, int dx, int dy, int sumx, int sumy){
    
    if(dx < sumx || dy < sumy){
        return false;
    }
    
    if(dx == sumx && dy == sumy){
        return true;
    }
    
    if(dx > dy){
        return reachValidDestination(sx, sy, dx - dy, dy, sumx, sumy);
    }
    else{
        return reachValidDestination(sx, sy, dx, dy - dx, sumx, sumy);
    }
    // int lsum1 = sumy + sumx;
    // bool foundDestination1 = reachValidDestination(sx, sy, dx, dy, sumx, lsum1);
    
    // int rsum1 = sumx + sumy;
    // bool foundDestination2 = reachValidDestination(sx, sy, dx, dy, rsum1, sumy);
    // return foundDestination1 || foundDestination2;
}

bool reachDestination(int sx, int sy, int dx, int dy) {
    // Write your code here
    bool flag = false;
    flag = reachValidDestination(sx, sy, dx, dy, sx, sy);
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a,b,c,d;
        cin >> a>> b>> c>> d;

        
        if(reachDestination(a,b,c,d)){
            cout<< "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }
}