#include "OptTask.h"
#include "DejongOptTask.h"


OptTask& OptTask::getTask(int dim, std::string fName)
{
	if (fName.compare("DejongOptTask") == 0) {
		DejongOptTask* newTask = new DejongOptTask(dim);
		return *newTask;
	}
}

OptTask::OptTask(int n) : dimention(n)
{
}

int OptTask::getDimension()
{
	return dimention;
}

void OptTask::setFunction(std::function<double(std::vector<double>)> f)
{
	function = f;
}

void OptTask::setConstraints(std::vector <double> minC, std::vector <double> maxC)
{
	minConstr = minC;
	maxConstr = maxC;
}

double OptTask::getValue(std::vector <double> x)
{
	return function(x);
}

double OptTask::getMinConstr(int i)
{
	return minConstr[i];
}

double OptTask::getMaxConstr(int i)
{
	return maxConstr[i];
}

void OptTask::setExtr(double e)
{
	extr = e;
}

bool OptTask::isInTheSearchArea(std::vector< double > x)
{
	for (int i = 0; i < x.size(); i++) {
		if (x[i] < minConstr[i] || x[i] > maxConstr[i])
			return false;
	}
	return true;
}
