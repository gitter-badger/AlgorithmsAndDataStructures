#pragma once

#include "Algorithm.h"


namespace algorithm
{
	class Observer
	{
		public:
			virtual void onAlgorithmFinished(Algorithm* algorithm, int nrSamples, __int64 time) = 0;
			virtual void onAlgorithmStarted(Algorithm* algorithm) = 0;
	};
}