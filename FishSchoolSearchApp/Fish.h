#pragma once
#include <vector>
class Fish
{
public:
	Fish(int _n, double wM, std::vector<double> xVec, double, double vM);
	void moveTo(std::vector<double>, double);
	//double getFuncDiff();
	void feeding();
	std::vector<double> individualSwim();
	double getWeight();
	int getSize();
	std::vector< double > getPos();
	double getFuncValue();
private:
	int n;
	double weight;
	std::vector<double> x;
	double funcValue;
	double old_funcValue;
	//Max weight
	const double wMax;
	//Maximum value of the search step coeff (TODO: decrease vMax during iterations)
	double vMax;
};

