#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m; // n = processes, m = resources

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> maxm(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> avail(m);

    // Input Allocation
    cout << "Enter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> alloc[i][j];

    // Input Maximum
    cout << "Enter Maximum Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> maxm[i][j];

    // Input Available
    cout << "Enter Available Resources:\n";
    for(int i = 0; i < m; i++)
        cin >> avail[i];

    // Step 1: Need = Max - Allocation
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = maxm[i][j] - alloc[i][j];
        }
    }

    vector<bool> finish(n, false);
    vector<int> safeSeq;

    int count = 0;

    // Step 2: Safety Check
    while(count < n) {

        bool found = false;

        for(int i = 0; i < n; i++) {

            if(!finish[i]) {

                int j;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j])
                        break;
                }

                // If process can be executed
                if(j == m) {

                    for(int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safeSeq.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        // If no process found → unsafe state
        if(!found) {
            cout << "\nSystem is NOT in SAFE state\n";
            return 0;
        }
    }

    // Safe state
    cout << "\nSystem is in SAFE state\n";
    cout << "Safe Sequence: ";

    for(int i = 0; i < n; i++) {
        cout << "P" << safeSeq[i];
        if(i != n - 1) cout << " -> ";
    }

    cout << endl;

    return 0;
}