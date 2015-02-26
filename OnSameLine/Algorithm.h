#pragma once

class Node;


namespace algorithm
{
	void ViewPointList(Node* node);
	void RemovePointsFromLines(Node* node);

	bool areOnSameLine(const Node* n1, const Node* n2, const Node* n3);
}
