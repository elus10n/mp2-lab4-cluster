#include "gtest.h"
#include "..\cluster_sim\cluster.h"

TEST(Cluster, can_create_cluster_with_valid_arguments)
{
	ASSERT_NO_THROW(Cluster q(MinComponents, 0.5, MinPPT));
}

TEST(Cluster, throws_exception_when_creating_cluster_with_too_small_count_of_components)
{
	ASSERT_ANY_THROW(Cluster q(MinComponents - 1, 0.5, MinPPT));
}

TEST(Cluster, throws_exception_when_creating_cluster_with_too_big_count_of_components)
{
	ASSERT_ANY_THROW(Cluster q(MaxComponents + 1, 0.5, MinPPT));
}

TEST(Cluster, throws_exception_when_creating_cluster_with_invalid_chance)
{
	ASSERT_ANY_THROW(Cluster q(MinComponents, 1.5, MinPPT));
	ASSERT_ANY_THROW(Cluster q(MinComponents, -1, MinPPT));
}

TEST(Cluster, throws_exception_when_creating_cluster_with_too_small_count_of_Programms_Per_Tact)
{
	ASSERT_ANY_THROW(Cluster q(MinComponents, 0.5, MinPPT - 1));
}

TEST(Cluster, throws_exception_when_creating_cluster_with_too_big_count_of_Programms_Per_Tact)
{
	ASSERT_ANY_THROW(Cluster q(MinComponents, 0.5, MaxPPT + 1));
}

TEST(Cluster, can_simulate_with_valid_arguments)
{
	Cluster q(MinComponents, 0.5, MinPPT);
	ASSERT_NO_THROW(q.simulation(MinTime, 10, 5));
}

TEST(Cluster, can_not_simulate_with_too_small_simulation_time)
{
	Cluster q(MinComponents, 0.5, MinPPT);
	ASSERT_ANY_THROW(q.simulation(MinTime-1, 10, 5));
}

TEST(Cluster, can_not_simulate_with_too_big_simulation_time)
{
	Cluster q(MinComponents, 0.5, MinPPT);
	ASSERT_ANY_THROW(q.simulation(MaxTime + 1, 10, 5));
}

TEST(Cluster, can_not_simulate_with_zero_limit_of_time_for_programm)
{
	Cluster q(MinComponents, 0.5, MinPPT);
	ASSERT_ANY_THROW(q.simulation(MinTime, 0, 5));
}

TEST(Cluster, can_not_simulate_with_negative_limit_of_time_for_programm)
{
	Cluster q(MinComponents, 0.5, MinPPT);
	ASSERT_ANY_THROW(q.simulation(MinTime, -1, 5));
}

TEST(Cluster, can_not_simulate_with_too_big_limit_of_time_for_programm)
{
	Cluster q(MinComponents, 0.5, MinPPT);
	ASSERT_ANY_THROW(q.simulation(MinTime, MaxTime + 1, 5));
}

TEST(Cluster, can_not_simulate_with_zero_limit_of_components)
{
	Cluster q(MinComponents, 0.5, MinPPT);
	ASSERT_ANY_THROW(q.simulation(MinTime, 5, 0));
}

TEST(Cluster, can_not_simulate_with_negative_limit_of_components)
{
	Cluster q(MinComponents, 0.5, MinPPT);
	ASSERT_ANY_THROW(q.simulation(MinTime, 5, -1));
}

TEST(Cluster, can_not_simulate_with_too_big_limit_of_components)
{
	Cluster q(MinComponents, 0.5, MinPPT);
	ASSERT_ANY_THROW(q.simulation(MinTime, 5, MinComponents+1));//Cluster создан с MinComponents вычислительными узлами
}

TEST(Cluster, can_return_statistic)
{
	Cluster q(MaxComponents, 1, MinPPT);
	double avg = 1.0 / (double)MaxComponents;
	Statistic s1 = {1*MinTime, 1*MinTime, 1*MinTime - 1, avg };

	Statistic s2 = q.simulation(MinTime, 1, 1);

	EXPECT_EQ(s1.avg_cluster_load, s2.avg_cluster_load);
}

//TEST(Cluster, )
//{
//
//}
//
//TEST(Cluster, )
//{
//
//}
//
//TEST(Cluster, )
//{
//
//}
//
//TEST(Cluster, )
//{
//
//}
//
//TEST(Cluster, )
//{
//
//}
//
//TEST(Cluster, )
//{
//
//}
//
//TEST(Cluster, )
//{
//
//}
//
//TEST(Cluster, )
//{
//
//}
//
//TEST(Cluster, )
//{
//
//}
//
//TEST(Cluster, )
//{
//
//}