#include<stdio.h>
#include<time.h>
#include<stdlib.h>
/*NxN lik [0, 1] say�lar�ndan olu�an rastgele labirent olu�tur.Labtan ��karken hangi ad�mlardan gidildi�ini lab i�erisine yaz.
Dolamba� Kurallar�:
1. A ve B noktalar� 1 olacakt�r. 
2. Gidilen bir noktaya tekrar gidilebilecektir.
3. Yukar�, a�a��, sa�a ve sola hareket edilebilecektir. �apraz hareket yap�lmayacakt�r.
4. Her gidilen ad�mda ad�m say�s� o h�creye yaz�lacakt�r. A=1 olmak �zere bir sonraki ad�m 2 olacakt�r.
5. E�er dolamba�tan ��k�lam�yorsa ��IKILAMADI� yaz�p tekrar rastgele bir dolamba� �retilecektir.
6. DOLAMBA�TAN �IKILAMADI ise yeni dolamba� �retilmeden �nce dolambac�n son hali g�sterilecektir.*/
main()
{	srand(time(NULL));
	int n,x=0,y=0,adim=2;
	int kazanildimi=0;
	printf("\n Labirent olusturmak icin n sayisi giriniz: ");
	scanf("%d",&n);
	
	while(kazanildimi==0)
	{
	x=0;
	y=0;
	adim=2;
	int lab[n][n];
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
		{
			lab[i][j]=rand()%2;
		}
	}
	lab[0][0]=1;
	lab[n-1][n-1]=1;
	printf("\n LABIRENTIN ILK HALI:\n");
	for(int i=0;i<n;i++)
	{ 
	    printf("\n\t\t");
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
			{
				printf(" A ");
			}
			else if(i==n-1 && j==n-1)
			{
				printf(" B ");
			}
			else
			{
				printf(" %d ",lab[i][j]);
			}
	      
		}
	}
	int sayac=1;
	while(sayac<n*n)
	{
	   if(lab[y][x+1]==1 && x!=n-1 )//sa�a do�ru
	   {
	   	lab[y][x+1]=adim;
	   	adim++;
	   	x++;
	   }
	   else if(lab[y+1][x]==1 && y!=n-1)//asagi do�ru
	   {
	   	lab[y+1][x]=adim;
	   	adim++;
	   	y++;
	   }
	   else if(lab[y][x-1]==1 && x!=0 && x!=n-1)//sola dogru
	   {
	   	lab[y][x-1]=adim;
	   	adim++;
	   	x--;
	   	}
	    else if(lab[y-1][x]==1 && y!=0&& y!=n-1)//yukar� dogru
	   {
	   	lab[y-1][x]=adim;
	   	adim++;
	   	y--;
	   }
	   else
	   {
	   	break;
	   }
	  sayac++;
	  
	  if(x==n-1 && y==n-1)
	   {
	  	kazanildimi=1;
	  	break;
	   }
	}
	printf("\n\nLABIRENTIN SON HALI:");
	for(int i=0;i<n;i++)
	{
		printf("\n\t\t");
	    for(int j=0;j<n;j++)
		{
			printf(" %d ",lab[i][j]);
		}
	}
	if(kazanildimi==0)
	{
		printf("\n LABIRENTTEN CIKILAMADI..\n");
	
		printf("\n --YENI DONGUYE GIRILIYOR..--\n");
		
	}
	if(kazanildimi==1)
	{
		printf("\nLABIRENTTEN CIKILDI..");
	}
	
	}
	
	
	
	
	
	
}
