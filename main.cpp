#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include "number.h"
#include "Multiplicator.h"

using namespace std;

time_t avarageTime(vector<time_t> v)
{
    return (v[0] + v[1] + v[2])/3;
}

int main()
{
    vector<time_t> vecOfRes1, vecOfRes2, vecOflentgh;
    int start, finish;
    cin >> start >> finish;
    for (int i = start; i < finish; ++i)
    {
        vector<time_t> temp1;
        vector<time_t> temp2;
        Number x(i);
        Number y(i);
        vecOflentgh.push_back(i);
        for (int j = 0; j < 3; ++j)
        {
        time_t b1 = clock();
        Multiplicator::product1(x, y);
        time_t e1 = clock();
        temp1.push_back(e1-b1);
        }
        vecOfRes1.push_back(avarageTime(temp1));

        for (int j = 0; j < 3; ++j)
        {
            time_t b2 = clock();
            Multiplicator::product2(x, y);
            time_t e2 = clock();
            temp2.push_back(e2-b2);
        }
        vecOfRes2.push_back(avarageTime(temp2));

    }


    ofstream file("file.csv");
    if (file.is_open())
        cout << "File is open! \n";
    for (int i = 0; i < vecOfRes1.size(); ++i)
    {
        file << vecOflentgh [i] << ";" << vecOfRes1[i] << ";" << vecOfRes2[i] << '\n';
    }
    file.close();


    return 0;
}