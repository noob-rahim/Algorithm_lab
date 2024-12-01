#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};
int findSide(Point p1, Point p2, Point p){
    int val = (p.y - p1.y) * (p2.x - p1.x) - (p2.y -p1.y) * (p.x - p1.x);
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

int distance(Point p1, Point p2, Point p){
    return abs((p.y - p1.y) * (p2.x - p1.x) -(p2.y - p1.y) * (p.x - p1.x));
}

void quickHull(vector<Point> &points, Point p1, Point p2, int side, vector<Point> &hull){
    int ind = -1;
    int max_dist = 0;
    for (int i = 0; i < points.size(); i++){
        int temp = distance(p1, p2, points[i]);
        if (findSide(p1, p2, points[i]) == side && temp > max_dist){
            ind = i;
            max_dist = temp;
        }
    }
    if (ind == -1){
        hull.push_back(p1);
        hull.push_back(p2);
        return;
    }
    quickHull(points, points[ind], p1,
    findSide(p1, points[ind], p2), hull);
    quickHull(points, points[ind], p2,
    findSide(p2, points[ind], p1), hull);
}
vector<Point> ConvexHull(vector<Point> &points){
    if (points.size() < 3){
        return points;
    }
    int min_x = 0, max_x = 0;
    for (int i = 1; i < points.size(); i++){
        if (points[i].x < points[min_x].x)min_x = i;
        else if (points[i].x == points[min_x].x && points[i].y < points[min_x].y)min_x = i;
        if (points[i].x > points[max_x].x) max_x = i;
        else if (points[i].x == points[max_x].x && points[i].y > points[max_x].y)max_x = i;
    }
    Point A = points[min_x];
    Point B = points[max_x];
    vector<Point> hull;
    quickHull(points, A, B, 1, hull);
    quickHull(points, A, B, -1, hull);
    sort(hull.begin(), hull.end(), [](const Point &p1, const Point &p2){ return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x; });
        hull.erase(unique(hull.begin(), hull.end(),[](const Point &p1, const Point &p2){ 
            return p1.x == p2.x && p1.y == p2.y; }),
            hull.end());
        Point centroid = {0, 0};
        for (const auto &p : hull){
            centroid.x += p.x;
            centroid.y += p.y;
        }
    centroid.x /= hull.size();
    centroid.y /= hull.size();
    sort(hull.begin(), hull.end(),[&centroid](const Point &p1, const Point &p2){
    double angle1 = atan2(p1.y - centroid.y, p1.x - centroid.x);
    double angle2 = atan2(p2.y -centroid.y, p2.x - centroid.x);
    return angle1 < angle2; });
    return hull;
}
vector<Point> readPointsFromFile(const string &filename){
    vector<Point> points;
    ifstream inputFile(filename);
    if (!inputFile){
        cerr << "Error: Unable to open file " <<
        filename << endl;
        exit(1);
    }
    int x, y;
    while (inputFile >> x >> y){
        points.push_back({x, y});
    }
    inputFile.close();
    return points;
}
int main(){
    string filename = "points.txt";
    vector<Point> points = readPointsFromFile(filename);
    auto start1 = chrono::high_resolution_clock::now();
    vector<Point> hull =ConvexHull(points);
    auto end1 =chrono::high_resolution_clock::now();
    chrono::duration<float> duration1 = end1- start1;
    cout << "\nConvex Hull:\n";
    for (const auto &p : hull){
        cout << "(" << p.x << ", " << p.y <<"),\n";
    }
    cout<< "Time: " << duration1.count()<< " s"<<endl;
    return 0;
}
