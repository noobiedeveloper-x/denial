#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int unit;

    cout << setw(100) << "|-------------------------------------|" << endl;
    cout << setw(100) << "|         SIMPLE GPA CALCULATOR       |" << endl;
    cout << setw(100) << "|            CODED BY KLEIN 1-B       |" << endl;
    cout << setw(100) << "|_____________________________________|" << endl;

    cout << "ENTER UNIT ?:  " << endl;
    cin >> unit;

    double totalgrades = 0;
    double grade;

    for (int i = 0; i < unit; i++) {
        cout << "ENTER GRADE " << i + 1 << ": ";
        cin >> grade;
        totalgrades += grade;
    }

    double average = static_cast<double>(totalgrades) / unit;

    if (average >= 3.5) {
        cout << "SUMMA CUM LAUDE!" << endl;
        cout << "TOTAL AVG: " << average << endl;
    }
    else if (average >= 3.0) {
        cout << "MAGNACUM LAUDE!" << endl;
        cout << "TOTAL AVG: " << average << endl;
    }
    else if (average >= 2.5) {
        cout << "CUM LAUDE!" << endl;
        cout << "TOTAL AVG: " << average << endl;
    }
    else if (average >= 2.0) {
        cout << "DEAN'S LISTER!" << endl;
        cout << "TOTAL AVG: " << average << endl;
    }
    else {
        cout << "STUDY MORE TO GET TO DEAN LIST" << endl;
        cout << "TOTAL AVG: " << average << endl;
    }

    return 0;
}
