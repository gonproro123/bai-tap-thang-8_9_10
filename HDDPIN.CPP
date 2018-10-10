#include <bits/stdc++.h>

using namespace std;
ifstream fin("HIDDPIN.INP");
ofstream fout("HIDDPIN.OUT");
const int N = 1e5 + 5;
long long n, a[N], b[N], x, y, check;
void In()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >>  a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        b[i] = i;
    }
}
int main()
{
    In();
    int z = n;
    while(z--)
    {
        x = b[1];
        for(int i = 1; i <= n; i++)
        {
            b[i] = b[i + 1];
            if(i == n)
            {
             b[i] = x;
            }
        }
         for(int i = 1; i <= n; i++)
         {
             if(abs(b[i] - a[i]) <= 1)
             {
                 check++;
              if(b[i] == 1)
              {
                  y = i;

              }
             }
             else
             {
                check = 0;
                break;
             }
         }
         if(check == n)
         {
             fout << "YES" << "\n";
             fout << y;
             return 0;
         }
    }
    fout << "NO";
    return 0;
}
