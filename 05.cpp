#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[10], bt[10], ct[10], tat[10], wt[10];
    bool done[10] = {false};

    cout << "Enter AT and BT:\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> at[i] >> bt[i];
    }

    int time = 0, completed = 0;

    while(completed < n) {

        int idx = -1;
        int min_bt = 9999;

        // find shortest job
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == false) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        //  CPU idle
        if(idx == -1) {
            time++;
            continue;
        }

        //  execute process
        ct[idx] = time + bt[idx];
        time = ct[idx];

        done[idx] = true;
        completed++;
    }

    // calculate TAT and WT
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // print table
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\n";
    }

    // 🎯 Gantt Chart (simple)
    cout << "\nGantt Chart:\n| ";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << " | ";
    }

    cout << endl;

    return 0;
}