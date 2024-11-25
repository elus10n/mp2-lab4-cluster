#include "../cluster_sim/cluster.h"
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	cout << "��������� ��������." << endl;
	cout << "������� ��������� ��� �������� ����" << endl;
	int components;
	cout << "���������� �������������� ����� (�� " << MinComponents << " �� " << MaxComponents << "): ";
	cin >> components;
	cout << endl;
	int tacts;
	cout << "���������� ������ ��������� (�� " << MinTime << " �� " << MaxTime << "): ";
	cin >> tacts;
	cout << endl;
	double chance;
	cout << "���� ������������� ��������� ������ �� ������ ����� (�� 0.1  �� 1): ";
	cin >> chance;
	cout << endl;
	int PPT;
	cout << "���������� ����������� ��������� ����� �� ������ ����� (�� " << MinPPT << " �� " << MaxPPT << "): ";
	cin >> PPT;
	cout << endl;
	int t_lim;
	cout << "������������ ������� ������� ���������� ������ (�� " << 1 << " �� " << MaxTime << "): ";
	cin >> t_lim;
	cout << endl;
	int c_lim;
	cout << "������������ ���������� �������������� �����������, ����������� ��� ���������� ������ (�� " << 1 << " �� " << components << "): ";
	cin >> c_lim;
	cout << endl;
	Cluster q(components, chance, PPT);
	Statistic stat = q.simulation(tacts, t_lim, c_lim);
	cout << "���������� ��������: " << stat.count_of_programms << endl;
	cout << "���������� ���������� ��������: " << stat.started_programms << endl;
	cout << "���������� ����������� ��������: " << stat.completed_programm << endl;
	cout << "������� �������� ��������: " << stat.avg_cluster_load*100 <<"%" << endl;
}