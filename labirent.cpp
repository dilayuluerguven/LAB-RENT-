#include<stdio.h>
#include<time.h>
#include<stdlib.h>
/*NxN lik [0, 1] sayýlarýndan oluþan rastgele labirent oluþtur.Labtan çýkarken hangi adýmlardan gidildiðini lab içerisine yaz.
Dolambaç Kurallarý:
1. A ve B noktalarý 1 olacaktýr. 
2. Gidilen bir noktaya tekrar gidilebilecektir.
3. Yukarý, aþaðý, saða ve sola hareket edilebilecektir. Çapraz hareket yapýlmayacaktýr.
4. Her gidilen adýmda adým sayýsý o hücreye yazýlacaktýr. A=1 olmak üzere bir sonraki adým 2 olacaktýr.
5. Eðer dolambaçtan çýkýlamýyorsa “ÇIKILAMADI” yazýp tekrar rastgele bir dolambaç üretilecektir.
6. DOLAMBAÇTAN ÇIKILAMADI ise yeni dolambaç üretilmeden önce dolambacýn son hali gösterilecektir.*/
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
	   if(lab[y][x+1]==1 && x!=n-1 )//saða doðru
	   {
	   	lab[y][x+1]=adim;
	   	adim++;
	   	x++;
	   }
	   else if(lab[y+1][x]==1 && y!=n-1)//asagi doðru
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
	    else if(lab[y-1][x]==1 && y!=0&& y!=n-1)//yukarý dogru
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
