/************************************************************************
 * Raportul unor puncte coliniare (5p)                                  *
 * Se dau patru puncte coliniare.                                       *
 * Sa se determine acele trei puncte                                    *
 *  pentru care valoarea raportului este maxima                         *
 *  (in raport cu toate valorile obtinute pentru cele patru puncte).    *
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
    char name;
    vector<float> coordinates;
};

void readInput(ifstream& inputFile, vector<Point>& points)
{
    // d - dimenisiunea
    // n - numarul de puncte
    // id, in - iteratori pentru d, respectiv n
    int d, n, id, in;
    float tempCoord;
    Point tempPoint;

    inputFile >> d >> n;

    for (in = 0; in < n; ++in)
    {
        tempPoint.coordinates.clear();
        inputFile >> tempPoint.name;

        for (id = 0; id < d; ++id)
        {
            inputFile >> tempCoord;
            tempPoint.coordinates.push_back(tempCoord);
        }
        points.push_back(tempPoint);
    }
}

bool comparator(const Point& p1, const Point& p2)
{
  return p1.coordinates[0] < p2.coordinates[0];
}

void sortPoints(vector<Point>& points)
{
    int i;
    sort(points.begin(), points.end(), &comparator);
}

void printPoints(const vector<Point>& points)
{
    int i, j;

    for (i = 0; i < points.size(); ++i)
    {
        cout << points[i].name << "(";
        for (j = 0; j < points[i].coordinates.size() - 1; ++j)
            cout << points[i].coordinates[j] << ", ";
        cout << points[i].coordinates[j] << ")";
        cout << "\n";
    }
    cout << "\n";
}

float computeRatioOptimized(const Point& M, const Point& N, const Point &P)
{
    float MN, NP, r;
    //MN = N - M; NP = P - N
    MN = N.coordinates[0] - M.coordinates[0];
    NP = P.coordinates[0] - N.coordinates[0];
    r = MN / NP;
    return r;
}

//needed for printing MN = r * NP
//otherwise use optimized version
float computeRatio(const Point& M, const Point& N, const Point& P)
{
    int i;
    float r;
    vector<float> MN, NP;
    for (i = 0; i < M.coordinates.size(); ++i)
        MN.push_back(N.coordinates[i] - M.coordinates[i]);
    for (i = 0; i < M.coordinates.size(); ++i)
        NP.push_back(P.coordinates[i] - N.coordinates[i]);
    r = MN[0] / NP[0];

    //printing
    cout << M.name << N.name <<"(";
    for (i = 0; i < MN.size() - 1; ++i)
        cout << MN[i] << ", ";
    cout << MN[i] << ") = " << r << " * ";
    cout << N.name << P.name << "(";
    for (i = 0; i < NP.size() - 1; ++i)
        cout << NP[i] << ", ";
    cout << NP[i] << ")\n";

    return r;
}

void getMaxRatio(const vector<Point>& points)
{
    float maxRatio = 0;
    float r;
    Point M, N, P;

    for (int i = 0; i < points.size() - 2; ++i)
        for (int j = i + 1; j < points.size() - 1; ++j)
            for (int k = j + 1; k < points.size(); ++k)
            {
                r = computeRatio(points[i], points[j], points[k]);
                if (r > maxRatio)
                {
                    maxRatio = r;
                    M = points[i];
                    N = points[j];
                    P = points[k];
                }
            }

    for (int i = 0; i < points.size() - 2; ++i)
        for (int j = i + 1; j < points.size() - 1; ++j)
            for (int k = j + 1; k < points.size(); ++k)
            {
                r = computeRatio(points[k], points[j], points[i]);
                if (r > maxRatio)
                {
                    maxRatio = r;
                    M = points[k];
                    N = points[j];
                    P = points[i];
                }
            }
    cout << "\nRaportul maxim si punctele pentru care raportul are aceasta valoare: ";
    cout << "r(" << M.name << ", " << N.name << ", " << P.name << ") = " << maxRatio;
}

int main()
{
    vector<Point> points;

    ifstream fin("data.in");

    readInput(fin, points);

    cout << "Configuratia initiala:\n";
    printPoints(points);

    sortPoints(points);

    cout << "Dupa sortarea punctelor:\n";
    printPoints(points);

    getMaxRatio(points);

    return 0;
}
