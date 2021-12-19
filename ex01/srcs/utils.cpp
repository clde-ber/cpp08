#include "utils.hpp"

int randomNumber()
{
    return std::rand()%100;
}

int randomNumberInRange(int min, int max)
{
	return (std::rand() % (max - min + 1)) + min;
}