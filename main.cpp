#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream in("numar5.in");
ofstream out("numar5.out");

bool isCircular(int v[100000] ,int nrcif)
{
    bool viz[1000];
    for(int i=0;i<1000;i++)
        viz[i] = false;
    int pos,i;
    pos = i = 0;
    for(i = 0;i < nrcif;i++)
    {
        pos = pos + v[pos];
        pos = pos % pos;
        if(viz[i]==true)
            break;
        viz[i] = true;
    }
    if(pos = 0 && i == nrcif)
        return true;
    else
        return false;
}

int main()
{int nrn,nrc,n,maxnr1cif = 0,maxnr = 0,nr[100000];
    in>>nrn;
    for(int i=0;i<nrn;i++)
    {
        in>>n;
        maxnr1cif = max(maxnr1cif,n);
        nrc = 0;
        while(n)
        {
            nr[nrc] = n %10;
            nrc++;
            n = n/10;
        }
        for(int j=0;j<nrc;j++)
           swap(nr[j],nr[nrc-j-1]);
        int temp = 0;bool temp2 = false;
        for(int j=0;j<nrc;j++)
        {
            for(int k=0;k<nrc;k++)
            {
                if(nr[j]==nr[k])
                {
                    temp2 = true;
                    break;
                }
            }
            temp = temp * 10 + nr[j];
        }
        if(temp2 = true)
            maxnr = max(maxnr,temp);

    }
    if(maxnr != 0)
        out<<maxnr;
    else
        out<<maxnr1cif;

    return 0;
}
