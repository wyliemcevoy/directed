#pragma once

namespace directed
{
	template<class T>
	class AdjacencyListGraph
	{
		// The owner of an edge is the source and the edge specifies a destination
		struct ALEdge {
			int cost;
			T* destination;
		};

	public:
		AdjacencyListGraph();
		~AdjacencyListGraph();

		bool AddNode(const & T data);
		bool AddEdge(const & T source, const & T destination, int value);
		bool RemoveNode(const & T data);
		bool RemoveEdge(const & T source, const & T destination, int value);
		bool ContainsNode(const & T data);
		bool ContainsEdge(const & T source, const & T destination, int value);
		bool ContainsPath(const & T source, const & T destination);


	private:
		std::vector<T> nodes_;
		std::unordered_map<T, vector<ALEdge>> outgoing_edges_;
	};



	template<class T>
	AdjacencyListGraph::AdjacencyListGraph()
	{

	}

	template<class T>
	AdjacencyListGraph::~AdjacencyListGraph()
	{

	}

	template<class T>
	bool AdjacencyListGraph<T>::AddNode(const &T data)
	{
		if (!ContainsEdge(data))
		{
			nodes_.push_back(data);
			return true;
		}
		else {
			// Only supports unique items (need a unique handle to add edges between nodes correctly)
			return false;
		}
	}

	template<class T>
	bool AdjacencyListGraph<T>::AddEdge(const &T source, const &T destination, int value)
	{
		if (ContainsNode(source) && ContainsNode(destination))
		{
			// Does support multiple edges between a source and destination
			outgoing_edges_[source].push_back(ALEdge(destination, value));
			return true;
		}
		else {
			return false;
		}
	}

	template<class T>
	bool AdjacencyListGraph<T>::RemoveNode(const &T data)
	{
		// Find all nodes that have an outgoing edge to this node and remove those edges

		return false;
	}

	template<class T>
	bool AdjacencyListGraph<T>::RemoveEdge(const &T source, const &T destination, int value)
	{

		return false;
	}

	template<class T>
	bool AdjacencyListGraph<T>::ContainsNode(const &T data)
	{


		return false;
	}

	template<class T>
	bool AdjacencyListGraph<T>::ContainsEdge(const &T source, const &T destination, int value)
	{



		return false;
	}

	template<class T>
	bool AdjacencyListGraph<T>::ContainsPath(const &T source, const &T destination)
	{
		return false;
	}



}
