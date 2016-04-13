#pragma once
#include "gtest/gtest.h"
#include "graph.h"

class GraphTest : public ::testing::Test
{
public:
	GraphTest();
	~GraphTest();
	void SetUp();
	void TearDown();

	directed::Graph graph;

};

