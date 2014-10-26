#pragma once

#include "Algorithm.h"
#include "Subject.h"

#include <memory>
#include <vector>
#include <map>
#include <thread>


namespace algorithm
{
	class Subject;


	class Framework : public Subject
	{
		public:
			// add each algorithm that we want to test and the number of samples
			void addAlgorithm(Algorithm* algorithm, std::vector<int> samples);

			// run the framework to correctly time how much each algorithm takes
			void test();

		private:
			std::map<Algorithm*, std::vector<int>> samplesMap;
			std::map<Algorithm*, std::vector<__int64>> durationsMap;
	};
}
