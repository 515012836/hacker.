#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include "hacker.h"
//��VC++2010��ſ��������������
//����ģʽҪ�л���Release�ſ���ִ��hacker.lib��̬�⡣
using namespace std;

#define X 45//��
#define Y 25//��
void login();
void menushow();
void one();
void two();
void three();
void four();
int option();
void window();
void inputPwd();

int main(void){
	window();
	login();
	while(1){
	menushow();
	int n=option();
	system("cls");
	switch(n){
			case 1:one();
				break;
			case 2:two();
				break;
			case 3:three();
				break;
			case 4:four();
				break;
			case 5:return 0;
			default:
				cout<<"������Ч�����������룡"<<endl;
		}
	}
	system("pause");
	return 0;
}
//��������
void inputPwd(char pwd[],int size){
	char x;
	int i=0;
	while(1){
		x=getch();
		if(x=='\r'){
			pwd[i]=0;//'\0'������
				break;
		}
		pwd[i++]=x;
		cout<<'*';
	}
	cout<<endl;
}
//��ƿ���̨���ڴ�С
void window(void){
	char cmd[128];
	sprintf_s(cmd,"mode con cols=%d lines=%d",X,Y);
	system(cmd);
}
//���빦��ѡ��
int option(void){
	int n=0;
	while(1){
		cout<<"��ѡ��";
		cin>>n;
		if(cin.fail()){
			cin.clear();
			getchar();
			cout<<"ѡ��������ѡ����ȷ��ѡ�"<<endl;
			system("pause");
		}else{
			break;
		}
	}
	return n;
}
//�˵�ѡ��
void menushow(void){
	cout<<"1.��վ404����\n"<<"2.��վ�۸Ĺ���\n"<<"3.�鿴������¼\n"
		<<"4.��վ�����޸�\n"<<"5.�˳�\n";
}
//��¼����
void login(void){
	string name;
	//string pwd;
	char pwd[64];
	while(1){
		cout<<"�������ʺţ�";
		cin>>name;
		cout<<"���������룺";
		inputPwd(pwd,sizeof(pwd));
		if(name=="admin"&& !strcmp(pwd,"123456")){
			system("cls");
			break;
		}else{
			cout<<"�ʺ������������������!"<<endl;
			system("pause");
			system("cls");
		}
	}
}
void one(void){//��վ404����
	char id[128];//��վID
	char response[4096];//�����󣬷������ķ��ؽ��
	cout<<"�����빥��ID��";
	scanf_s("%s",&id,sizeof(id));
	cout<<"�������֣����Ե�...\n";
	hk_404(id,response);
	string ret=UTF8ToGBK(response);
	cout<<ret<<endl;
	system("pause");
	system("cls");
}
void two(void){//��վ�۸Ĺ���
	char id[128];
	char response[4096];
	string paratext;
	cout<<"�����빥��ID��";
	scanf_s("%s",&id,sizeof(id));
	cout<<"������۸ĵ����ݣ�";
	cin>>paratext;
	GBKToUTF8(paratext);//ת�����룬��Ȼ����ʾ����
	hk_tamper(id,(char*)paratext.c_str(),response);
	string ret=UTF8ToGBK(response);
	cout<<ret<<endl;
	system("pause");
	system("cls");
}
void three(void){//�鿴������¼
	char id[128];
	char response[4096];
	cout<<"������ID��";
	scanf_s("%s",&id,sizeof(id));
	hk_record(id,response);
	string ret=UTF8ToGBK(response);
	cout<<ret<<endl;
	system("pause");
	system("cls");
}
void four(void){//��վ�����޸�
	char id[128];
	char response[4096];
	cout<<"������ID��";
	scanf_s("%s",&id,sizeof(id));
	hk_restore(id,response);
	string ret=UTF8ToGBK(response);
	cout<<ret<<endl;
	system("pause");
	system("cls");
}