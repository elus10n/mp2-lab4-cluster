#include "cluster.h"
#include <iostream>

int randomize(int left, int right)
{
	return left + rand() % (right - left + 1);
}

Cluster::Cluster(int comp, int tacts, double chanc, int ppt)
{
	if ((comp < MinComponents || comp > MaxComponents) || (tacts < MinTime || tacts > MaxTime) || (chanc <= 0 || chanc > 1.0) || (ppt < MinPPT || ppt > MaxPPT))
		throw "invalid cluster arguments!";
	components = comp;
	tacts_to_sim = tacts;
	chance = chanc;
	PPT = ppt;
}

void Cluster::set_components(int comp)
{
	if (comp <= 0 || comp > MaxComponents)
		throw "invalid cluster arguments!";
	components = comp;
}

void Cluster::set_tacts(int tacts)
{
	if (tacts <= 0 || tacts > MaxTime)
		throw "invalid cluster arguments!";
	tacts_to_sim = tacts;
}

void Cluster::set_chance(double chanc)
{
	if(chance <= 0.0 || chance > 1.0)
		throw "invalid cluster arguments!";
	chance = chanc;
}

Statistic Cluster::simulation()
{
	Queue<Programm> main_q{};
	vector<Programm> active;
	int free_components = components;
	int tact_limit = 50;
	int comp_limit = 10;
	Statistic stat;
	double avg = 0;
	int j;
	int k;
	int ind = 0;
	for (int i = 1; i <= tacts_to_sim; i++)//симуляция тактов
	{
		for (j = 0; j < active.size();)//отслеживание выполнения и обновление статуса всех активных программ
		{
			active[j].tacts_to_finish--;
			if (active[j].tacts_to_finish < 1)
			{
				stat.completed_programm++;
				free_components += active[j].necessary_components;
				active.erase(active.begin() + j);
				continue;
			}
			j++;
		}
		for (k = 0; k < PPT; k++)//попробуем создать максимальное количество программ
		{
			if ((double)randomize(0, 100) / 100 <= chance)//возможное появление новой программы
			{
				ind++;
				Programm new_programm(ind,randomize(1, tact_limit), randomize(1, comp_limit), i);
				main_q.push(new_programm);
				stat.count_of_programms++;
			}
		}
		if (!main_q.isEmpty() && (main_q.get_head().necessary_components<=free_components))//возможный старт новой программы
		{
			free_components -= main_q.get_head().necessary_components;
			active.push_back(main_q.pop());
			stat.started_programms++;
		}
		avg += (double)(components - free_components) / components;
	}
	avg = avg / tacts_to_sim;
	stat.avg_cluster_load = avg;
	return stat;
}
