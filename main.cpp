#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

#define DEBUG false

struct Point{
    double x, y;

    Point(double _x = 0, double _y = 0): x(_x), y(_y) {}

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

    LineSegment() {}
    LineSegment(Point _p, Point _q): p(_p), q(_q) {}

    int direction(){
        if(p.x == q.x)  // parallel to Oy - vertical
            return 0;
        else            // parallel to Ox - horizontal
            return 1;
    }

    double lenghth(){
        if(direction() == 0)
            return fabs(p.y - q.y);
        else  
            return fabs(p.x - q.x);
    }

    bool contain(Point t){
        return LineSegment(p, t).lenghth() + LineSegment(q, t).lenghth() == this->lenghth();
    }

    friend ostream &operator << (ostream &out, const LineSegment &line){
        return out << line.p.x << "," << line.p.y << " => " << line.q.x << "," << line.q.y;
    }
};

int N, M;
vector<Point> points;
vector<vector<LineSegment>> polygons;
Point I;

void readFile();
vector<LineSegment> getRectangle(Point p);

int main(){
    readFile();
    cout << "Nhap toa do diem I: ";
    cin >> I.x >> I.y;

    Point A, B, C, D;
    A.x = I.x - 1; A.y = I.y + 3;
    B.x = I.x + 1; B.y = I.y + 3;
    C.x = I.x + 1; C.y = I.y - 3;
    D.x = I.x - 1; D.y = I.y - 3;

    for(int i = 0; i < N; i++){ // Check with each polygon
        for(int j = 0; j < polygons[i].size(); j++){ // Check with each line segment of polygon
            int prevId;
            if(j > 0) prevId = j - 1;
            else prevId = polygons[i].size() - 1;
            if(polygons[i][j].direction() == 0){    // horizontal
                if(polygons[i][j].contain(B) && polygons[i][j].contain(C)){
                    if((int)LineSegment(polygons[i][j].p, B).lenghth() % 6 == 0){
                        if()
                    }
                }
                else if(polygons[i][j].contain(A) && polygons[i][j].contain(D)){

                }
            }
            else{   // vertical
                if(polygons[i][j].contain(A) && polygons[i][j].contain(B)){

                }
                else if(polygons[i][j].contain(C) && polygons[i][j].contain(D)){

                }
            }
        }
    }
    return 0;
}

void readFile(){
    ifstream inputFile;
    inputFile.open("input.txt");
    if(!inputFile){
        cout << "Can not read data from input file!\n";
        return;
    }
    inputFile >> N;
    for(int t = 0; t < N; t++){
        inputFile >> M;
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
            inputFile >> newP.x >> newP.y;
            points.push_back(newP);
            if(i == 0) prevId = M - 1;
            else prevId = i - 1;
            polygon[prevId].q = newP;
            polygon[i].p = newP;
        }
        polygons.push_back(polygon);
    }
    inputFile.close();
#if DEBUG
    for(int i = 0; i < polygons.size(); i++){
        cout << "Polygon " << i + 1 << "\n";
        for(int j = 0; j < polygons[i].size(); j++){
            cout << "\t" << polygons[i][j].p.x << "," << polygons[i][j].p.y << " ==> " << polygons[i][j].q.x << "," << polygons[i][j].q.y << "\n";
        }
    }
#endif
}