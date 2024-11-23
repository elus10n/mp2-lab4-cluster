#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "queue.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

const int MaxComponents = 64;
const int MinComponents = 16;

const int MaxTime = 500;
const int MinTime = 50;

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
	int tacts_to_sim;
	double chance;
	int PPT;//programms per tact
public:
	Cluster(int comp, int tacts, double chanc, int ppt);
	void set_components(int comp);
	void set_tacts(int tacts);
	void set_chance(double chanc);
	Statistic simulation();
};

#endif
