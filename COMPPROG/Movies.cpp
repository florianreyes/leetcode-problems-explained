#include <iostream>
#include <vector>

using namespace std;

struct Movie
{
    int start;
    int end;
};

int MovieCounts()
{
    int n;
    cin >> n;

    vector<Movie> movies(n);
    for (int i = 0; i < n; i++)
    {
        cin >> movies[i].start >> movies[i].end;
    }

    sort(movies.begin(), movies.end(), [](Movie a, Movie b)
         { return a.end < b.end; });

    int mc = 0; // Contador de movies
    int lt = 0; // Ultimo tiempo de fin de peli

    for (int i = 0; i < n; i++)
    {
        if (movies[i].start >= lt)
        {
            mc++;
            lt = movies[i].end;
        }
    }

    return mc;
}

int main()
{
    cout << MovieCounts() << endl;
    return 0;
}