#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> req(n, vector<int>(m));
    vector<int> avail(m);

    // Input Allocation Matrix
    cout << "Enter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> alloc[i][j];

    // Input Request Matrix
    cout << "Enter Request Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> req[i][j];

    // Input Available Resources
    cout << "Enter Available Resources:\n";
    for(int i = 0; i < m; i++)
        cin >> avail[i];

    vector<bool> finish(n, false);

    int completed = 0;

    while(true) {

        bool found = false;

        for(int i = 0; i < n; i++) {

            if(!finish[i]) {

                int j;
                for(j = 0; j < m; j++) {

                    if(req[i][j] > avail[j])
                        break;
                }

                // If process can complete
                if(j == m) {

                    for(int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    finish[i] = true;
                    found = true;
                    completed++;
                }
            }
        }

        // If no process can proceed
        if(!found)
            break;
    }

    // Check deadlock
    bool deadlock = false;

    cout << "\nDeadlocked Processes: ";

    for(int i = 0; i < n; i++) {
        if(!finish[i]) {
            cout << "P" << i << " ";
            deadlock = true;
        }
    }

    if(!deadlock)
        cout << "None (No Deadlock)";

    cout << endl;

    return 0;
}