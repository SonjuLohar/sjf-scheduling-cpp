
#include <iostream>
#include <iomanip>
using namespace std;

class SJF {
    int n;
    int at[100], bt[100], ct[100], tat[100], wt[100];
    bool done[100];

public:
    void input() {
        cout << "Enter number of processes: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter Arrival Time and Burst Time for P"
                 << i + 1 << ": ";
            cin >> at[i] >> bt[i];
            done[i] = false;
        }
    }

    void calculate() {
        int currentTime = 0;
        int completed = 0;

        while (completed < n) {
            int shortest = -1;

            for (int i = 0; i < n; i++) {
                if (!done[i] && at[i] <= currentTime) {
                    if (shortest == -1 || bt[i] < bt[shortest]) {
                        shortest = i;
                    }
                }
            }

            if (shortest == -1) {
                currentTime++;
                continue;
            }

            currentTime += bt[shortest];
            ct[shortest] = currentTime;

            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            done[shortest] = true;
            completed++;
        }
    }

    void display() {
        float totalWT = 0, totalTAT = 0;

        cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";

        for (int i = 0; i < n; i++) {
            cout << "P" << i + 1 << "\t"
                 << at[i] << "\t"
                 << bt[i] << "\t"
                 << ct[i] << "\t"
                 << tat[i] << "\t"
                 << wt[i] << "\n";

            totalWT += wt[i];
            totalTAT += tat[i];
        }

        cout << fixed << setprecision(2);
        cout << "\nAverage Waiting Time: " << totalWT / n;
        cout << "\nAverage Turnaround Time: " << totalTAT / n;
    }
};

int main() {
    SJF obj;

    obj.input();
    obj.calculate();
    obj.display();

    return 0;
}

