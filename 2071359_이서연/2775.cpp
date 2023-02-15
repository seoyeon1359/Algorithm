#include <iostream>

using namespace std;

int solve(int K,int N)
{
    int now[14+1];
    int under[14+1]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    //아래층을 기반으로 현재 배열을 만듬
    for(int i=1;i<=K;i++)  //층
    {
        for(int j=1;j<=N;j++) //호
        {
            for(int k=1;k<=j;k++)//아래층의 호
            {
                if(k==1) //첫 +=라면 1로 초기화
                    now[j]=1;
                else
                    now[j]+=under[k];
            }
        }
        //i층 검사가 끝나고 아래층을 i층으로 갱신
        for(int j=1;j<=N;j++)
        {
            under[j]=now[j];
        }
        
    }
    return now[N];
}

int main()
{
    int T,k,n;
    cin>>T;
    for(int i=0;i<T;i++)
    {   
        cin>>k>>n;
        cout<<solve(k,n)<<endl;
    }
    return 0;
}
