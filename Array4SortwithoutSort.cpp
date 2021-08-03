#include<iostream>
using namespace std;
void sort012(int a[], int n);

int main()
{
    
    cout<<endl;
    return 0;
}

void sort012(int a[], int n)
{
    int zero = 0,one = 0,two = 0;
    for (int i = 0;i<n;i++)
    {
        if (a[i] == 0)
            zero++;
        else if (a[i] == 1)
            one++;
        else //if (a[i] == 2)
            two++;
    }
    for (int i = 0;i<n;i++)
    {
        if (zero > 0)
        {
            a[i] = 0;
            zero--;
        }
        else if (one > 0 )
        {
            a[i] = 1;
            one--;
        }
        else// if ( two > 0)
        {
            a[i] = 2;
            two--;
        }
    }
    
    
}