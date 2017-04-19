// chillitom. 2017

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map<int, int> points;

void add_point(int point, int delta) {
    auto it = points.lower_bound(point);
    if (it != points.end() && it->first == point) {
        it->second += delta;
    } else {
        points.emplace_hint(it, point, delta);
    }
}

int lookup(int p) {
    auto it = points.lower_bound(p);
    if(it != points.end() && it->first > p)
        it--;
    return it == points.end() ? 0 : it->second;
}

int main() {
    ifstream in("extents.txt");
    add_point(-1, 0);
    int a, b;
    while(in >> a >> b) {
        add_point(a, 1);
        add_point(b + 1, -1);
    }

    int n = 0;
    for(auto& i : points) {
        n += i.second;
        i.second = n;
    }

    ifstream numbers("numbers.txt");

    int point;
    while(numbers >> point) {
        cout << lookup(point) << endl;
    }

    return 0;
}

