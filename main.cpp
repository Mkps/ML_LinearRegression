#include "LinearRegression.hpp"

int	main()
{
	NDArray X = {{1.0, 2.0, 3.0}, {1.0, 1.0, 1.0}};
	NDArray Y = {{6.0, 3.0}};
	NDArray initialWeights = {{0.2, 0.1, 0.6}};
	LinearRegression l(initialWeights, 0.001, X.size(), X, Y);
	l.trainModel(4000000);
	return (0);
}
