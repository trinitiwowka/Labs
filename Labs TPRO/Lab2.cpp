#define _CRT_SECURE_NO_WARNINGS
/*#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<conio.h>
int DeleteNote()
{
	char tmp_tell[13];
	printf("Enter tell num:\n");
	scanf("%12s", &tmp_tell);
	while (getchar() != '\n');
	for (int i = 0; i < LENGTHCALLBOOK; ++i)
	{
		if (!strcmp(my_call_tell[i].tell, tmp_tell))
		{
			my_call_tell[i].firstName[0] = '\0';
			my_call_tell[i].lastName[0] = '\0';
			my_call_tell[i].tell[0] = '\0';
			printf("DELETE SUCCSESSFULLY!\n");
			system("pause");
			return 0;
		}
	}
	printf("Tell Not Found\n");
	system("PAUSE");
	return 1;
}

int main()
{
	char tmp_selection;
	printf("hAllo!\n");
	while (true)
	{
		printf("1-Add note\n2-Delete note\n3-Search note\n4-Show all\n5-exit\n");
		scanf("%1c", &tmp_selection);
		while (getchar() != '\n');
		switch (tmp_selection)
		{
		case '1':
			AddNote();
			break;
		case '2':
			DeleteNote();
			break;
		case '3':
			SearchNote();
			break;
		case '4':
			PrintAll();
			break;
		case '5':
			printf("Good BY\n");
			system("pause");
			return 1;
			break;
		default:
			printf("Invalid choice\n");
			break;
		}
	}
	return 0;
}*/
#include <stdlib.h>
#include <iostream>

struct Call_tell       //��������� ���������� ������ ������
{
	char firstName[11];
	char lastName[21];
	char tell[13];

	Call_tell *Next, *Prev; //��������� �� ������ ���������� � ����������� ��������� ������
	Call_tell() :firstName("\0"),lastName("\0"),tell("\0") {};
};

struct List   //������� ��� ������ ������
{
	Call_tell *Head, *Tail; //��������� �� ������ ������ ������ � ��� �����
	void Add();
	int isNumFree(char temp_num[13]);

	List() :Head(NULL), Tail(NULL) {}; //�������������� ������ ��� ������
	void Show(); //������� ����������� ������ �� ������
	void EarceList();
	int Search();
};

void List::EarceList() //���� ����������
{
	while (Head) //���� �� ������ �� ������ ������ ���-�� ���� 
	{
		Tail = Head->Next; //��������� ����� ������ ���������� ����� ������
		delete Head; //������� ������ �� ������� �����
		Head = Tail; //����� ������ ������ �� ����� ���������� ��������
	}
}
int List::Search()
{
	if (Head==NULL)
	{
		printf("PUSTO!!!\n");
		return -1;
	}

	Call_tell *tmp = Head;
	char temp_lastname[21];
	int          i = 0;
	printf("Enter last name:\n");
	scanf("%20s", &temp_lastname);
	while (getchar() != '\n');

	while(tmp)
	{
		if (!strcmp(tmp->lastName, temp_lastname))
		{
			printf("Last name found!\n");
			printf("[Note #%d]\n", i);
			printf("First name: %s\n", tmp->firstName);
			printf("Last Name: %s\n", tmp->lastName);
			printf("Tell: %s\n", tmp->tell);
			system("PAUSE");
			return 0;//������� ������ ��������� ������� � �������, ����� �� �������� - ����������� ��� ������.
		}
		tmp = tmp->Next;
		++i;
	}
	printf("Last name not found!!!\n");
	system("PAUSE");
	return 1;
}
void List::Add()
{
	Call_tell *temp = new Call_tell; //��������� ������ ��� ����� ������� ���������
	temp->Next = NULL;  //���������, ��� ���������� �� ���������� ������ �����
	//
	//temp->x = _x;//���������� ��� ����� ����
	//
	printf("Enter First Name:\n");
	scanf("%10s", &temp->firstName);
	while (getchar() != '\n');

	printf("Enter Last Name:\n");
	scanf("%20s", &temp->lastName);
	while (getchar() != '\n');

	char tmp_tell[13];
a:
	printf("Enter tell num:\n");
	scanf("%12s", &tmp_tell);//add function clean character
	if (!isNumFree(tmp_tell))
	{
		printf("Numper NOT FREE\n");
		goto a;
	}
	strcat(temp->tell, tmp_tell);
	while (getchar() != '\n');

	//
	if (Head != NULL) //���� ������ �� ����
	{
		temp->Prev = Tail; //��������� ����� �� ���������� ������� � �����. ����
		Tail->Next = temp; //��������� ����� ���������� �� ������� ��������
		Tail = temp; //������ ����� ������
	}
	else //���� ������ ������
	{
		temp->Prev = NULL; //���������� ������� ��������� � �������
		Head = Tail = temp; //������=�����=��� �������, ��� ������ ��������
	}
	printf("Note added!\n");
	system("pause");
}
int List::isNumFree(char temp_num[13])
{
	Call_tell *temp = Head;
	while (temp)
	{
		if (!strcmp(temp->tell, temp_num))
			return 0;
		temp = temp->Next;
	}
	return 1;
}
void List::Show()
{
	//������� ������ � �����
	Call_tell *temp = Head;
	int           i = 0;
	//��������� ��������� �� ����� ���������� ��������
	printf("----------------All Note-------------------\n");
	while (temp != NULL) //���� �� ���������� ������ ��������
	{
			if (temp->firstName[0] != '\0')
			{
				printf("[Note #%d]\n", i);
				printf("First name: %s\n", temp->firstName);
				printf("Last Name: %s\n", temp->lastName);
				printf("Tell: %s\n", temp->tell);
			}
			printf("\n");
		temp = temp->Next; //���������, ��� ����� ����� ����������� ��������
		++i;
	}
	printf("-------------------------------------------\n");
	system("pause");

	//������� ������ � ������
	//temp = Head; //�������� ��������� �� ����� ������� ��������
	//while (temp != NULL) //���� �� �������� ������ ��������
	//{
	//	cout << temp->x << " "; //������� ������ ��������� �������� �� �����
	//	temp = temp->Next; //����� ������ �� ����� ���������� ��������
	//}
	
}


int main()
{
	system("CLS");
	List lst; //��������� ����������, ��� ������� ���� ������
	lst.Add(); //��������� � ������ ��������
	lst.Add();
	lst.Search();
	lst.Show(); //���������� ������ �� ������
	system("PAUSE");
}
