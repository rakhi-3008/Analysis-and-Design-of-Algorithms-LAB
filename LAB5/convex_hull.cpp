#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

vector<Point> hull;

int findSide(Point A, Point B, Point P) {
    int val = (P.y - A.y) * (B.x - A.x) -
              (B.y - A.y) * (P.x - A.x);
    if (val > 0) return 1;  //left
    if (val < 0) return -1; //right
    return 0;   //on
}

int lineDist(Point A, Point B, Point P) {
    return abs((P.y - A.y) * (B.x - A.x) -
               (B.y - A.y) * (P.x - A.x));
}

void quickHull(vector<Point>& points, int n,
               Point A, Point B, int side) {

    int idx = -1;
    int max_dist = 0;

    for (int i = 0; i < n; i++) {
        int temp = lineDist(A, B, points[i]);
        if (findSide(A, B, points[i]) == side && temp > max_dist) {
            idx = i;
            max_dist = temp;
        }
    }

    if (idx == -1) {
        hull.push_back(A);
        hull.push_back(B);
        return;
    }

    quickHull(points, n, points[idx], A,
              -findSide(points[idx], A, B));
    quickHull(points, n, points[idx], B,
              -findSide(points[idx], B, A));
}

void printHull(vector<Point>& points, int n) {
    if (n < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[min_x].x)
            min_x = i;
        if (points[i].x > points[max_x].x)
            max_x = i;
    }

    quickHull(points, n, points[min_x], points[max_x], 1);
    quickHull(points, n, points[min_x], points[max_x], -1);

    cout << "Convex Hull Points:\n";
    for (auto p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";
}

int main() {
    vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1},
        {2, 1}, {3, 0}, {0, 0},
        {3, 3}
    };

    printHull(points, points.size());
    return 0;
}