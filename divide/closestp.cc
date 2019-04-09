#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

bool comp_x(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool comp_y(const Point& a, const Point& b) {
    return a.y < b.y;
}

double distance(const Point& a, const Point& b) {
    double dist_sqr = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    return sqrt(dist_sqr);
}

double center_strip(const vector<Point>& points, int mid, double d) {
    int n = points.size();
    double center = points[mid].x;
    vector<Point> candidates;
    for (int i=0; i<n; ++i) {
        if (abs(points[i].x - center) < d) candidates.push_back(points[i]);
    }
    sort(candidates.begin(), candidates.end(), comp_y);
    int m = candidates.size();
    for (int i=0; i<m; ++i) {
        int j = i+1;
        while (candidates[j].y - candidates[i].y < d and j < m) {
            if (distance(candidates[j], candidates[i]) < d) d = distance(candidates[j], candidates[i]);
            ++j;
        }
    }
    return d;
}

double closest_points(const vector<Point>& points, int l, int r) {
    int n = r-l+1;
    if (n == 2) {
        return distance(points[l], points[l+1]);
    }
    int mid = l + (r-l)/2;
    double min_dist = min(closest_points(points, l, mid), closest_points(points, mid, r));
    double delta_strip = center_strip(points, mid, min_dist);
    if (delta_strip < min_dist) min_dist = delta_strip;
    return min_dist;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(5);
    vector<Point> points;
    double x, y;
    while (cin >> x >> y) {
        Point p = {x, y};
        points.push_back(p);
    }
    sort(points.begin(), points.end(), comp_x);
    cout << closest_points(points, 0, points.size()-1) << endl;
}
