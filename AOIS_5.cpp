#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<bool> next_trigger_signals(vector<bool> constituent, bool v)
{
	int index = constituent.size() - 1;
	while (v && index >= 0)
	{
		if (constituent[index]) {
			constituent[index] = 0;
		}
		else {
			constituent[index] = 1;
			v = false;
		}
		index--;
	}
	return constituent;
}
vector<bool> compare_input_and_output(vector<bool> input_trigger, vector<bool> output_trigger)
{
	vector<bool> output;
	for (int i = 0; i < input_trigger.size(); i++)
	{
		if (input_trigger[i] == output_trigger[i]) {
			output.push_back(0);
		}
		else output.push_back(1);
	}
	return output;
}
void h_triggers_management(vector<bool> constituent, bool v, vector<bool> compare_result, vector<vector<bool>>&h1_sdnf, vector<vector<bool>>&h2_sdnf, vector<vector<bool>>&h3_sdnf)
{
	constituent.push_back(v);
	if (compare_result[0]) h1_sdnf.push_back(constituent);
	if (compare_result[1]) h2_sdnf.push_back(constituent);
	if (compare_result[2]) h3_sdnf.push_back(constituent);
}
void copy_to_truth_table_lines(vector<bool> example, vector<bool>& line_one, vector<bool>& line_two, vector<bool>& line_three)
{
	line_one.push_back(example[0]);
	line_two.push_back(example[1]);
	line_three.push_back(example[2]);
}
void truth_table_auto(vector<bool> h1, vector<bool> h2, vector<bool> h3, vector<bool> q1, vector<bool> q2, vector<bool> q3)
{
	cout << "Truth table : " << endl << "----------------------------------------------------------------------------" << endl
		<< "q*1      : | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |" << endl
		<< "q*2      : | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |" << endl
		<< "q*3      : | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 |" << endl
		<< "v        : | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |" << endl
		<< "----------------------------------------------------------------------------" << endl << "result : |";
	for (int i = 0; i < answerstofunction_one.size(); i++)
	{
		cout << " " << answerstofunction_one[i] << " |";
	}
	cout << endl << "shift  : |";
	for (int i = 0; i < answerstofunction_two.size(); i++)
	{
		cout << " " << answerstofunction_two[i] << " |";
	}
	cout << endl << "------------------------------------------" << endl;

}
void h_sdnf_builder(vector<vector<bool>>& h1_sdnf, vector<vector<bool>>& h2_sdnf, vector<vector<bool>>& h3_sdnf)
{
	vector<bool> h1_line, h2_line, h3_line, q1_line, q2_line, q3_line;
	vector<vector<bool>> data{ {0,0,0}, {0,0,1}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1} };
	for (int i = 0; i < data.size(); i++)
	{
		vector<bool> next_signals = next_trigger_signals(data[i], 0);
		copy_to_truth_table_lines(next_signals, q1_line, q2_line, q3_line);
		vector<bool> compare_h_signals = compare_input_and_output(data[i], next_signals);
		copy_to_truth_table_lines(compare_h_signals, h1_line, h2_line, h3_line);
		h_triggers_management(data[i], 0, compare_h_signals, h1_sdnf, h2_sdnf, h3_sdnf);
		next_signals = next_trigger_signals(data[i], 1);
		copy_to_truth_table_lines(next_signals, q1_line, q2_line, q3_line);
		compare_h_signals = compare_input_and_output(data[i], next_signals);
		copy_to_truth_table_lines(compare_h_signals, h1_line, h2_line, h3_line);
		h_triggers_management(data[i], 1, compare_h_signals, h1_sdnf, h2_sdnf, h3_sdnf);
	}
}

int main()
{
	return 0;
}