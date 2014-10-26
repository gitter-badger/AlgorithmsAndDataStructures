#pragma once


enum class AlgorithmType
{
	// union find algorithms
	QuickFind,
	QuickUnion,
	WeightedQuickUnion,
	WeightedQuickUnionPathCompression,

	// searching algorithms
	BinarySearch,
	LinearSearch,

	// sorting algorithms
	InsertionSort,
	BubbleSort,
	SelectionSort
};