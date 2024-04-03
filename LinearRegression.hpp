#ifndef LINEARREGRESSION_HPP
# define LINEARREGRESSION_HPP

#include <vector>

using NDArray = std::vector<std::vector<double>>;

class LinearRegression {

public:
	LinearRegression(NDArray weights, double learningRate, int setLength, NDArray X, NDArray Y);
	~LinearRegression();
	NDArray	getModelPrediction(const NDArray & startData, const NDArray & weights);
	double	getDerivative(const NDArray& modelPrediction, const NDArray& groundTruth, int N, const NDArray& startData, int desiredWeight);
	double	getError(const NDArray & modelPrediction, const NDArray & groundTruth);
	void	updateWeights(double *d);
	double	getLearningRate();
	void	getWeights();
	void	trainModel(int numIterations);
private:
	NDArray	_weights;
	double	_learningRate;
	int		_setLength;
	NDArray	_startData;
	NDArray _targetData;

};
#endif
 
