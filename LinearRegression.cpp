#include "LinearRegression.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

LinearRegression::LinearRegression(NDArray weights, double learningRate, int setLength, NDArray X, NDArray Y)
{
	_weights = weights;
	_learningRate = learningRate;
	_setLength = setLength;
	_startData = X;
	_targetData = Y;
}

LinearRegression::~LinearRegression()
{
}

NDArray	LinearRegression::getModelPrediction(const NDArray & startData, const NDArray & weights)
{
	assert(startData[0].size() == weights[0].size());
	NDArray prediction;
	for (size_t i = 0; i < startData.size(); ++i) {
		double dot_product = 0.0;
		for (size_t j = 0; j < startData[0].size(); ++j) {
			dot_product += startData[i][j] * weights[0][j];
		}
		prediction.push_back({dot_product});
	}
	return prediction;
}

double	dotProduct(std::vector<double> diff, NDArray mp, int desiredWeight, int N)
{
	double ret = 0.0;
	for (int i = 0; i < N; ++i)
		ret += diff[i] * mp[i][desiredWeight];
	return (ret);
}

double LinearRegression::getDerivative(const NDArray& modelPrediction, \
	const NDArray& groundTruth, int N, const NDArray& startData, int desiredWeight)
{
	std::vector<double>	diff(N);
	for (size_t i = 0; i < modelPrediction.size(); ++i)
		diff[i] = groundTruth[0][i] - modelPrediction[i][0];
	double derivative = -2.0 * (dotProduct(diff, startData, desiredWeight, N) / N);
	return derivative;
}

double	LinearRegression::getError(const NDArray & modelPrediction, const NDArray & groundTruth)
{
	double sum = 0.0;
	for (size_t i = 0 ; i < modelPrediction.size() ; ++i)
	{
		double	diff = modelPrediction[i][0] - groundTruth[0][i];
		sum += diff * diff;
	}
	sum /= groundTruth[0].size();
	std::cout << "sum " << sum << std::endl;
	return (std::round((sum * 100000.0) / 100000.0));
}

void	LinearRegression::updateWeights(double *d)
{
	for (size_t i = 0; i < _weights[0].size(); ++i)
	{
    	_weights[0][i] -= d[i] * this->getLearningRate();
	}
}

double	LinearRegression::getLearningRate()
{
	return (_learningRate);
}

void	LinearRegression::getWeights()
{
	NDArray newWeights(_weights);
    for (size_t i = 0; i < _weights[0].size(); ++i)
		newWeights[0][i] = std::round(_weights[0][i] * 100000.0) / 100000.0;
	std::cout << "Final weights are:" << std::endl;
    for (size_t i = 0; i < newWeights[0].size(); ++i)
		std::cout << "W" << i+1 << " " << newWeights[0][i] << " | ";
	std::cout << std::endl;
}

void	showParams(NDArray w, double lr, int numIter)
{
	std::cout << "Linear regression" << std::endl;
	std::cout << "running " << numIter << " times" << std::endl;
	std::cout << "Initial weights are:";
	for (size_t i = 0 ; i < 3 ; ++i)
		std::cout << " W" << i << " " << w[0][i];
	std::cout << std::endl;
	std::cout << "Learning rate is " << lr << std::endl;
}

void	LinearRegression::trainModel(int numIterations)
{
	//assert(_startData.size() == _targetData.size());
//	assert( _startData[0].size() == _targetData[0].size());
//	assert( _startData[0].size() == _weights[0].size());

	double d[3];
	showParams(_weights, _learningRate, numIterations);
    for (int iter = 0; iter < numIterations; ++iter)
	{
            NDArray modelPrediction = getModelPrediction(_startData, _weights);
            for (size_t i = 0; i < _weights[0].size(); ++i)
                d[i] = getDerivative(modelPrediction, _targetData, _startData.size(), _startData, i);
			updateWeights(d);
	}
	getWeights();

}
