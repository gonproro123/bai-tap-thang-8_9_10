#include <bits/stdc++.h>


using namespace std;
string a,b;
int n;
deque<char> Q;
deque<char> Q_Clone;
int main()
{
    cin >> b >> a ;
    int a_len= a.size();
    int b_len= b.size();
    a=" "+a;
    b=" "+b;
    for(int i=1;i<=b_len;i++)
    {
        Q.push_back(b[i]);
        int h=a_len;
        while(!Q.empty() && Q.back() == a[h])
        {
            Q_Clone.push_back(Q.back());
            Q.pop_back();
            if(h==1)
            {
                h=a_len;
                Q_Clone.clear();
            }
            else
                h--;
        }
        if(Q_Clone.size()<a_len && !Q_Clone.empty())
        {
            Q.push_back(Q_Clone.back());
            Q_Clone.pop_back();
        }

    }

    if(Q.empty())
        cout<<"EMPTY";
    while(!Q.empty())
    {
        cout<<Q.front();
        Q.pop_front();
    }

    return 0;
}
