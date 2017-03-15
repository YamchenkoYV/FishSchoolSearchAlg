#include "DejongOptTask.h"
#include <algorithm>
#include <vector>


DejongOptTask::DejongOptTask(int n) : OptTask(n)
{
	setFunction( [](std::vector<double> x) {
			double summ = 0.0;
			std::for_each(x.begin(), x.end(), [&](double &n) { summ += n * n; });
			return summ;
		}
	);

	std::vector<double> minX(n, -100.0);
	std::vector<double> maxX(n, 100.0);

	setConstraints(minX, maxX);
	setExtr(0);
}
