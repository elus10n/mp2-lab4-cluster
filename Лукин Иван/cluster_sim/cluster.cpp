#include "cluster.h"

int randomize(int left, int right)
{
	return left + rand() % (right - left + 1);
}

Cluster::Cluster(int comp, double chanc, int ppt)
{
	if ((comp < MinComponents || comp > MaxComponents) || (chanc <= 0 || chanc > 1.0) || (ppt < MinPPT || ppt > MaxPPT))
		throw "invalid cluster arguments!";
	components = comp;
	chance = chanc;
	PPT = ppt;
}

Statistic Cluster::simulation(int tacts,int t_lim,int c_lim)
{
	if (tacts < MinTime || tacts > MaxTime || t_lim < 1 || t_lim > MaxTime || c_lim < 1 || c_lim > components)
		throw "invalid cluster arguments!";
	Queue<Programm> main_q{};
	vector<Programm> active;
	int free_components = components;
	int tact_limit = t_lim;
	int comp_limit = c_lim;
	Statistic stat;
	double avg = 0;
	int j;
	int k;
	int ind = 0;
	for (int i = 1; i <= tacts; i++)//симуляция тактов
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
		while (!main_q.isEmpty() && (main_q.get_head().necessary_components<=free_components))//возможный старт новой программы или программ
		{
			free_components -= main_q.get_head().necessary_components;
			active.push_back(main_q.pop());
			stat.started_programms++;
		}
		avg += (double)(components - free_components) / components;
	}
	avg = avg / tacts;
	stat.avg_cluster_load = avg;
	return stat;
}
