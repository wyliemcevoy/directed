#pragma once
#include "gtest/gtest.h"
#include "pointer_graph.h"

class GraphTest : public ::testing::Test
{
public:
	GraphTest();
	~GraphTest();
	void SetUp();
	void TearDown();

	directed::PointerGraph graph;

};

