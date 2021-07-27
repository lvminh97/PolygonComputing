#include <iostream>
#include <vector>
using namespace std;

#define DEBUG false

struct Point{
    double x, y;

    Point &operator= (const Point &p){
        x = p.x;
        y = p.y;
        return (*this);
    }
};

struct LineSegment{
    Point p, q;
};

vector<Point> points;
vector<vector<LineSegment>> polygons;

void readFile(){
    freopen("input.txt", "r", stdin);
    int N, M;
    cin >> N;
    for(int t = 0; t < N; t++){
        cin >> M;
        // init memory for polygon
        vector<LineSegment> polygon;
        for(int i = 0; i < M; i++){
            LineSegment newLS;
            polygon.push_back(newLS);
        }
        // input M points of polygon
        int prevId = 0;
        for(int i = 0; i < M; i++){
            Point newP;
            cin >> newP.x >> newP.y;
            points.push_back(newP);
            if(i == 0) prevId = M - 1;
            else prevId = i - 1;
            polygon[prevId].q = newP;
            polygon[i].p = newP;
        }
        polygons.push_back(polygon);
    }
}

int main(){
    readFile();
#if DEBUG
    for(int i = 0; i < polygons.size(); i++){
        cout << "Polygon " << i + 1 << "\n";
        for(int j = 0; j < polygons[i].size(); j++){
            cout << "\t" << polygons[i][j].p.x << "," << polygons[i][j].p.y << " ==> " << polygons[i][j].q.x << "," << polygons[i][j].q.y << "\n";
        }
    }
#endif
    return 0;
}