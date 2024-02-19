#include <iostream>

using namespace std;

int main()
{
    int n,v[10]={},i,j;
    char cam;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>cam;
        if(cam=='L')
        {
            for(j=0;j<=9;j++)
            {
                if(v[j]==0)
                {
                    v[j]=1;
                    break;
                }
            }
        }
        if(cam=='R')
        {
            for(j=9;j>=0;j--)
            {
                 if(v[j]==0)
                {
                    v[j]=1;
                    break;
                }

            }

        }
        if(cam>='0' && cam<='9')
            v[cam-'0']=0;


    }
    for(i=0;i<10;i++)
        cout<<v[i];
    return 0;
}

