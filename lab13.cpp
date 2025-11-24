#include <iostream>
#include <vector>
using namespace std;

// Function under test (contains the fault)
bool fail_lecture(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}

void runTest(const vector<int>& v, const string& description) {
    cout << description << "\nInput: ";
    for (int x : v) cout << x << " ";
    cout << "\nOutput: " 
         << (fail_lecture(v) ? "true (fail)" : "false (pass)") 
         << "\n\n";
}

int main() {

    // Q2: Does NOT execute the fault
    runTest({1}, "Q2: Test that does NOT execute the fault:");

    // Q3: Executes fault but no error state
    runTest({1,1,1,1,1,1,1,1,1,1},
            "Q3: Executes fault but no error state:");

    // Q4: Error state but no failure
    runTest({0,1,1,1,1,1,1,1,1,0},
            "Q4: Error state but no failure:");

    // Q5: Failure
    runTest({0,0,0,1,1,1,1,1,1,1},
            "Q5: Failure:");

    return 0;
}
