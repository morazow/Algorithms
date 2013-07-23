#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> Point;
#define X first
#define Y second

inline double dist(const Point &P, const Point &Q) {
    return sqrt((P.X - Q.X) * (P.X - Q.X) +
                (P.Y - Q.Y) * (P.Y - Q.Y));
}
Point brute_force(const vector<Point> &);
Point closest_pair(const vector<Point> &);
Point closest_split_pair(const vector<Point> &);

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);

    srand(time(NULL));
    vector<Point> points(N);
    for (int i = 0; i < N; i++)
        points[i].X = rand(),
        points[i].Y = rand();

    sort(points.begin(), points.end());

    for (int i = 0; i < N; i++) printf("(%d, %d) ",points[i].X, points[i].Y);
    printf("\n\n");
    Point res_bt = brute_force(points);
    printf("(%d, %d)\n(%d, %d)\n", points[res_bt.X].X, points[res_bt.X].Y, points[res_bt.Y].X, points[res_bt.Y].Y);

    return 0;
}

Point brute_force(const vector<Point> &P) {
    int fp, fq;
    double d, best = -1;
    for (int i = 0; i < P.size(); i++)
        for (int j = i+1; j < P.size(); j++) {
            d = dist(P[i], P[j]);
            if ( best < 0 || best > d )
                fp = i, fq = j, best = d;
        }

    return make_pair(fp, fq);
}

Point closest_pair(const vector<Point> &P) {
    int N = P.size();
    if (N <= 2) {
        return make_pair(0, N-1);
    }

    int mid = (l + r) >> 1;
    leftPair = closest_pair(l, mid, P);
    rightPair = closest_pair(mid+1, r, P);
    double delta = min(dist(P[leftPair.X], P[leftPair.Y]), dist(P[rightPair.X], P[rightPair.Y]));
    result = closest_split_pair(l, r, delta, P);
}
