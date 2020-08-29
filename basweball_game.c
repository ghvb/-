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
	while (x != 1&& x!= 2 && x != 3)//다른 석택지 누르면 반복되게
	{
	draw_line();
	printf("\n\n1. 게임 시작\n\n");
	printf("2.게임 설명\n\n");
	printf("3.게임 종료\n\n");
	draw_line();
	printf("\n선택하고자 하는 메뉴를 입력해주세요:");
	scanf("%d", &x);
	srand((unsigned)time(NULL));//난수 생성
	switch (x)
	{
	case 1://1누를때
		start_game();//게임시작
		while (y != -1)//게임이 끝나고 -1을 누르면 다시 시작(화면은 start_game에 있다)
		{
			scanf("%d", &y);
			if (y == -1)//-1외에 다른거누르면 계속 반복
			{
				system("cls");
				x = 100;//x가 100되되서 while이 반복된다.(1,2,3만 아니면 됨)
			}
		}
		break;
	case 3:
		printf("프로그램을 종료 합니다...\n");//프로그램 종료
		break;
	case 2:
		print_info();//설명 띄우기
		system("cls");
		x = 100;//x가 100이어서 선택지 창 다시 반복
		break;
	default:
		system("cls");
		printf("메뉴를 다시 선택해 주세요.\n");//1,2,3,외 다른 선택지 누르면 뜸
		break;
	}
	}
}

void draw_line(void)
{
	for (int x = 1; x < 51; x++)//=50번 출력
	{
		printf("=");
	}
}

void print_info(void)
{
	int a=4;//-1만 아니면 됨
	while (a !=-1)//-1입력할때까지 반복
	{
		system("cls");
		printf("--------------------------미니 야구 게임 설명---------------------------\n");//설명창
		printf("본 게임은 야구의 룰을 일부 적용한 '미니 야구 게임' 입니다.\n");
		printf("  1. 게임은 총 3회로 이루어져 있습니다.\n");
		printf("  2. 플레이어는 스윙 혹은 공을 거를 수 있습니다.\n");
		printf("  3. 안타를 치거나 볼 넷이 되면 출루 할 수 있습니다.\n");
		printf("  4. 주자에 의한 아웃은 없으며, 플라이 아웃, 스트라이크 아웃만 있습니다.\n");
		printf("  5. 3회까지 득점한 점수가 10점 이상이면 게임에서 승리하게 됩니다.\n");
		printf("------------------------------------------------------------------------\n");
		printf("메인 메뉴로 돌아가기(-1):");
		scanf("%d", &a);
	}
}

int get_pass_result(void)
{
	int pass_result;
	int ball = rand() % 100;
	if (0 <= ball && ball < 60) //볼 확률 60%
	{
		pass_result = 1;//볼
	}
	else //스트라이크 확률 40%
	{
		pass_result = 2;//스트라이크
	}
	return pass_result;
}

int get_swing_result(void)
{
	int swing_result=500;//계속 지역변수 선언 해주라고 떠서 임의적으로 500넣음
	int ball = rand() % 100;
	if (0 <= ball && ball < 14) 
	{
		swing_result = 1;//안타
	}
	if (14 <= ball && ball < 21) 
	{
		swing_result = 2;//2루타
	}
	if (21 <= ball && ball < 26) 
	{
		swing_result = 3;//3루타
	}
	if (26 <= ball && ball < 29) 
	{
		swing_result = 4;//홈런
	}
	if (29 <= ball && ball < 62) 
	{
		swing_result = 5;//플라이 아웃
	}
	if (62 <= ball && ball < 100) 
	{
		swing_result = 6;//스트라이크
	}
	return swing_result;
}

void start_game(void)
{
	system("cls");
	draw_line();
	printf("\n게임을 시작합니다.\n");
	draw_line();
	printf("\n\n");
	start_inning();
}

void start_inning(void)
{
	int x=7, swing, pass, ball=0, strike=0, out=0, base1=0,base2=0,base3=0,score=0,ining=1,score1=0, score2=0, score3=0 ;
	while(ining<=3)//3이닝만 진행
	{
		while (out <= 2)//3아웃 되면 이닝 종료
		{
			x = 0;
			while (x != 1 && x != 2)//1,2 외에 다른거 누르면 반복
			{
				draw_line();
				printf("\n%d 회", ining);
				print_score(ining,score1,score2,score3);//점수판
				print_count(ball, strike, out);//아웃카운트 출력
				print_base(base1, base2, base3);//베이스 상황 출력
				printf("\n1. 스윙,    2.거르기\n");
				printf("입력:");
				scanf("%d", &x);
				if (x == 1)//스윙
				{
					swing = get_swing_result();
					system("cls");
					if (swing == 1)//안타
					{
						system("cls");
						printf("안타 입니다.\n");
						strike = 0;//볼카운트 초기화
						ball = 0;
						if (base1 == 0)//1루 주자 없으면
							base1 = 1;//1루 주자 추가
						else if (base1 == 1)//1루 주자 있을때
						{
							if (base2 == 0)//2루 주자 없으면
								base2 = 1;//2루 주자 추가
							else if (base2 == 1)//2루 주자 있을때
							{
								if (base3 == 0)//3루 주자 없으면
									base3 = 1;//3루주자 추가
								else if (base3 == 1)//3루 주자 있으면
									score++;//점수 1 추가
								printf("홈인! 점수를 한점 올립니다.\n");
							}
						}
					}
					if (swing == 6)//스트라이크
					{
						system("cls");
						printf("스트라이크 입니다.\n");
						strike++;//스트라이크 카운트 1추가
					}
					if (swing == 5)//플라이 아웃
					{
						system("cls");
						printf("플라이 아웃입니다.\n");
						strike = 0;//볼카운트 초기화
						ball = 0;
						out++;//아웃 카운트 1 추가
					}
					if (swing == 4)//홈런
					{
						system("cls");
						printf("홈런입니다.\n");
						strike = 0;//볼카운트 초기화
						ball = 0;
						if (base3 == 1)//3루 주자 있으면
						{
							score++;//1점 추가
							printf("3루 주자 홈인! 점수를 한점 올립니다.\n");
							base3 = 0;
						}
						if (base2 == 1)//2루 주자 있으면
						{
							score++;//1점 추가
							printf("2루 주자 홈인! 점수를 한점 올립니다.\n");
							base2 = 0;
						}
						if (base1 == 1)//1루 주자 있으면
						{
							score++;//1점 추가
							printf("1루 주자 홈인! 점수를 한점 올립니다.\n");
							base1 = 0;
						}
						score++;//타자가 1점 올림
						printf("타자 홈인! 점수를 한점 올립니다.\n");
					}
					if (swing == 3)//3루타
					{
						system("cls");
						printf("3루타입니다.\n");
						strike = 0;//볼카운트 초기화
						ball = 0;
						if (base2 == 1)//2루에 주자 있으면
						{
							score++;//1점 추가
							printf("2루 주자 홈인! 점수를 한점 올립니다.\n");
							base2 = 0;
						}
						if (base3 == 1)//3루에 주자 있으면
						{
							score++;//1점 추가
							printf("3루 주자 홈인! 점수를 한점 올립니다.\n");
							base3 = 0;
						}
						if (base1 == 1)//1루에 주자있으면
						{
							score++;//1점 추가
							printf("1루 주자 홈인! 점수를 한점 올립니다.\n");
							base1 = 0;
						}
						base3 = 1;//3루 주자 추가
					}
					if (swing == 2)//2루타
					{
						system("cls");
						printf("2루타 입니다.\n");
						strike = 0;//볼카운트 초기화
						ball = 0;
						if (base3 == 1)//3루 주자 있으면
						{
							score++;//1점 추가
							printf("3루 주자 홈인! 점수를 한점 올립니다.\n");
							base3 = 0;
						}
						if (base2 == 1)//2루 주자 있으면
						{
							score++;//점수 추가
							printf("2루 주자 홈인! 점수를 한점 올립니다.\n");
							base2 = 0;
						}
						if (base1 == 1)//1루 주자 있으면
						{
							base1 = 0;
							base3 = 1;//3루로 이동
						}
						base2 = 1;//2루 주자 추가
					}
				 }
				else if (x == 2)//거르기
				{
					pass = get_pass_result();
					system("cls");
					if (pass == 1)//볼
					{
						printf("볼입니다.\n");
						ball++;//볼 추가
					}
					if (pass == 2)//스트라이크
					{
						printf("스트라이크 입니다.\n");
						strike++;//스트라이크 추가
					}
				}
				else//잘못 입력
				{
				system("cls");
				printf("숫자를 다시 입력하세요.\n");
                }
				if (ball == 4)//볼넷
				{
					printf("볼넷 입니다.\n");
					strike = 0;//볼카운트 초기화
					ball = 0;
					if (base1 == 0)//안타와 동일
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
								printf("홈인! 점수를 한점 올립니다.\n");
							}
						}
					}
				}
				if (strike == 3)//삼진 아웃
				{
					printf("스트라이크 아웃!!\n");
					strike = 0;//볼카운트 초기화
					ball = 0;
					out++;//아웃 카운트 추가
				}
				if (ining == 1)//1이닝에 얻은 점수 socre1에 넣어주기
				{
					score1 = score;
				}
				if (ining == 2)//2이닝에 얻은 점수 socre2에 넣어주기
				{
					score2 = score;
				}
				if (ining == 3)//3이닝에 얻은 점수 socre3에 넣어주기
				{
					score3 = score;
				}
			}
		}
		printf("이닝이 종료되었습니다.\n");
		out = 0;//모두초기화(점수는 이닝별로 score123에 들어갔음)
		score = 0;
		base1 = 0;
		base2 = 0;
		base3 = 0;
		ining++;
		if (ining == 2) //1이닝 끝나고 10점 이상
		{
			if (score1 > 9)
			{
				ining = 5;//게임 끝내기
				printf("\n경기가 종료되었습니다.\n");
				draw_line();
				print_score(ining, score1, score2, score3);
				printf("\n*결과: 플레이어가 승리하였습니다.");
			}
		}
		if (ining == 3)//2이닝 끝나고 10점 이상
		{
			if (score1 + score2 > 9)
			{
				ining = 6;//게임 끝내기
				printf("\n경기가 종료되었습니다.\n");
				draw_line();
				print_score(ining, score1, score2, score3);
				printf("\n*결과: 플레이어가 승리하였습니다.");

			}
		}
		if (ining == 4)
		{
			if (score1 + score2 + score3 > 9)//3이닝 끝나고 10점 이상
			{
				printf("\n경기가 종료되었습니다.\n");
				draw_line();
				print_score(ining, score1, score2, score3);
				printf("\n*결과: 플레이어가 승리하였습니다.");
			}
			else if (score1 + score2 + score3 < 9)//3이닝 끝나고 10점 미만
			{
				printf("\n경기가 종료되었습니다.\n");
				draw_line();
				print_score(ining, score1, score2, score3);
				printf("\n*결과: 플레이어가 패배하였습니다.");
			}
		}
	}
	printf("\n메인 메뉴로 돌아가기(-1):");//-1누르면 메인 메뉴로 돌아가지는 기능은 prinf menu에 있음
}


void print_score(int ining,int score1,int score2, int score3)
{
	int total = score1 + score2 + score3;
	if (ining == 1)//1이닝때 점수판
	{
		printf("\n┌──────────────────────────────────────────────┐\n");
		printf("│        1회   2회   3회            총점       │\n");
		printf(" 점수     %d                                             \n",score1);
		printf("│                                              │\n");
		printf("└──────────────────────────────────────────────┘\n");
	}
	if (ining == 2)//2이닝때 점수판
	{
		printf("\n┌──────────────────────────────────────────────┐\n");
		printf("│        1회   2회   3회            총점       │\n");
		printf(" 점수     %d    %d                                           \n",score1,score2);
		printf("│                                              │\n");
		printf("└──────────────────────────────────────────────┘\n");
	}
	if (ining == 3)//3이닝때 점수판
	{
		printf("\n┌──────────────────────────────────────────────┐\n");
		printf("│        1회   2회   3회            총점       │\n");
		printf(" 점수       %d    %d     %d                                     \n", score1, score2,score3);
		printf("│                                              │\n");
		printf("└──────────────────────────────────────────────┘\n");
	}
	if (ining == 4)//4이닝은 없고 이닝이 4면 끝난거임
	{
		printf("\n┌──────────────────────────────────────────────┐\n");
		printf("│        1회   2회   3회            총점       │\n");
		printf(" 점수       %d    %d     %d             %d                          \n", score1, score2, score3,total);
		printf("│                                              │\n");
		printf("└──────────────────────────────────────────────┘\n");
	}
	if (ining == 5)//1이닝 끝나고 이길 경우
	{
		printf("\n┌──────────────────────────────────────────────┐\n");
		printf("│        1회   2회   3회            총점       │\n");
		printf(" 점수     %d                          %d                          \n", score1, total);
		printf("│                                              │\n");
		printf("└──────────────────────────────────────────────┘\n");
	}
	if (ining == 6)//2이닝 끝나고 이길 경우
	{
		printf("\n┌──────────────────────────────────────────────┐\n");
		printf("│        1회   2회   3회            총점       │\n");
		printf(" 점수     %d    %d                    %d                          \n", score1, score2, total);
		printf("│                                              │\n");
		printf("└──────────────────────────────────────────────┘\n");
	}
}

void print_count(int ball, int strike, int out)
{
	switch (ball)//볼 표시판
	{
	    case 0:
			printf("B ○○○\n");
			break;
		case 1:
			printf("B ●○○\n");
			break;
		case 2:
			printf("B ●●○\n");
			break;
		case 3:
			printf("B ●●●\n");
			break;
	}
	switch (strike)//스트라이크 표시판
	{
	case 0:
		printf("S ○○\n");
		break;
	case 1:
		printf("S ●○\n");
		break;
	case 2:
		printf("S ●●\n");
		break;
	}
	switch (out)//아웃 표시판
	{
	case 0:
		printf("O ○○\n");
		break;
	case 1:
		printf("O ●○\n");
		break;
	case 2:
		printf("O ●●\n");
		break;
	}
}

void print_base(int base1, int base2, int base3)//각 베이별로 경우의 수가 2개 이므로 2^3 전체 경우의 수는 8
{
	if (base1 == 0 && base2 == 0 && base3 == 0)
	{
		printf("               ◇            \n");
		printf("            ↙   ↖            \n");
		printf("         ↙        ↖           \n");
		printf("       ↙            ↖           \n");
		printf("      ◇               ◇         \n");
		printf("       ↘             ↗         \n");
		printf("         ↘         ↗         \n");
		printf("           ↘    ↗           \n");
		printf("              ◇            \n");
	}
	if (base1 == 1 && base2 == 0 && base3 == 0 )
	{
		printf("               ◇            \n");
		printf("            ↙   ↖            \n");
		printf("         ↙        ↖           \n");
		printf("       ↙            ↖           \n");
		printf("      ◇               ◆         \n");
		printf("       ↘             ↗         \n");
		printf("         ↘         ↗         \n");
		printf("           ↘    ↗           \n");
		printf("              ◇            \n");
	}
	if (base1 == 1 && base2 == 1 && base3 == 0 )
	{
		printf("               ◆            \n");
		printf("            ↙   ↖            \n");
		printf("         ↙        ↖           \n");
		printf("       ↙            ↖           \n");
		printf("      ◇               ◆         \n");
		printf("       ↘             ↗         \n");
		printf("         ↘         ↗         \n");
		printf("           ↘    ↗           \n");
		printf("              ◇            \n");
	}
	if (base1 == 1 && base2 == 1 && base3 == 1)
	{
		printf("               ◆            \n");
		printf("            ↙   ↖            \n");
		printf("         ↙        ↖           \n");
		printf("       ↙            ↖           \n");
		printf("      ◆               ◆         \n");
		printf("       ↘             ↗         \n");
		printf("         ↘         ↗         \n");
		printf("           ↘    ↗           \n");
		printf("              ◇            \n");
	}
	if (base1 == 1 && base2 == 0 && base3 == 1)
	{
		printf("               ◇            \n");
		printf("            ↙   ↖            \n");
		printf("         ↙        ↖           \n");
		printf("       ↙            ↖           \n");
		printf("      ◆               ◆         \n");
		printf("       ↘             ↗         \n");
		printf("         ↘         ↗         \n");
		printf("           ↘    ↗           \n");
		printf("              ◇            \n");
	}
	if (base1 == 0 && base2 == 1 && base3 == 0 )
	{
		printf("               ◆            \n");
		printf("            ↙   ↖            \n");
		printf("         ↙        ↖           \n");
		printf("       ↙            ↖           \n");
		printf("      ◇               ◇         \n");
		printf("       ↘             ↗         \n");
		printf("         ↘         ↗         \n");
		printf("           ↘    ↗           \n");
		printf("              ◇            \n");
	}
	if (base1 == 0 && base2 == 1 && base3 == 1 )
	{
		printf("               ◆            \n");
		printf("            ↙   ↖            \n");
		printf("         ↙        ↖           \n");
		printf("       ↙            ↖           \n");
		printf("      ◆               ◇         \n");
		printf("       ↘             ↗         \n");
		printf("         ↘         ↗         \n");
		printf("           ↘    ↗           \n");
		printf("              ◇            \n");
	}
	if (base1 == 0 && base2 == 0 && base3 == 1 )
	{
		printf("               ◇            \n");
		printf("            ↙   ↖            \n");
		printf("         ↙        ↖           \n");
		printf("       ↙            ↖           \n");
		printf("      ◆               ◇         \n");
		printf("       ↘             ↗         \n");
		printf("         ↘         ↗         \n");
		printf("           ↘    ↗           \n");
		printf("              ◇            \n");
	}
}
