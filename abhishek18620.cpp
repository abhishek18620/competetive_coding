#include <stdio.h>
#include <stdlib.h>
using namespace std;
long long totalDiamonds[100];
int main(){
  #ifdef LOCAL_DEFINE
        freopen("INP.txt","rt",stdin);
        //freopen("output.txt","w",stdout);
    #endif
  int tc;
  int n;
  int diamonds[201];
  totalDiamonds[1]=2;
  int indiPos[7]={0,0,0,0,0,0,9};
  int oddSum=9,evenSum=0;
  for(int i=0;i<10;i++)
    diamonds[i]=i;
  int k;
  int lastPos=6;
  int j;
  for(int i=10;i<=200;i++){
    j=lastPos;
    while(indiPos[j]==9){
      indiPos[j]=0;
      oddSum-=9;
      j--;
    }
    if(indiPos[j]&1){
      oddSum-=indiPos[j];
      evenSum+=(++indiPos[j]);
    }else{
      evenSum-=indiPos[j];
      oddSum+=(++indiPos[j]);
    }
    diamonds[i]=abs(evenSum-oddSum);
  }
  for(int j=2;j<=100;j++){
    totalDiamonds[j]=2*totalDiamonds[j-1]-totalDiamonds[j-2]-2*diamonds[j]+
                diamonds[2*(j-1)]+2*diamonds[2*j-1]+diamonds[2*j];
  }
  scanf("%d",&tc);
  while(tc--){
    scanf("%d",&n);
    printf("%lld\n",totalDiamonds[n]);
  }
  return 0;
} 