#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void print_menu(int x);
void draw_line(void);
void print_info(void);
void start_game(void);
int get_swing_result(void);
int get_pass_result(void);
void start_inning(void);
void print_score(int ining, int score1, int score2, int score3);
void print_count(int ball, int strike, int out);
void print_base(int base1, int base2, int base3);

int main(void)
{
	int x=5;
	print_menu(x);
}


void print_menu(int x)
{
	int y = 3;
	while (x != 1&& x!= 2 && x != 3)//�ٸ� ������ ������ �ݺ��ǰ�
	{
	draw_line();
	printf("\n\n1. ���� ����\n\n");
	printf("2.���� ����\n\n");
	printf("3.���� ����\n\n");
	draw_line();
	printf("\n�����ϰ��� �ϴ� �޴��� �Է����ּ���:");
	scanf("%d", &x);
	srand((unsigned)time(NULL));//���� ����
	switch (x)
	{
	case 1://1������
		start_game();//���ӽ���
		while (y != -1)//������ ������ -1�� ������ �ٽ� ����(ȭ���� start_game�� �ִ�)
		{
			scanf("%d", &y);
			if (y == -1)//-1�ܿ� �ٸ��Ŵ����� ��� �ݺ�
			{
				system("cls");
				x = 100;//x�� 100�ǵǼ� while�� �ݺ��ȴ�.(1,2,3�� �ƴϸ� ��)
			}
		}
		break;
	case 3:
		printf("���α׷��� ���� �մϴ�...\n");//���α׷� ����
		break;
	case 2:
		print_info();//���� ����
		system("cls");
		x = 100;//x�� 100�̾ ������ â �ٽ� �ݺ�
		break;
	default:
		system("cls");
		printf("�޴��� �ٽ� ������ �ּ���.\n");//1,2,3,�� �ٸ� ������ ������ ��
		break;
	}
	}
}

void draw_line(void)
{
	for (int x = 1; x < 51; x++)//=50�� ���
	{
		printf("=");
	}
}

void print_info(void)
{
	int a=4;//-1�� �ƴϸ� ��
	while (a !=-1)//-1�Է��Ҷ����� �ݺ�
	{
		system("cls");
		printf("--------------------------�̴� �߱� ���� ����---------------------------\n");//����â
		printf("�� ������ �߱��� ���� �Ϻ� ������ '�̴� �߱� ����' �Դϴ�.\n");
		printf("  1. ������ �� 3ȸ�� �̷���� �ֽ��ϴ�.\n");
		printf("  2. �÷��̾�� ���� Ȥ�� ���� �Ÿ� �� �ֽ��ϴ�.\n");
		printf("  3. ��Ÿ�� ġ�ų� �� ���� �Ǹ� ��� �� �� �ֽ��ϴ�.\n");
		printf("  4. ���ڿ� ���� �ƿ��� ������, �ö��� �ƿ�, ��Ʈ����ũ �ƿ��� �ֽ��ϴ�.\n");
		printf("  5. 3ȸ���� ������ ������ 10�� �̻��̸� ���ӿ��� �¸��ϰ� �˴ϴ�.\n");
		printf("------------------------------------------------------------------------\n");
		printf("���� �޴��� ���ư���(-1):");
		scanf("%d", &a);
	}
}

int get_pass_result(void)
{
	int pass_result;
	int ball = rand() % 100;
	if (0 <= ball && ball < 60) //�� Ȯ�� 60%
	{
		pass_result = 1;//��
	}
	else //��Ʈ����ũ Ȯ�� 40%
	{
		pass_result = 2;//��Ʈ����ũ
	}
	return pass_result;
}

int get_swing_result(void)
{
	int swing_result=500;//��� �������� ���� ���ֶ�� ���� ���������� 500����
	int ball = rand() % 100;
	if (0 <= ball && ball < 14) 
	{
		swing_result = 1;//��Ÿ
	}
	if (14 <= ball && ball < 21) 
	{
		swing_result = 2;//2��Ÿ
	}
	if (21 <= ball && ball < 26) 
	{
		swing_result = 3;//3��Ÿ
	}
	if (26 <= ball && ball < 29) 
	{
		swing_result = 4;//Ȩ��
	}
	if (29 <= ball && ball < 62) 
	{
		swing_result = 5;//�ö��� �ƿ�
	}
	if (62 <= ball && ball < 100) 
	{
		swing_result = 6;//��Ʈ����ũ
	}
	return swing_result;
}

void start_game(void)
{
	system("cls");
	draw_line();
	printf("\n������ �����մϴ�.\n");
	draw_line();
	printf("\n\n");
	start_inning();
}

void start_inning(void)
{
	int x=7, swing, pass, ball=0, strike=0, out=0, base1=0,base2=0,base3=0,score=0,ining=1,score1=0, score2=0, score3=0 ;
	while(ining<=3)//3�̴׸� ����
	{
		while (out <= 2)//3�ƿ� �Ǹ� �̴� ����
		{
			x = 0;
			while (x != 1 && x != 2)//1,2 �ܿ� �ٸ��� ������ �ݺ�
			{
				draw_line();
				printf("\n%d ȸ", ining);
				print_score(ining,score1,score2,score3);//������
				print_count(ball, strike, out);//�ƿ�ī��Ʈ ���
				print_base(base1, base2, base3);//���̽� ��Ȳ ���
				printf("\n1. ����,    2.�Ÿ���\n");
				printf("�Է�:");
				scanf("%d", &x);
				if (x == 1)//����
				{
					swing = get_swing_result();
					system("cls");
					if (swing == 1)//��Ÿ
					{
						system("cls");
						printf("��Ÿ �Դϴ�.\n");
						strike = 0;//��ī��Ʈ �ʱ�ȭ
						ball = 0;
						if (base1 == 0)//1�� ���� ������
							base1 = 1;//1�� ���� �߰�
						else if (base1 == 1)//1�� ���� ������
						{
							if (base2 == 0)//2�� ���� ������
								base2 = 1;//2�� ���� �߰�
							else if (base2 == 1)//2�� ���� ������
							{
								if (base3 == 0)//3�� ���� ������
									base3 = 1;//3������ �߰�
								else if (base3 == 1)//3�� ���� ������
									score++;//���� 1 �߰�
								printf("Ȩ��! ������ ���� �ø��ϴ�.\n");
							}
						}
					}
					if (swing == 6)//��Ʈ����ũ
					{
						system("cls");
						printf("��Ʈ����ũ �Դϴ�.\n");
						strike++;//��Ʈ����ũ ī��Ʈ 1�߰�
					}
					if (swing == 5)//�ö��� �ƿ�
					{
						system("cls");
						printf("�ö��� �ƿ��Դϴ�.\n");
						strike = 0;//��ī��Ʈ �ʱ�ȭ
						ball = 0;
						out++;//�ƿ� ī��Ʈ 1 �߰�
					}
					if (swing == 4)//Ȩ��
					{
						system("cls");
						printf("Ȩ���Դϴ�.\n");
						strike = 0;//��ī��Ʈ �ʱ�ȭ
						ball = 0;
						if (base3 == 1)//3�� ���� ������
						{
							score++;//1�� �߰�
							printf("3�� ���� Ȩ��! ������ ���� �ø��ϴ�.\n");
							base3 = 0;
						}
						if (base2 == 1)//2�� ���� ������
						{
							score++;//1�� �߰�
							printf("2�� ���� Ȩ��! ������ ���� �ø��ϴ�.\n");
							base2 = 0;
						}
						if (base1 == 1)//1�� ���� ������
						{
							score++;//1�� �߰�
							printf("1�� ���� Ȩ��! ������ ���� �ø��ϴ�.\n");
							base1 = 0;
						}
						score++;//Ÿ�ڰ� 1�� �ø�
						printf("Ÿ�� Ȩ��! ������ ���� �ø��ϴ�.\n");
					}
					if (swing == 3)//3��Ÿ
					{
						system("cls");
						printf("3��Ÿ�Դϴ�.\n");
						strike = 0;//��ī��Ʈ �ʱ�ȭ
						ball = 0;
						if (base2 == 1)//2�翡 ���� ������
						{
							score++;//1�� �߰�
							printf("2�� ���� Ȩ��! ������ ���� �ø��ϴ�.\n");
							base2 = 0;
						}
						if (base3 == 1)//3�翡 ���� ������
						{
							score++;//1�� �߰�
							printf("3�� ���� Ȩ��! ������ ���� �ø��ϴ�.\n");
							base3 = 0;
						}
						if (base1 == 1)//1�翡 ����������
						{
							score++;//1�� �߰�
							printf("1�� ���� Ȩ��! ������ ���� �ø��ϴ�.\n");
							base1 = 0;
						}
						base3 = 1;//3�� ���� �߰�
					}
					if (swing == 2)//2��Ÿ
					{
						system("cls");
						printf("2��Ÿ �Դϴ�.\n");
						strike = 0;//��ī��Ʈ �ʱ�ȭ
						ball = 0;
						if (base3 == 1)//3�� ���� ������
						{
							score++;//1�� �߰�
							printf("3�� ���� Ȩ��! ������ ���� �ø��ϴ�.\n");
							base3 = 0;
						}
						if (base2 == 1)//2�� ���� ������
						{
							score++;//���� �߰�
							printf("2�� ���� Ȩ��! ������ ���� �ø��ϴ�.\n");
							base2 = 0;
						}
						if (base1 == 1)//1�� ���� ������
						{
							base1 = 0;
							base3 = 1;//3��� �̵�
						}
						base2 = 1;//2�� ���� �߰�
					}
				 }
				else if (x == 2)//�Ÿ���
				{
					pass = get_pass_result();
					system("cls");
					if (pass == 1)//��
					{
						printf("���Դϴ�.\n");
						ball++;//�� �߰�
					}
					if (pass == 2)//��Ʈ����ũ
					{
						printf("��Ʈ����ũ �Դϴ�.\n");
						strike++;//��Ʈ����ũ �߰�
					}
				}
				else//�߸� �Է�
				{
				system("cls");
				printf("���ڸ� �ٽ� �Է��ϼ���.\n");
                }
				if (ball == 4)//����
				{
					printf("���� �Դϴ�.\n");
					strike = 0;//��ī��Ʈ �ʱ�ȭ
					ball = 0;
					if (base1 == 0)//��Ÿ�� ����
						base1 = 1;
					else if (base1 == 1)
					{
						if (base2 == 0)
							base2 = 1;
						else if (base2 == 1)
						{
							if (base3 == 0)
								base3 = 1;
							else if (base3 == 1)
							{
								score++;
								printf("Ȩ��! ������ ���� �ø��ϴ�.\n");
							}
						}
					}
				}
				if (strike == 3)//���� �ƿ�
				{
					printf("��Ʈ����ũ �ƿ�!!\n");
					strike = 0;//��ī��Ʈ �ʱ�ȭ
					ball = 0;
					out++;//�ƿ� ī��Ʈ �߰�
				}
				if (ining == 1)//1�̴׿� ���� ���� socre1�� �־��ֱ�
				{
					score1 = score;
				}
				if (ining == 2)//2�̴׿� ���� ���� socre2�� �־��ֱ�
				{
					score2 = score;
				}
				if (ining == 3)//3�̴׿� ���� ���� socre3�� �־��ֱ�
				{
					score3 = score;
				}
			}
		}
		printf("�̴��� ����Ǿ����ϴ�.\n");
		out = 0;//����ʱ�ȭ(������ �̴׺��� score123�� ����)
		score = 0;
		base1 = 0;
		base2 = 0;
		base3 = 0;
		ining++;
		if (ining == 2) //1�̴� ������ 10�� �̻�
		{
			if (score1 > 9)
			{
				ining = 5;//���� ������
				printf("\n��Ⱑ ����Ǿ����ϴ�.\n");
				draw_line();
				print_score(ining, score1, score2, score3);
				printf("\n*���: �÷��̾ �¸��Ͽ����ϴ�.");
			}
		}
		if (ining == 3)//2�̴� ������ 10�� �̻�
		{
			if (score1 + score2 > 9)
			{
				ining = 6;//���� ������
				printf("\n��Ⱑ ����Ǿ����ϴ�.\n");
				draw_line();
				print_score(ining, score1, score2, score3);
				printf("\n*���: �÷��̾ �¸��Ͽ����ϴ�.");

			}
		}
		if (ining == 4)
		{
			if (score1 + score2 + score3 > 9)//3�̴� ������ 10�� �̻�
			{
				printf("\n��Ⱑ ����Ǿ����ϴ�.\n");
				draw_line();
				print_score(ining, score1, score2, score3);
				printf("\n*���: �÷��̾ �¸��Ͽ����ϴ�.");
			}
			else if (score1 + score2 + score3 < 9)//3�̴� ������ 10�� �̸�
			{
				printf("\n��Ⱑ ����Ǿ����ϴ�.\n");
				draw_line();
				print_score(ining, score1, score2, score3);
				printf("\n*���: �÷��̾ �й��Ͽ����ϴ�.");
			}
		}
	}
	printf("\n���� �޴��� ���ư���(-1):");//-1������ ���� �޴��� ���ư����� ����� prinf menu�� ����
}


void print_score(int ining,int score1,int score2, int score3)
{
	int total = score1 + score2 + score3;
	if (ining == 1)//1�̴׶� ������
	{
		printf("\n������������������������������������������������������������������������������������������������\n");
		printf("��        1ȸ   2ȸ   3ȸ            ����       ��\n");
		printf(" ����     %d                                             \n",score1);
		printf("��                                              ��\n");
		printf("������������������������������������������������������������������������������������������������\n");
	}
	if (ining == 2)//2�̴׶� ������
	{
		printf("\n������������������������������������������������������������������������������������������������\n");
		printf("��        1ȸ   2ȸ   3ȸ            ����       ��\n");
		printf(" ����     %d    %d                                           \n",score1,score2);
		printf("��                                              ��\n");
		printf("������������������������������������������������������������������������������������������������\n");
	}
	if (ining == 3)//3�̴׶� ������
	{
		printf("\n������������������������������������������������������������������������������������������������\n");
		printf("��        1ȸ   2ȸ   3ȸ            ����       ��\n");
		printf(" ����       %d    %d     %d                                     \n", score1, score2,score3);
		printf("��                                              ��\n");
		printf("������������������������������������������������������������������������������������������������\n");
	}
	if (ining == 4)//4�̴��� ���� �̴��� 4�� ��������
	{
		printf("\n������������������������������������������������������������������������������������������������\n");
		printf("��        1ȸ   2ȸ   3ȸ            ����       ��\n");
		printf(" ����       %d    %d     %d             %d                          \n", score1, score2, score3,total);
		printf("��                                              ��\n");
		printf("������������������������������������������������������������������������������������������������\n");
	}
	if (ining == 5)//1�̴� ������ �̱� ���
	{
		printf("\n������������������������������������������������������������������������������������������������\n");
		printf("��        1ȸ   2ȸ   3ȸ            ����       ��\n");
		printf(" ����     %d                          %d                          \n", score1, total);
		printf("��                                              ��\n");
		printf("������������������������������������������������������������������������������������������������\n");
	}
	if (ining == 6)//2�̴� ������ �̱� ���
	{
		printf("\n������������������������������������������������������������������������������������������������\n");
		printf("��        1ȸ   2ȸ   3ȸ            ����       ��\n");
		printf(" ����     %d    %d                    %d                          \n", score1, score2, total);
		printf("��                                              ��\n");
		printf("������������������������������������������������������������������������������������������������\n");
	}
}

void print_count(int ball, int strike, int out)
{
	switch (ball)//�� ǥ����
	{
	    case 0:
			printf("B �ۡۡ�\n");
			break;
		case 1:
			printf("B �ܡۡ�\n");
			break;
		case 2:
			printf("B �ܡܡ�\n");
			break;
		case 3:
			printf("B �ܡܡ�\n");
			break;
	}
	switch (strike)//��Ʈ����ũ ǥ����
	{
	case 0:
		printf("S �ۡ�\n");
		break;
	case 1:
		printf("S �ܡ�\n");
		break;
	case 2:
		printf("S �ܡ�\n");
		break;
	}
	switch (out)//�ƿ� ǥ����
	{
	case 0:
		printf("O �ۡ�\n");
		break;
	case 1:
		printf("O �ܡ�\n");
		break;
	case 2:
		printf("O �ܡ�\n");
		break;
	}
}

void print_base(int base1, int base2, int base3)//�� ���̺��� ����� ���� 2�� �̹Ƿ� 2^3 ��ü ����� ���� 8
{
	if (base1 == 0 && base2 == 0 && base3 == 0)
	{
		printf("               ��            \n");
		printf("            ��   ��            \n");
		printf("         ��        ��           \n");
		printf("       ��            ��           \n");
		printf("      ��               ��         \n");
		printf("       ��             ��         \n");
		printf("         ��         ��         \n");
		printf("           ��    ��           \n");
		printf("              ��            \n");
	}
	if (base1 == 1 && base2 == 0 && base3 == 0 )
	{
		printf("               ��            \n");
		printf("            ��   ��            \n");
		printf("         ��        ��           \n");
		printf("       ��            ��           \n");
		printf("      ��               ��         \n");
		printf("       ��             ��         \n");
		printf("         ��         ��         \n");
		printf("           ��    ��           \n");
		printf("              ��            \n");
	}
	if (base1 == 1 && base2 == 1 && base3 == 0 )
	{
		printf("               ��            \n");
		printf("            ��   ��            \n");
		printf("         ��        ��           \n");
		printf("       ��            ��           \n");
		printf("      ��               ��         \n");
		printf("       ��             ��         \n");
		printf("         ��         ��         \n");
		printf("           ��    ��           \n");
		printf("              ��            \n");
	}
	if (base1 == 1 && base2 == 1 && base3 == 1)
	{
		printf("               ��            \n");
		printf("            ��   ��            \n");
		printf("         ��        ��           \n");
		printf("       ��            ��           \n");
		printf("      ��               ��         \n");
		printf("       ��             ��         \n");
		printf("         ��         ��         \n");
		printf("           ��    ��           \n");
		printf("              ��            \n");
	}
	if (base1 == 1 && base2 == 0 && base3 == 1)
	{
		printf("               ��            \n");
		printf("            ��   ��            \n");
		printf("         ��        ��           \n");
		printf("       ��            ��           \n");
		printf("      ��               ��         \n");
		printf("       ��             ��         \n");
		printf("         ��         ��         \n");
		printf("           ��    ��           \n");
		printf("              ��            \n");
	}
	if (base1 == 0 && base2 == 1 && base3 == 0 )
	{
		printf("               ��            \n");
		printf("            ��   ��            \n");
		printf("         ��        ��           \n");
		printf("       ��            ��           \n");
		printf("      ��               ��         \n");
		printf("       ��             ��         \n");
		printf("         ��         ��         \n");
		printf("           ��    ��           \n");
		printf("              ��            \n");
	}
	if (base1 == 0 && base2 == 1 && base3 == 1 )
	{
		printf("               ��            \n");
		printf("            ��   ��            \n");
		printf("         ��        ��           \n");
		printf("       ��            ��           \n");
		printf("      ��               ��         \n");
		printf("       ��             ��         \n");
		printf("         ��         ��         \n");
		printf("           ��    ��           \n");
		printf("              ��            \n");
	}
	if (base1 == 0 && base2 == 0 && base3 == 1 )
	{
		printf("               ��            \n");
		printf("            ��   ��            \n");
		printf("         ��        ��           \n");
		printf("       ��            ��           \n");
		printf("      ��               ��         \n");
		printf("       ��             ��         \n");
		printf("         ��         ��         \n");
		printf("           ��    ��           \n");
		printf("              ��            \n");
	}
}
