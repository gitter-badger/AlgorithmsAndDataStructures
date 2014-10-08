#pragma once

class IUninonFind
{
	public:
		// Initializes the data structure with correct data for the algorithm
		virtual void Initialize(int n) = 0;

		// Returns true if p is connected to q. Not necessarily direct connection
		virtual bool Connected(int p, int q) = 0;

		// Merges 2 adjacent sets
		virtual void Union(int p, int q) = 0;

		// Returns the number of connected components
		virtual int Components() = 0;

		// If p and q are not connected, we perform a union
		// Returns true if the pair was added
		virtual bool addPair(int p, int q) = 0;
};