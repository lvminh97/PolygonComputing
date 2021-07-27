#include <iostream>
#include <vector>
using namespace std;

#define DEBUG false

struct Point{
    double x, y;

    Point(double _x, double _y): x(_x), y(_y) {}

    Point &operator= (const Point &p){
        x = p.x;
        y = p.y;
        return (*this);
    }

    bool operator== (const Point &p){
        return x == p.x && y == p.y;
    }
};

struct LineSegment{
    Point p, q;
};

vector<Point> points;
vector<vector<LineSegment>> polygons;
Point I;

void readFile();
vector<vector<Point>> findRectangle(Point p);

int main(){
    readFile();
    cout << "Nhap toa do diem I: ";
    cin >> I.x >> I.y;
    return 0;
}

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
#if DEBUG
    for(int i = 0; i < polygons.size(); i++){
        cout << "Polygon " << i + 1 << "\n";
        for(int j = 0; j < polygons[i].size(); j++){
            cout << "\t" << polygons[i][j].p.x << "," << polygons[i][j].p.y << " ==> " << polygons[i][j].q.x << "," << polygons[i][j].q.y << "\n";
        }
    }
#endif
}

vector<vector<Point>> findRectangle(Point p){
    vector<vector<Point>> res;
    vector<Point> rect1, rect2;
    rect1.push_back(Point(p.x - 1, p.y - 3));
    rect1.push_back(Point(p.x - 1, p.y + 3));
    rect1.push_back(Point(p.x + 1, p.y - 3));
    rect1.push_back(Point(p.x + 1, p.y + 3));
    res.push_back(rect1);
    rect2.push_back(Point(p.x - 3, p.y - 1));
    rect2.push_back(Point(p.x - 3, p.y + 1));
    rect2.push_back(Point(p.x + 3, p.y - 1));
    rect2.push_back(Point(p.x + 3, p.y + 1));
    res.push_back(rect2);
    return res;
}