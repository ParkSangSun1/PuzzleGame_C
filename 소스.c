//3X3 퍼즐 게임
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define LEFT    75
#define RIGHT   77
#define UP      72
#define DOWN    80

int getkey()//방향키를 입력받는 함수
{
    int key;
    key = _getch();
    if (key == 224)//방향키
    {
        return _getch(); //어떤 방향 키인지 반환
    }
    return 0;    //방향키가 아님
}
void interface(int puzzle[4][4])
{
    int row, col;
    system("cls"); //콘솔 화면을 지우기
    for (row = 0; row < 4; row++)//열 반복
    {
        for (col = 0; col < 4; col++)//행 반복
        {
            if (puzzle[row][col])//참이면(0이 아니면)
            {
                printf("%3d", puzzle[row][col]);//퍼즐의 수를 출력
            }
            else//거짓(0)이면
            {
                printf("   ");//공백 출력
            }

        }
        printf("\n");//개행
    }
}
int end(int puzzle[4][4])
{
    int row, col;

    for (row = 0; row < 4; row++)//열 반복
    {
        for (col = 0; col < 4; col++)//행 반복
        {
            if (puzzle[row][col] != row * 4 + col + 1)
            {
                return (row == 2) && (col == 2);
            }
        }
    }
    return 0;
}
int main()
{
    int num;
    int row;
    while (1) {
        printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("■저희의 프로젝트 게임은 상슨아 숫자배열 맞춰!! 입니다.       ■\n");
        printf("■                                                            ■\n");
        printf("■숫자'1'을 눌러 게임의 크기를 선택해주세요                   ■\n");
        printf("■                                                            ■\n");
        printf("■1이 아닌 숫자를 입력할시 즉시 초기화 됩니다.                ■\n");
        printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
        printf("▶▶");
        scanf_s("%d", &num);
        Sleep(3000);

        if (num == 1) {
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            printf("■ @ X @ 3~5중 @에 들어갈 숫자를 선택해주세요                 ■\n");
            printf("■                                                            ■\n");
            printf("■                                                            ■\n");
            printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
            printf("▶▶");
            scanf_s("%d", &row);
            if (3 <= row && 5 >= row) {
                printf("■□□□■□□□■□■■■■■□■□□□□□□■■■■■□□□■■■■■□□□□□■□□□■□□□■■■■■\n");
                printf("■□□□■□□□■□■□□□□□■□□□□□■■□□□□□□■□□□□□■□□□□■□□□■□□□■□□□□\n");
                printf("□■□■□■□■□□■■■■■□■□□□□□■□□□□□□□■□□□□□■□□□■□■□■□■□□■■■■■\n");
                printf("□□■□□□■□□□■□□□□□■□□□□□■■□□□□□□■□□□□□■□□■□□□■□□□■□■□□□□\n");
                printf("□□■□□□■□□□■■■■■□■■■■■□□■■■■■□□□■■■■■□□□■□□□■□□□■□■■■■■\n");
                Sleep(5432);
                break;
            }
            else {
                system("cls");
            }
        }
        else {
            system("cls");
        }
    }

    int puzzle[4][4] = { {1,3,2,12}, {15,4,10,13}, {9,8,14,7}, {11,5,6,0} };
    row = 3;
    int col = 3;
    int key = 0;

    while (!end(puzzle))
    {
        interface(puzzle);
        printf(">> 방향키 선택 \n");
        key = getkey();

        switch (key)
        {
        case RIGHT:
            if (col > 0)
            {
                puzzle[row][col] = puzzle[row][col - 1];
                puzzle[row][col - 1] = 0;
                col--;
            }

            break;
        case LEFT:
            if (col < 4 - 1)
            {
                puzzle[row][col] = puzzle[row][col + 1];
                puzzle[row][col + 1] = 0;
                col++;
            }
            break;
        case UP:
            if (row < 4 - 1)
            {
                puzzle[row][col] = puzzle[row + 1][col];
                puzzle[row + 1][col] = 0;
                row++;
            }
            break;
        case DOWN:
            if (row > 0)
            {
                puzzle[row][col] = puzzle[row - 1][col];
                puzzle[row - 1][col] = 0;
                row--;
            }
            break;
        }
    }
    return 0;
}
