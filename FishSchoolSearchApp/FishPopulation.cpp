#include "FishPopulation.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>

FishPopulation::FishPopulation(OptTask& _task, int populationSize, double v_vM, int indCount = 1 ) : task(_task), vol_vMax(v_vM), indIterCount(indCount)
{
	srand(time(NULL));
	int size = _task.getDimension();
	std::vector<double> pos(size, 0);
	//Population initialization
	for (int i = 0; i < populationSize; i++) {
		for (int i = 0; i < size; i++)
			pos[i] = rand() % (int)(_task.getMaxConstr(i) - _task.getMinConstr(i)) + _task.getMinConstr(i);
		Fish fish(size, 100, pos, _task.getValue(pos), (_task.getMaxConstr(i) - _task.getMinConstr(i)) / 2.0);
		fPopulation.push_back(std::move(fish));
	}

}

void FishPopulation::swimmingIteration()
{		
	std::vector<std::vector<double> > v;
	std::vector<double> funcValDiff;

	//Individual part
	for (int i = 0; i < fPopulation.size(); i++) {
		v.push_back( fPopulation[i].getPos() );
		funcValDiff.push_back ( fPopulation[i].getFuncValue() );
		
		std::vector<double> newX;
		double fVal;
		for (int j = 0; j < indIterCount; j++) {
			newX = fPopulation[i].individualSwim();
			fVal = task.getValue(newX);
			if (task.isInTheSearchArea(newX) && ((fVal - fPopulation[i].getFuncValue()) < 0)) {
				fPopulation[i].moveTo(newX, fVal);
			}
		}
		for (int k = 0; k < v.size(); k++)
			v[i][k] = fPopulation[i].getPos()[k] - v[i][k];
		funcValDiff[i] = fPopulation[i].getFuncValue() - funcValDiff[i];
	}

	//Collective-Instinct part
	double summFuncDiff = 0.0;
	for (double d : funcValDiff)
		summFuncDiff += d;
	for (int i = 0; i < fPopulation.size(); i++)
		coltvInstctSwim(v, fPopulation[i].getPos(), funcValDiff[i], summFuncDiff);

	//Collective-volition
	coltvVolitionSwim();

	//Feeding
	for (Fish fish : fPopulation)
		fish.feeding();
}

void FishPopulation::coltvInstctSwim(std::vector< std::vector <double> > vInd, std::vector <double>& curPos, double iFuncDiff, double summFuncDiff)
{
	int n = curPos.size();
	std::vector< double > v(n, 0.0);
	for (auto v : vInd) {
		for (int i = 0; i < n; i++) {
			v[i] += v[i] + iFuncDiff;
		}
	}
	std::for_each(v.begin(), v.end(), [&](double &n) { n /= summFuncDiff; });

	for (int i = 0; i < curPos.size(); i++)
		curPos[i] += v[i];
}


void FishPopulation::coltvVolitionSwim()
{
	double v_Vol = vol_vMax * rand() / RAND_MAX;
	double oldSummWeight = getSummWeight();
	std::srand(std::time(NULL));
	double curSummWeight = getCurrentSummWeight();
	std::vector<double> center = getCenter(curSummWeight);

	for (Fish fish : fPopulation) {
		std::vector<double>& x = fish.getPos();

		if (curSummWeight > oldSummWeight) {
			for (int i = 0; i < x.size(); i++) 
				x[i] += v_Vol * (center[i] - x[i]);
		} else
			for (int i = 0; i < x.size(); i++)
				x[i] -= v_Vol * (center[i] - x[i]);
		}
}

double FishPopulation::getCurrentSummWeight()
{
	double summWeight = 0;
	for (Fish fish : fPopulation)
		summWeight += fish.getWeight();
	return summWeight;
}

double FishPopulation::getSummWeight()
{
	return summWeight;
}

void FishPopulation::updateSummWeight(double weight)
{
	summWeight = weight;
}

double FishPopulation::getRecord()
{
	double record = std::numeric_limits<double>::max();
	for (Fish fish : fPopulation)
	{
		double val = fish.getFuncValue();
		if (val < record)
			record = val;
	}
	return record;
}

std::vector< double > FishPopulation::getCenter(double curSW)
{
	int size = fPopulation[0].getSize();
	std::vector < double > center( size, 0);

	for (Fish fish : fPopulation) {
		double weight = fish.getWeight();
		std::vector<double> x = fish.getPos();
		for (int i = 0; i < size; i++) {
			center[i] += weight * x[i];
		}
	}
	std::for_each(center.begin(), center.end(), [&](double &n) { n /= curSW; });
	return center;
}
