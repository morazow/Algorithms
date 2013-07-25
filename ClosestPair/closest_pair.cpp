#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

typedef pair<int, int> Point;
// two point indeces and distance between them
typedef pair<pair<int, int>, double> PPdist;
#define X first
#define Y second

#define EPS 1e-9
#define INF 10e12

inline double dist(const Point &P, const Point &Q) {
    return sqrt((P.X - Q.X) * (P.X - Q.X) +
                (P.Y - Q.Y) * (P.Y - Q.Y));
}
PPdist brute_force(int, int, const vector<Point> &);
PPdist closest_pair(int, int, const vector<Point> &);

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);

    srand(time(NULL));
    vector<Point> points(N);
    for (int i = 0; i < N; i++)
        points[i].X = rand() % 10000, // coordinate plane of
        points[i].Y = rand() % 10000; // 10k x 10k

    // sort coordinates first by x axis then by y axis
    sort(points.begin(), points.end());

    clock_t bf_time = clock();
    PPdist bf_result = brute_force(0, N, points);
    bf_time = clock() - bf_time;

    clock_t cl_time = clock();
    PPdist cl_result = closest_pair(0, N, points);
    cl_time = clock() - cl_time;

    assert(cl_result.second - bf_result.second < EPS);

    fprintf(stderr, "%d %.2f %.2f\n", N, 1000*(double)(bf_time) / CLOCKS_PER_SEC, 1000*(double)(cl_time) / CLOCKS_PER_SEC);

    return 0;
}

PPdist brute_force(int l, int r, const vector<Point> &P) {
    int fp, fq;
    double d, best = -1;
    for (int i = l; i < r; i++)
        for (int j = i+1; j < r; j++) {
            d = dist(P[i], P[j]);
            if ( best < 0 || best > d )
                fp = i, fq = j, best = d;
        }

    return make_pair(make_pair(fp, fq), best);
}

PPdist closest_split_pair(int l, int r, int mid_x, double delta, const vector<Point> &P) {
    double bestDist = delta;
    Point bestPair;

    for (int i = l; i < r; i++) {
        if (abs(P[i].X - mid_x) > delta)
            continue;
        for (int j = 1; j <= 7 && i + j < r; j++) {
            double d = dist(P[i], P[i+j]);
            if ( d < bestDist )
                bestDist = d,
                bestPair = make_pair(i, i+j);
        }
    }

    return make_pair(bestPair, bestDist);
}

PPdist closest_pair(int l, int r, const vector<Point> &P) {
    if (r - l <= 1)
        return make_pair(make_pair(l, l), INF);

    int mid = (l + r) >> 1;

    // find closest pair in left half
    PPdist leftPair = closest_pair(l, mid, P);

    // find closest pair in right half
    PPdist rightPair = closest_pair(mid, r, P);

    // find cl pair in split
    double bestDist = min(leftPair.second, rightPair.second);
    PPdist combPair = closest_split_pair(l, r, P[mid-1].X, bestDist, P);

    // select best of three
    bestDist = leftPair.second;
    PPdist bestPair = leftPair;
    if (bestDist > rightPair.second)
        bestDist = rightPair.second, bestPair = rightPair;
    if (bestDist > combPair.second)
        bestDist = combPair.second, bestPair = combPair;

    return bestPair;
}
