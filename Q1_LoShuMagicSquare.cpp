#include "iostream"
#include "iomanip"
using namespace std;

constexpr int size = 3;
int sum(int (&arr)[size]);
bool isMagicSquare(int arr[size][size]);

int main(int argc, char const *argv[])
{
    int arr[size][size] =  {{4, 9, 2},
                            {3, 5, 7},
                            {8, 1, 1}};
    cout << boolalpha<< isMagicSquare(arr) << endl;
    return 0;
}
bool isMagicSquare(int arr[size][size])
{
    int magicSum = sum(arr[0]);
    int tempColSum[3]={0,0,0};
    int tempCrossSum[2]={0,0};
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] < 1 || arr[i][j] > 9)
                return false;
            tempColSum[j]+=arr[i][j];
        }
        if (magicSum != sum(arr[i]))
            return false;
        tempCrossSum[0]+=arr[i][i];
        tempCrossSum[1]+=arr[i][size-i-1];
    }

    for (int col: tempColSum)
        if (col!=magicSum)
            return false;

    for (int cross: tempCrossSum)
        if (cross!=magicSum)
            return false;

    return true;
}

int sum(int (&arr)[size])
{
    int tSum(0);
    for (int item : arr)
    {
        tSum += item;
    }
    return tSum;
}