// chillitom. 2017

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map<int, int> points {{0, 0}};

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
    return it == points.end() ? 0 : (it->first > p ? it-- : it)->second;    
}

int main() {
    int x, y, n = 0, point;

    ifstream in("extents.txt");      
    while(in >> x >> y) {
        add_point(x, 1);
        add_point(y + 1, -1);
    }

    for(auto& i : points) {
        n += i.second;
        i.second = n;
    }

    ifstream numbers("numbers.txt");
    while(numbers >> point) {
        cout << lookup(point) << endl;
    }

    return 0;
}

