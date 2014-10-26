#pragma once

#include <vector>

namespace algorithm
{
	class Algorithm;
	class Observer;


	class Subject
	{
		public:
			void registerListener(Observer* listener);

		protected:
			void notifyListenersAlgorithmFinished(Algorithm* algorithm, int nrSamples, __int64 time);
			void notifyListenersAlgorithmStarted(Algorithm* algorithm);

			std::vector<Observer*> listeners;
	};
}
