#include "../cluster_sim/cluster.h"
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	cout << "Симуляция кластера." << endl;
	cout << "Введите параметры для кластера ниже" << endl;
	int components;
	cout << "Количество вычислительных узлов (от " << MinComponents << " до " << MaxComponents << "): ";
	cin >> components;
	cout << endl;
	int tacts;
	cout << "Количество тактов симуляции (от " << MinTime << " до " << MaxTime << "): ";
	cin >> tacts;
	cout << endl;
	double chance;
	cout << "Шанс возникновения отдельной задачи на каждом такте (от 0.1  до 1): ";
	cin >> chance;
	cout << endl;
	int PPT;
	cout << "Количество максимально возможных задач на каждом такте (от " << MinPPT << " до " << MaxPPT << "): ";
	cin >> PPT;
	cout << endl;
	int t_lim;
	cout << "Максимальная граница времени выполнения задачи (от " << 1 << " до " << MaxTime << "): ";
	cin >> t_lim;
	cout << endl;
	int c_lim;
	cout << "Максимальное количество вычислительных компонентов, требующихся для выполнения задачи (от " << 1 << " до " << components << "): ";
	cin >> c_lim;
	cout << endl;
	Cluster q(components, chance, PPT);
	Statistic stat = q.simulation(tacts, t_lim, c_lim);
	cout << "Количество программ: " << stat.count_of_programms << endl;
	cout << "Количество запущенных программ: " << stat.started_programms << endl;
	cout << "Количество завершенных программ: " << stat.completed_programm << endl;
	cout << "Средняя загрузка кластера: " << stat.avg_cluster_load*100 <<"%" << endl;
}