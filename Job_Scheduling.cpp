#include <iostream>
using namespace std;
void swap(int *p, int i, int j)
{
    int temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}
int main()
{
    int n;
    cout << "Enter the number of jobs :";
    cin >> n;
    int profit[n];
    int serial[n];
    int deadline[n];
    int maxdeadline = -1;
    cout << "Enter the profit and deadline for each process :";
    for (int i = 0; i < n; i++)
    {
        serial[i] = i + 1;
        cin >> profit[i] >> deadline[i];
        if (deadline[i] > maxdeadline)
        {
            maxdeadline = deadline[i];
        }
    }
    int output[maxdeadline + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (profit[i] > profit[j])
            {
                swap(profit, i, j);
                swap(serial, i, j);
                swap(deadline, i, j);
            }
        }
    }
    int maxprofit = 0;
    for (int i = 0; i < n; i++)
    {
        if (output[deadline[i]] == 0)
        {
            output[deadline[i]] = serial[i];
            maxprofit += profit[i];
            continue;
        }
        else
        {
            for (int j = deadline[i]; j > 0; j--)
            {
                if (output[j] == 0)
                {
                    output[j] = serial[i];
                    maxprofit += profit[i];
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i <= maxdeadline; i++)
    {
        if (output[i] != 0)
        {
            if (count == 0)
            {
                cout << output[i];
                count++;
            }
            else
            {
                cout << "->" << output[i];
            }
        }
    }
    cout << endl;
    cout << "Profit: "<<maxprofit;
}