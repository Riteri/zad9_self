#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n , m , k;
    cin >> n >> m >> k;
    string tablica_sejf[n];
    int tablica_pomocnicza[2][n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> tablica_sejf[i];
        tablica_pomocnicza[1][i][m%2] = n-i-1;
    }
    int ostatni_x = n;
    int ostatni_o = 0;
    for (int j = m - 1; j > -1; j--)
    {
        int ilosc_o = 0;
        int ilosc_x = 0;
        for (int i = 0; i < ostatni_x; i++)
        {
            if (tablica_sejf[tablica_pomocnicza[1][i][(j+1)%2]][j] == 'X')
            {
                tablica_pomocnicza[1][ilosc_x][j%2]=tablica_pomocnicza[1][i][(j+1)%2];
                ilosc_x++;
            }else
            {
                tablica_pomocnicza[0][ilosc_o][j%2]=tablica_pomocnicza[1][i][(j+1)%2];
                ilosc_o++;
            }
        }
        for (int i = 0; i < ostatni_o; i++)
        {
            if (tablica_sejf[tablica_pomocnicza[0][i][(j+1)%2]][j] == 'X')
            {
                tablica_pomocnicza[1][ilosc_x][j%2]=tablica_pomocnicza[0][i][(j+1)%2];
                ilosc_x++;
            }else
            {
                tablica_pomocnicza[0][ilosc_o][j%2]=tablica_pomocnicza[0][i][(j+1)%2];
                ilosc_o++;
            }
        }
        ostatni_x = ilosc_x;
        ostatni_o = ilosc_o;
    }
    for (int i = 0; i < min(k , ostatni_x); i++)
    {
        cout << tablica_sejf[tablica_pomocnicza[1][i][0]];
        cout<< "\n";
    }
    k-=ostatni_x;
    if (k > 0)
    {
        for (int i = 0; i < min(k , ostatni_o); i++)
        {
            cout << tablica_sejf[tablica_pomocnicza[0][i][0]];
            cout<< "\n";
        }
    }
    return 0;
}