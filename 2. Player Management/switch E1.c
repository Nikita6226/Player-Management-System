#include<stdio.h>
void main()
{
	int month;
	printf("\n enter the month no.(1-12)");	
	scanf("%d",& month);
	switch(month)
	{
		case 1:printf("\n january is having 31 days");
		break ;
		case 2:printf("\n february is having 28/29 days");
		break ;
		case 3:printf("\n march is having 31 days");
		break ;
		case 4:printf("\n april is having 30 days");
		break ;
		case 5:printf("\n may is having 31 days");
		break ;
		case 6:printf("\n june is having 30 days");
		break ;
		case 7:printf("\n july is having 31 days");
		break ;
		case 8:printf("\n august is having 31 days");
		break ;
		case 9:printf("\n september is having 30 days");
		break ;
		case 10:printf("\n octobmber is having 31 days");
		break ;
		case 11:printf("\n november is having 30 days");
		break ;
		case 12:printf("december is having 31 days");
		break ;
		default:printf("invalid input");
	}
}


