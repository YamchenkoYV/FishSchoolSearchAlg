#pragma once
#include <vector>
#include "Fish.h"
#include "OptTask.h"

class FishPopulation
{
public:
	FishPopulation(OptTask& _task, int populationSize, double v_vM, int indCount);
	void swimmingIteration();
	void coltvInstctSwim(std::vector< std::vector <double> >, std::vector<double>&, double, double);
	void coltvVolitionSwim();
	double getCurrentSummWeight();
	double getSummWeight();
	void updateSummWeight(double);
	double getRecord();
	std::vector< double > getCenter(double);
private:
	OptTask& task;
	std::vector<Fish> fPopulation;
	double summWeight;
	//Max value of coltvVolitionSwim coeff (TODO:decrease during the iterations)
	double vol_vMax;
	int indIterCount;
};

