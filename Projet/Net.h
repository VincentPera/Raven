#pragma once
#include "Neuron.h"
#include <vector>
#include "main.h"
using namespace std;


class Net
{
public:
	Net(const vector<unsigned> &topology);
	void FeedForward(const vector<double> &inputVals);
	void BackProp(const vector<double> &targetVals);
	void GetResult(vector<double> &resultVals) const;
	~Net();

	double getError();

	void							SetWeights(vector<vector<vector<double>>> weights);
	vector<vector<vector<double>>>	GetWeights();
	double							GetNetInputNumber();

	void SetEta(double newEta);
	void SetAlpha(double newAlpha);
private:
	vector<Layer> m_Layers; // m_layers[layersNum][neuronNum]
	double m_error = 1.0;
	double m_recentAverageError;
	double m_recentAverageSmoothingFactor;
};

