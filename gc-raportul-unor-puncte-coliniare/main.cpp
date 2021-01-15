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

void printPoints(const vector<Point>& points)
{
    int i, j;
    cout << "Punctele sunt: \n";
    for (i = 0; i < points.size(); ++i) {
        cout << points[i].name << "(";
        for (j = 0; j < points[i].coordinates.size() - 1; ++j)
            cout << points[i].coordinates[j] << ", ";
        cout << points[i].coordinates[j] << ")\n";
    }
}

int main()
{
    vector<Point> points;

    ifstream fin("data.in");
    ofstream fout("data.out");

    readInput(fin, points);
    printPoints(points);

    return 0;
}
