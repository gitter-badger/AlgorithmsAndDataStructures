#include "Framework.h"

#include <chrono>
#include <iostream>

namespace algorithm
{

	//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
	void Framework::addAlgorithm(Algorithm* algorithm, std::vector<int> samples)
	{
		samplesMap.emplace(algorithm, samples);
	}

	//__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
	void Framework::test()
	{
		int nrAlgorithms = samplesMap.size();

		int algorithmIndex = 0;
		for(auto& kv : samplesMap)
		{
			auto algorithm = kv.first;
			auto samples   = kv.second;

			std::cout << std::endl << "[" << algorithmIndex + 1 << "/" << nrAlgorithms <<"] " << algorithm->getName();

			int sampleIndex = 0;
			int nrSamples   = samples.size();
			for(auto sample : samples)
			{
				std::cout << std::endl << "\t[" << sampleIndex + 1 << "/" << nrSamples <<"] N = " << sample << ".......";
				algorithm->init(sample);

				auto start = std::chrono::system_clock::now();

				algorithm->run();

				auto elapsed  = std::chrono::system_clock::now() - start;
				auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
				std::cout << duration << " ms";

				samplesMap[algorithm].push_back(duration);
			}

			algorithmIndex++;
		}
	}

} // namespace algorithm
