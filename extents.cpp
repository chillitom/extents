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

int main() {
	ifstream in("extents.txt");

	int a, b;
	while(in >> a >> b) {
		add_point(a, 1);
		add_point(b, -1);
	}

	int open = 0;
	for(auto& i : points) {
		open += i.second;
		i.second = open;
	}

	ifstream numbers("numbers.txt");

	int point;
	while(numbers >> point) {
		cout << points.lower_bound(point)->second + 1 << endl;
	}

	return 0;
}

