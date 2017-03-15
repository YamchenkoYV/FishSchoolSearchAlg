#include "Fish.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>


Fish::Fish(int _n, double wM, std::vector<double> xVec, double func, double vM) : n(_n), wMax(wM), x(xVec), vMax(vM)
{
	funcValue = func;
	old_funcValue = func;
	weight = wMax / 2.0;
}

void Fish::moveTo(std::vector<double> newPos, double newFVal)
{
	x = newPos;
	funcValue = newFVal;
}

//double fish::getfuncdiff()
//{
//	return funcvalue - old_funcvalue;
//}

void Fish::feeding() {
	weight += (funcValue - old_funcValue) / std::fmax(funcValue, old_funcValue);
	old_funcValue = funcValue;
}

std::vector<double> Fish::individualSwim() {
	std::srand(std::time(NULL)); // use current time as seed for random generator
	std::vector<double> newX;
	for (int i = 0; i < n; i++)
	{
		double randVal = (std::rand() - (RAND_MAX / 2.0)) / (RAND_MAX / 2.0); // Random value [-1;1]
		newX.push_back(x[i] + randVal * vMax);
	}
	return newX;
}

double Fish::getWeight()
{
	return weight;
}

int Fish::getSize()
{
	return n;
}

std::vector< double > Fish::getPos()
{
	return x;
}

double Fish::getFuncValue()
{
	return funcValue;
}
