#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <list>

using namespace std;

int cycle = 1;
const int tab_size = 15;
int tab[tab_size][tab_size];
int next_tab[tab_size][tab_size];
void set_tab_as_zero(int (&tab)[tab_size][tab_size], int size);
void display_tab(int (&tab)[tab_size][tab_size], int size);
void init_ones(int (&tab)[tab_size][tab_size], int size);
void set_tab_as_next(int (&tab)[tab_size][tab_size], int (&next_tab)[tab_size][tab_size], int size);
void set_next_tab(int (&tab)[tab_size][tab_size], int (&next_tab)[tab_size][tab_size]);
int main()
{
    set_tab_as_zero(tab, tab_size);
    set_tab_as_zero(next_tab, tab_size);
    init_ones(tab, tab_size);
    display_tab(tab, tab_size);
    for (int i = 0; i < 10; i++)
    {
        set_next_tab(tab, next_tab);
        set_tab_as_next(tab, next_tab, tab_size);
        set_tab_as_zero(next_tab, tab_size);
        display_tab(tab, tab_size);
    }
};
void set_tab_as_zero(int (&tab)[tab_size][tab_size], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            *(*(tab + i) + j) = 0;
        }
    }
}
void display_tab(int (&tab)[tab_size][tab_size], int size)
{
    cout << "Cykl: " << cycle << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // cout << *(*(tab + i) + j) << " ";
            if (tab[i][j] == 1)
            {
                cout << "X"
                     << " ";
            }
            else
            {
                cout << "-"
                     << " ";
            }
        }
        cout << endl;
    }
    cycle++;
}
void init_ones(int (&tab)[tab_size][tab_size], int size)
{

    // Blinker
    // tab[5][5] = 1;
    // tab[5][6] = 1;
    // tab[5][7] = 1;

    // żabka
    tab[3][5] = 1;
    tab[4][5] = 1;
    tab[5][5] = 1;
    tab[4][6] = 1;
    tab[5][6] = 1;
    tab[6][6] = 1;

    // Staw
    // tab[4][4] = 1;
    // tab[5][4] = 1;
    // tab[6][5] = 1;
    // tab[6][6] = 1;
    // tab[5][7] = 1;
    // tab[4][7] = 1;
    // tab[3][5] = 1;
    // tab[3][6] = 1;
}
void set_tab_as_next(int (&tab)[tab_size][tab_size], int (&next_tab)[tab_size][tab_size], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            tab[i][j] = next_tab[i][j];
        }
    }
}
void set_next_tab(int (&tab)[tab_size][tab_size], int (&next_tab)[tab_size][tab_size])
{
    int sum = 0;
    int left_top = 0;
    int left = 0;
    int left_bottom = 0;
    int bottom = 0;
    int right_bottom = 0;
    int right = 0;
    int right_top = 0;
    int top = 0;
    for (int i = 1; i < tab_size - 1; i++)
    {
        for (int j = 1; j < tab_size - 1; j++)
        {
            left_top = tab[i - 1][j - 1];
            left = tab[i][j - 1];
            left_bottom = tab[i + 1][j - 1];
            bottom = tab[i + 1][j];
            right_bottom = tab[i + 1][j + 1];
            right = tab[i][j + 1];
            right_top = tab[i - 1][j + 1];
            top = tab[i - 1][j];
            sum = left_top + left + left_bottom + bottom + right_bottom + right + right_top + top;
            if (tab[i][j] == 0 && sum == 3)
            {
                next_tab[i][j] = 1;
            }
            else if (tab[i][j] == 1 && (sum == 3 || sum == 2))
            {
                next_tab[i][j] = 1;
            }
            else
            {
                next_tab[i][j] = 0;
            }
        }
    }
}
