#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 1000000;
    int a[n];
    priority_queue < int,vector<int>, greater<> > pq;
    for(int i=0;i<n;i++)
    {
        a[i] = rand();
        if(pq.size()<10)
            pq.push(a[i]);
        else
        {
            if(pq.top()>a[i])
            {
                pq.pop();
                pq.push(a[i]);
            }
        }
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}