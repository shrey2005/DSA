#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;

            if(pq[childIndex] > pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }

            childIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.size() == 0){
            return 0;
        }
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(pq.size() == 0){
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];

        pq.pop_back();

        int pI = 0;
        int lci = 2 * pI + 1;
        int rci = 2 * pI + 2;

        while(lci < pq.size()){
            int maxIndex = pI;
            
            if(pq[maxIndex] < pq[lci]){
                maxIndex = lci;
            }
            if(rci < pq.size() && pq[maxIndex] < pq[rci]){
                maxIndex = rci;
            }
            if(maxIndex == pI){
                break;
            }
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[pI];
            pq[pI] = temp;

            pI = maxIndex;

            lci = 2 * pI + 1;
            rci = 2 * pI + 2;

        }

        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
