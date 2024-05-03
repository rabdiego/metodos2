#include "libs/methodic/include/Log.hpp"

using namespace Methodic;

Log::Log(double returnValue, int numItter, int numPartitions) {
    this->returnValue = returnValue;
    this->numItter = numItter;
    this->numPartitions = numPartitions;
}
