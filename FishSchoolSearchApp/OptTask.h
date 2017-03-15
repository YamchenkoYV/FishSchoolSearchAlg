#pragma once

#include <functional>
#include <vector>
#include <string>
class OptTask
{
public:
	typedef typename std::function<double(std::vector<double>)> Func;

	static OptTask& getTask(int, std::string);

	OptTask(int);

	int getDimension();

	void setFunction( std::function<double(std::vector<double>)> );

	void setConstraints(std::vector <double>, std::vector <double>);

	double getValue(std::vector <double>);

	double getMinConstr(int);

	double getMaxConstr(int);

	void setExtr(double);

	bool isInTheSearchArea(std::vector< double >);

private:
	int dimention;
	std::function<double(std::vector<double>)> function;
	std::vector <double> minConstr;
	std::vector <double> maxConstr;
	double extr;
};

