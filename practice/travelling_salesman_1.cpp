#include <iostream>
using namespace std;

const int MaxVillages = 10;  // Maximum number of villages

int costMatrix[MaxVillages][MaxVillages];  // Cost matrix to store travel costs
int visited[MaxVillages];  // Array to track visited villages
int numVillages, totalCost = 0;  // Number of villages and total travel cost

// Function to find the nearest unvisited village from a given village
int findNearestUnvisitedVillage(int currentVillage) {
    int i, nearestVillage = -1;
    int minCost = 999, tempCost;

    for (i = 0; i < numVillages; i++) {
        if ((costMatrix[currentVillage][i] != 0) && (visited[i] == 0)) {
            tempCost = costMatrix[currentVillage][i];
            if (tempCost < minCost) {
                minCost = tempCost;
                nearestVillage = i;
            }
        }
    }

    if (nearestVillage != -1)
        totalCost += minCost;

    return nearestVillage;
}

// Function to find the minimum cost Hamiltonian circuit starting from a given city
void findMinimumCostHamiltonianCircuit(int currentCity) {
    int nextCity;
    visited[currentCity] = 1;

    cout << "Visiting City " << currentCity + 1 << " ---> ";
    nextCity = findNearestUnvisitedVillage(currentCity);

    if (nextCity == -1) {
        nextCity = 0;
        cout << "Returning to City 1" << endl;
        totalCost += costMatrix[currentCity][nextCity];
        return;
    }
    
    findMinimumCostHamiltonianCircuit(nextCity);
}

int main() {
    cout << "Enter the number of villages: ";
    cin >> numVillages;

    cout << "\nEnter the Cost Matrix\n";
    for (int i = 0; i < numVillages; i++) {
        cout << "\nEnter Costs for Village " << i + 1 << "\n";
        for (int j = 0; j < numVillages; j++)
            cin >> costMatrix[i][j];
        visited[i] = 0;
    }

    cout << "\n\nThe Path is:\n";
    findMinimumCostHamiltonianCircuit(0); 

    cout << "\n\nMinimum cost of the circuit is " << totalCost << endl;
    return 0;
}
