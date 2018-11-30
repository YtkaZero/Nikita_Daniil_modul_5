#define _CRT_SECURE_NO_WARNINGS


#include "stdlib.h"
#include "stdio.h"

char Dannie[30];
int ads=2;
struct Settings
{
	int x;
	int sx;
	int ax;
	int bx;
	int y;
	int sy;
	int ay;
	int by;

};
char pr(int vvod2)
{
	char vv1;
		switch (vvod2)
		{
		case 0: vv1 = '0';  break;
		case 1: vv1 = '1';  break;
		case 2: vv1 = '2';  break;
		case 3: vv1 = '3';  break;
		case 4: vv1 = '4';  break;
		case 5: vv1 = '5';  break;
		case 6: vv1 = '6';  break;
		case 7: vv1 = '7';  break;
		case 8: vv1 = '8';  break;
		case 9: vv1 = '9';  break;
		default:vv1 = 0; break;
		}
		return vv1;
}

int vvod_all(struct Settings  def)
{
	int vvod2 = 0;
	int vv1 = 0;

	char vvod1[300];
	char zz[100];
	int zm[3];
	int m = 0;
	int mn = 0;
	int jk = 0;
	int j = 0;
	while (mn != 1)
	{
		for (int i = 0; i < 3; i++)
		{
			vvod1[i] = getchar();
			if (vvod1[i] == '\n')
			{
				if (i + 1 < 3)
				{
					vvod1[i + 1] = '\n';
					i++;
					if (i + 1 < 3)
					{
						vvod1[i + 1] = '\n';
						i++;
					}
				}
			}
		}
		if (vvod1[2] != '\n')
		{
			getchar();
		}
		for (int i = 0; i < 3; i++)
			switch (vvod1[i])
			{
			case '0': zz[j] = '0'; j++; jk++; break;
			case '1': zz[j] = '1'; j++; jk++; break;
			case '2': zz[j] = '2'; j++; jk++; break;
			case '3': zz[j] = '3'; j++; jk++; break;
			case '4': zz[j] = '4'; j++; jk++; break;
			case '5': zz[j] = '5'; j++; jk++; break;
			case '6': zz[j] = '6'; j++; jk++; break;
			case '7': zz[j] = '7'; j++; jk++; break;
			case '8': zz[j] = '8'; j++; jk++; break;
			case '9': zz[j] = '9'; j++; jk++; break;
			default:zz[j] = -52; j++; jk++; break;
			}
		j = 0;
		if (jk == 3)
		{
			mn = 1;
			if (ads == 2)
			{
				if (zz[0] >= '1' & zz[1] > '0' & zz[2] > '0')
				{
					printf("Repeat enter. Position need < 100\n");
					mn = 0;
				}
				else
					mn = 1;
			}
			if (ads == 16)
			{
				if (zz[0] >= '1' & zz[1] > '0' & zz[2] > '0')
				{
					printf("Repeat enter. Position need < 100\n");
					mn = 0;
				}
				else
					mn = 1;
			}
			
		}
		else
			mn = 0;
		
		jk = 0;
	}
	
	for(int i = 0;i<3;i++)
	{
		if (zz[i] == -52)
		{
			if (i == 0)
			{
				zz[i] = '0';
			}
			else
			{
				zz[i] = zz[i - 1];
				zz[i - 1] = '0';
				if (i == 2)
				{
					zz[i-1] = zz[i - 2];
					zz[i - 2] = '0';
				}
			}
		}
	}
	if (zz[0] == '0'&zz[1] == '0'&zz[2] == '0')
	{
		if (ads == 5)
		{
			zm[0] = def.sx/100;
			zm[1] = def.sx / 10 % 10;
			zm[2] = def.sx % 10;
			m = 1;
		}
		if (ads == 8)
		{
			zm[0] = def.ax / 100;
			zm[1] = def.ax / 10 % 10;
			zm[2] = def.ax % 10;
			m = 1;
		}
		if (ads == 11)
		{
			zm[0] = def.bx / 100;
			zm[1] = def.bx / 10 % 10;
			zm[2] = def.bx % 10;
			m = 1;
		}
		if (ads == 19)
		{
			zm[0] = def.sy / 100;
			zm[1] = def.sy / 10 % 10;
			zm[2] = def.sy % 10;
			m = 1;
		}
		if (ads == 22)
		{
			zm[0] = def.sy / 100;
			zm[1] = def.sy / 10 % 10;
			zm[2] = def.sy % 10;
			m = 1;
		}
		if (ads == 26)
		{
			zm[0] = def.sy / 100;
			zm[1] = def.sy / 10 % 10;
			zm[2] = def.sy % 10;
			m = 1;
		}
		if(m==1)
		for (int i = 0; i < 3; i++)
		{
			zz[i] = pr(zm[i]);
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		Dannie[ads] = zz[i];
		ads++;
	}
	if (ads == 14)
		ads = 16;
	return vvod2;

}

int proverka_vvoda(char zn1[], char zn2[])
{
	int mm = 0;
	for (int i = 0; i < strlen(zn1); i++)
	{
		if (zn1[i] != zn2[i])
			mm++;
	}
	if (mm == strlen(zn2))
	{
		return 1;
	}
	else
		return 0;
}

int menuse()
{
	struct Settings def, set;

	def.x = 0;
	def.y = 0;
	def.ax = 20;		// Можно брать из файла
	def.ay = 20;
	def.bx = 20;
	def.by = 20;
	def.sx = 10;
	def.sy = 10;
	Dannie[0] = 'P';
	Dannie[1] = 'X';
	Dannie[14] = 'P';
	Dannie[15] = 'Y';

	int sw = 1;
	while (sw)
	{
		printf("------MENU------\n1) Change setting\n2) Return\n3) Exit from programm\nYour choice\n>>");
		scanf("%d", &sw);
		switch (sw)
		{
		case 0:  printf("Sth wrong. Try again!\n"); break;
		case 1:
			printf("You in settings..\n"); getchar();
			printf("Enter the Xpos\n>>"); vvod_all(def);
			printf("Enter the Xspd\n>>"); vvod_all(def);
			printf("Enter the Xacc\n>>"); vvod_all(def);
			printf("Enter the Xbrk\n>>"); vvod_all(def);
			printf("Enter the Ypos\n>>"); vvod_all(def);
			printf("Enter the Yspd\n>>"); vvod_all(def);
			printf("Enter the Yacc\n>>"); vvod_all(def);
			printf("Enter the Ybrk\n>>"); vvod_all(def);

			for (int i = 0; i < 30; i++)
			{
				printf("%c", Dannie[i]);
			}
			printf("\n\n");
			ads = 2;
			break;
		case 2: printf("You choosed return\n"); break;
		case 3: printf("You choosed exit\n"); return 0;
		default: printf("Sth wrong. Try again!\n"); break;
		}
	}
	
	system("pause");
}

			
			



int main(int argc, char *argv[])
{

	char menu[] = "menu";
	char menu1[] = "MENU";
	char ctrl[] = "ctrl";
	char ctrl1[] = "CTRL";
	int pr = 0;
	while (pr != 2)
	{
		if ((argv[1] != NULL)&(argv[2] != NULL))
			if ((proverka_vvoda(argv[1], menu)) | (proverka_vvoda(argv[1], menu1) & (proverka_vvoda(argv[2], ctrl)) | (proverka_vvoda(argv[2], ctrl1))))
			{
				menuse();
			}
			else
			{
			}
		else
		{
			printf("Invalid values entered.\nRepeat enter.");
			pr = 2;
		}
	}

	return 0;
}