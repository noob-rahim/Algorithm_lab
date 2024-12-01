#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

Point nextToTop(stack<Point>&S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void swap(Point& p1, Point& p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int dis(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r) {
    int val = (q.x - p.x) * (r.y - q.y) - (q.y - p.y) * (r.x - q.x);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

Point p0;
bool compare(const Point& p1, const Point& p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0) {
        return dis(p0, p1) <= dis(p0, p2);
    }
    return o == 1;
}

vector<Point> grahamScan(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};

    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }

    swap(points[0], points[min]);
    p0 = points[0];

    sort(points.begin() + 1, points.end(), compare);

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < n; i++) {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 1) {
            S.pop();
        }
        S.push(points[i]);
    }

    vector<Point> hull;
    while (!S.empty()) {
        hull.push_back(S.top());
        S.pop();
    }

    return hull;
}

vector<Point> readPointsFromFile(const string& filename) {
    vector<Point> points;
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    int x, y;
    while (inputFile >> x >> y) {
        points.push_back({x, y});
    }

    inputFile.close();
    return points;
}

int main() {
    string filename = "Point.txt";

    vector<Point> points = readPointsFromFile(filename);
     auto start1 = chrono::high_resolution_clock::now();

    vector<Point> hull = grahamScan(points);
        auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<float> duration1 = end1 - start1;
    cout << "\nConvex Hull:\n";
    for (const auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    cout<< "Time: " << duration1.count()<< " s" <<endl;
    return 0;
}