#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (a < b ? a : b)

int tabla[20][20]={0},n;  //n - marimea
int plasare(int , int );
void BackTrack(int);
void afisam();

int main()
{
printf("Introdu marimea tablei de sah : ");
scanf("%d",&n);
BackTrack(1);
}

 
void BackTrack(int rind)
{
int i=0,j=0;

	for(i=1;i<=n;i++)
	if( plasare(rind,i) )
	{
		tabla[rind][i]=1;
		if(rind==n) afisam();
		else BackTrack(rind+1);
		tabla[rind][i]=0;	
	}

}


void afisam()
{
int i,j;
for(i=1;i<=n;i++,printf("\r\n"))
for(j=1;j<=n;j++)
	printf("%d ",tabla[i][j]);
exit(0);
}


int plasare(int rind ,int col)
{
int i,j,reset;

for(i=1;i<=n;i++)  //parcurgere pe linii si coloane
if( tabla[rind][i]==1 || tabla[i][col]==1 ) return 0;
reset=min(rind,col)-1; 

for(i=rind-reset , j=col-reset; i<n,j<n; i++,j++) // parcurgere pe diagonala nr 1
	if(tabla[i][j]==1) return 0;

for(i=rind-reset,j=col+reset; i<n, j>0; i++, j--) //parcurgere pe diagonala nr 2
	if(tabla[i][j]==1) return 0;

	return 1;


}