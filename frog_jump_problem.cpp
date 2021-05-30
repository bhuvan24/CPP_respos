// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool CheckWhetherFrogMeet(int *val)
{
    int iPosFrog1 = val[0];
    int iJumpMtrsFrog1 = val[1];
    int iPosFrog2 = val[2];
    int iJumpMtrsFrog2 = val[3];
    while (iPosFrog1 < 10000 && iPosFrog2 < 10000)
    {
        iPosFrog1 += iJumpMtrsFrog1;
        iPosFrog2 += iJumpMtrsFrog2;
        if (iPosFrog1 == iPosFrog2)
            return true;
    }
    return false;

}

int main()
{
    char charinput[100];
    char delim[] = ",";
    int values[4], cnt{ 0 };
    cin >> charinput;
    char* token = strtok(charinput, delim);
    while (token)
    {
        values[cnt] = atoi(token);
        if (values[cnt] > 10000)
        {
            cout << "Input Exceeds the limits" << endl;
            return -1;
        }
        token = strtok(NULL, delim);
        cnt++;
    }
    bool bMeet = CheckWhetherFrogMeet(values);
    if (bMeet)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
