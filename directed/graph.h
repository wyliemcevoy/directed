#pragma once

namespace directed
{
	class Graph
	{
	public:
		Graph();

		virtual bool AddNode(int id) = 0;
		virtual bool AddEdge(int from, int to) = 0;
		virtual bool RemoveNode(int id) = 0;
		virtual bool RemoveEdge(int out, int in) = 0;
		virtual bool ContainsNode(int id) = 0;
		virtual bool ContainsEdge(int out, int in) = 0;
		virtual bool ContainsPath(int from, int to) = 0;

		virtual ~Graph() = 0;
	};

}