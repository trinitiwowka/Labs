#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
struct CallBook
{
	char FirstName[10];
	char LastName[20];
	long Num;
} my_callbook[20];

int AddCallBook(CallBook _callbook)
{
	char _FirstName[10], _LastName[20];
	long _Num = 0;

	printf("Add FirstName:");
	scanf("%s", _FirstName);
	strcat(_callbook.FirstName, _FirstName);

	printf("Add LastName:");
	scanf("%s", _LastName);
	strcat(_callbook.LastName, _LastName);

	printf("Add Tell:");
	scanf("%d", _Num);
	_callbook.Num = _Num;
	return 0;
}
int main()
{
	int menu_num = 0, count_now = 0;
	printf("menu: ");
	scanf("%d", menu_num);
	CallBook *HUI[20]
		switch (menu_num)
		{
		case 1:
			AddCallBook(my_callbook[count_now]);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}
}