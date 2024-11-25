#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "queue.h"
#include <vector>

using namespace std;

const int MaxComponents = 64;
const int MinComponents = 16;

const int MaxTime = 500;
const int MinTime = 25;

const int MaxPPT = 10;//PPT - Programms Per Tact
const int MinPPT = 1;

struct Programm
{
	int index;
	int tacts_to_finish;
	int necessary_components;
	int appearance_tact;
	Programm(int ind = 0, int tacts = 0, int components = 0, int tact = 0) :index(ind), tacts_to_finish(tacts), necessary_components(components), appearance_tact(tact) {}
};

struct Statistic
{
	int count_of_programms = 0;
	int started_programms = 0;
	int completed_programm = 0;
	double avg_cluster_load = 0;
};

class Cluster
{
	int components;
	double chance;
	int PPT;//programms per tact
public:
	Cluster(int comp, double chanc, int ppt);
	Statistic simulation(int tacts, int t_lim = 25, int c_lim = 5);
};

#endif
