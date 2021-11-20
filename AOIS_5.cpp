#include "AOIS_5.h"

void SDNF_vector_bool_output(vector<vector<bool>> sdnfprototype)
{
	if (sdnfprototype.size() == 0) return;
	for (int i = 0; i < sdnfprototype.size(); i++)
	{
		cout << "(";
		for (int j = 0; j < sdnfprototype[i].size(); j++)
		{
			if (j == 0) {
				if (sdnfprototype[i][j] == 1) cout << "a";
				else cout << "!a";
			}
			if (j == 1) {
				if (sdnfprototype[i][j] == 1) cout << "b";
				else cout << "!b";
			}
			if (j == 2) {
				if (sdnfprototype[i][j] == 1) cout << "c";
				else cout << "!c";
			}
			if (j == 3) {
				if (sdnfprototype[i][j] == 1) cout << "d";
				else cout << "!d";
			}
			if (j == 4) {
				if (sdnfprototype[i][j] == 1) cout << "e";
				else cout << "!e";
			}
			if (j != sdnfprototype[i].size() - 1) cout << "*";
		}
		cout << ")";
		if (i != sdnfprototype.size() - 1) cout << "+";
	}
	cout << endl;
}
string SDNF_vector_pair_output(vector<vector<pair<int, bool>>> sdnfprotatype)
{
	string output;
	for (int i = 0; i < sdnfprotatype.size(); i++)
	{
		output += '(';
		for (int j = 0; j < sdnfprotatype[i].size(); j++)
		{
			if (sdnfprotatype[i][j].first == 0) {
				if (sdnfprotatype[i][j].second == 0) output += "!a";
				else output += 'a';
			}
			else if (sdnfprotatype[i][j].first == 1)
			{
				if (sdnfprotatype[i][j].second == 0) output += "!b";
				else output += 'b';
			}
			else if (sdnfprotatype[i][j].first == 2)
			{
				if (sdnfprotatype[i][j].second == 0) output += "!c";
				else output += 'c';
			}
			else if (sdnfprotatype[i][j].first == 3)
			{
				if (sdnfprotatype[i][j].second == 0) output += "!d";
				else output += 'd';
			}
			else if (sdnfprotatype[i][j].first == 4)
			{
				if (sdnfprotatype[i][j].second == 0) output += "!e";
				else output += 'e';
			}
			if (j != sdnfprotatype[i].size() - 1) output += '*';
		}
		output += ')';
		if (i != sdnfprotatype.size() - 1) output += '+';
	}
	return output;
}
void truth_table(vector<vector<bool>> q_set, vector<vector<bool>> h_set)
{
	cout << "Truth table : " << endl << "----------------------------------------------------------------------------" << endl
		<< "q*1      : | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |" << endl
		<< "q*2      : | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |" << endl
		<< "q*3      : | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 |" << endl
		<< "v        : | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |" << endl
		<< "----------------------------------------------------------------------------" << endl;
	for (int i = 0; i < q_set.size(); i++)
	{
		cout << "q" << i + 1 << "       : |";
		for (int j = 0; j < q_set[i].size(); j++)
		{
			cout << " " << q_set[i][j] << " |";
		}
		cout << endl;
	}
	cout << "----------------------------------------------------------------------------" << endl;
	for (int i = 0; i < h_set.size(); i++)
	{
		cout << "h" << i + 1 << "       : |";
		for (int j = 0; j < h_set[i].size(); j++)
		{
			cout << " " << h_set[i][j] << " |";
		}
		cout << endl;
	}
	cout << "----------------------------------------------------------------------------" << endl;

}

vector<pair<int, bool>> from_constituent_to_pair(vector<bool>& constituent)
{
	vector<pair<int, bool>> result;
	for (int i = 0; i < constituent.size(); i++)
	{
		pair<int, bool> example(i, constituent[i]);
		result.push_back(example);
	}
	return result;
}
vector<vector<pair<int, bool>>> from_set_of_constituents_to_implicants(vector<vector<bool>>& sdnfprotatype)
{
	vector<vector<pair<int, bool>>> result;
	for (int i = 0; i < sdnfprotatype.size(); i++)
	{
		result.push_back(from_constituent_to_pair(sdnfprotatype[i]));
	}
	return result;
}

bool checker_for_coincidence(vector<pair<int, bool>>& term_one, vector<pair<int, bool>>& term_two, int size)
{
	if (!(term_one.size() == size && term_two.size() == size)) return false;
	int counter_of_coincidence = 0, neccesary_coincidence = term_one.size() - 1;
	for (int i = 0; i < term_one.size(); i++)
	{
		bool overlap = false;
		for (int j = 0; j < term_two.size(); j++)
		{
			if (term_one[i].first == term_two[j].first) {
				overlap = true;
				if (term_one[i].second == term_two[i].second) counter_of_coincidence++;
				break;
			}
		}
		if (!overlap) return false;
	}
	if (counter_of_coincidence == neccesary_coincidence) return true;
	return false;
}
vector<pair<int, bool>> implicant(vector<pair<int, bool>>& term_one, vector<pair<int, bool>>& term_two)
{
	vector<pair<int, bool>> result;
	for (int i = 0; i < term_one.size(); i++)
	{
		for (int j = 0; j < term_two.size(); j++)
		{
			if (term_one[i].first == term_two[j].first && term_one[i].second == term_two[j].second)
			{
				pair<int, bool> example(term_one[i].first, term_one[i].second);
				result.push_back(example);
				break;
			}
		}
	}
	return result;
}
void gluing(vector<vector<pair<int, bool>>>& current_sdnf, int size)
{
	map<vector<pair<int, bool>>, bool> repeat;
	vector<vector<pair<int, bool>>> output;
	for (int i = 0; i < current_sdnf.size(); i++)
	{
		bool overlap = false;
		for (int j = 0; j < current_sdnf.size(); j++)
		{
			if (i == j) continue;
			if (checker_for_coincidence(current_sdnf[i], current_sdnf[j], size)) {
				overlap = true;
				vector<pair<int, bool>> implicant_ex = implicant(current_sdnf[i], current_sdnf[j]);
				if (!repeat[implicant_ex]) {
					repeat[implicant_ex] = true;
					output.push_back(implicant_ex);
				}
			}
		}
		if (!overlap) {
			output.push_back(current_sdnf[i]);
		}
	}
	current_sdnf = output;
}

bool checker_for_implicant_and_constituent(vector<bool>& constituent, vector<pair<int, bool>>& implicant)
{
	int counter = 0;
	for (int i = 0; i < implicant.size(); i++)
	{
		if (implicant[i].second == constituent[implicant[i].first]) counter++;
	}
	if (counter == implicant.size()) return true;
	else return false;
}
pair<vector<vector<bool>>, vector<int>> table_of_crosses(vector<vector<bool>>& sdnfprototype, vector<vector<pair<int, bool>>>& implicants)
{
	vector<vector<bool>> result;
	vector<int> future_result_of_operation;
	for (int i = 0; i < sdnfprototype.size(); i++)
	{
		vector<bool> line_for_constituent;
		int summary_for_the_line = 0, unique_implicant;
		for (int j = 0; j < implicants.size(); j++)
		{
			bool result_for_comparison = checker_for_implicant_and_constituent(sdnfprototype[i], implicants[j]);
			if (result_for_comparison) unique_implicant = j;
			line_for_constituent.push_back(result_for_comparison);
			summary_for_the_line += result_for_comparison;
		}
		if (summary_for_the_line == 1) future_result_of_operation.push_back(unique_implicant);
		else result.push_back(line_for_constituent);
	}
	pair<vector<vector<bool>>, vector<int>> future_result_and_table(result, future_result_of_operation);
	return future_result_and_table;
}
void one_line_deleting(vector<vector<bool>>& table, int line, int& current_amount_of_cleaning_crosses)
{
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i][line]) {
			current_amount_of_cleaning_crosses++;
			table[i][line] = 0;
		}
	}
}
bool table_checker(vector<vector<bool>> table)
{
	for (int i = 0; i < table.size(); i++)
	{
		bool zero_sign = false;
		for (int j = 0; j < table[i].size(); j++)
		{
			if (table[i][j]) {
				zero_sign = true;
				break;
			}
		}
		if (!zero_sign) {
			return false;
		}
	}
	return true;
}
void creator_for_set_of_exceptions(map<int, bool>visited, vector<vector<bool>> table, int number_of_cleaning_line, vector<int>& main_line_for_result, vector<int>current_line_for_result, int& main_amount_of_crosses, int current_amount_of_crosses)
{
	one_line_deleting(table, number_of_cleaning_line, current_amount_of_crosses);
	if (table_checker(table)) {
		visited[number_of_cleaning_line] = true;
		current_line_for_result.push_back(number_of_cleaning_line);
		if ((main_line_for_result.size() < current_line_for_result.size()) && (main_amount_of_crosses < current_amount_of_crosses)) {
			main_line_for_result = current_line_for_result;
			main_amount_of_crosses = current_amount_of_crosses;
		}
		for (int i = 0; i < table[0].size(); i++)
		{
			if (!visited[i]) creator_for_set_of_exceptions(visited, table, i, main_line_for_result, current_line_for_result, main_amount_of_crosses, current_amount_of_crosses);
		}
	}
	else return;
}
vector<int> set_of_exceptions(vector<vector<bool>> table, int number_of_start_implicant, map<int, bool> visited)
{
	vector<int>main_line, current_line;
	int current_amount_of_cleanning_crosses = 0, main_amount_of_cleanning_crosses = 0;
	creator_for_set_of_exceptions(visited, table, number_of_start_implicant, main_line, current_line, main_amount_of_cleanning_crosses, current_amount_of_cleanning_crosses);
	return main_line;
}
vector<int> result_exeption(vector<vector<bool>> table, vector<int> numbers_of_correct_implicants)
{
	vector<int> result;
	map<int, bool> visited;
	for (int i = 0; i < numbers_of_correct_implicants.size(); i++)
	{
		visited[numbers_of_correct_implicants[i]] = true;
	}
	if (table.size() != 0) {
		for (int i = 0; i < table[0].size(); i++)
		{
			if (!visited[i]) {
				vector<int> current_result = set_of_exceptions(table, i, visited);
				if (current_result.size() > result.size()) result = current_result;
			}
		}
	}
	return result;
}
void exceptioned_implicants(vector<vector<pair<int, bool>>>& implicants, vector<int> exception)
{
	vector<vector<pair<int, bool>>> result_implicants;
	for (int i = 0; i < implicants.size(); i++)
	{
		bool sign = true;
		for (int j = 0; j < exception.size(); j++)
		{
			if (i == exception[j]) sign = false;
		}
		if (sign) result_implicants.push_back(implicants[i]);
	}
	implicants = result_implicants;
}
vector<vector<pair<int, bool>>> minimization(vector<vector<bool>>& sdnfprotatype)
{
	vector<vector<pair<int, bool>>> result_implicants = from_set_of_constituents_to_implicants(sdnfprotatype);
	if (result_implicants.size() == 0) return result_implicants;
	int size = sdnfprotatype[0].size();
	while (size > 1)
	{
		gluing(result_implicants, size);
		size--;
	}
	pair<vector<vector<bool>>, vector<int>> table_and_one_cross_implicants_sdnf = table_of_crosses(sdnfprotatype, result_implicants);
	vector<int> exception_sdnf = result_exeption(table_and_one_cross_implicants_sdnf.first, table_and_one_cross_implicants_sdnf.second);
	exceptioned_implicants(result_implicants, exception_sdnf);
	return result_implicants;
}

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
void copy_to_truth_table_lines(vector<bool>& example, vector<vector<bool>>& storage)
{
	for (int i = 0; i < example.size(); i++)
	{
		storage[i].push_back(example[i]);
	}
}
pair<vector<vector<bool>>, vector<vector<bool>>> lines_of_triggers(vector<vector<bool>>& data)
{
	vector<vector<bool>> q_next_signals_line, h_trigger_signals_line;
	q_next_signals_line.resize(data[0].size());
	h_trigger_signals_line.resize(data[0].size());
	for (int i = 0; i < data.size(); i++)
	{
		vector<bool> next_signals = next_trigger_signals(data[i], false);
		copy_to_truth_table_lines(next_signals, q_next_signals_line);
		vector<bool> compare_h_signals = compare_input_and_output(data[i], next_signals);
		copy_to_truth_table_lines(compare_h_signals, h_trigger_signals_line);
		next_signals = next_trigger_signals(data[i], true);
		copy_to_truth_table_lines(next_signals, q_next_signals_line);
		compare_h_signals = compare_input_and_output(data[i], next_signals);
		copy_to_truth_table_lines(compare_h_signals, h_trigger_signals_line);
	}
	pair<vector<vector<bool>>, vector<vector<bool>>> output(q_next_signals_line, h_trigger_signals_line);
	return output;
}
vector<bool> summary_for_final_constituent(vector<bool> term, bool v)
{
	term.push_back(v);
	return term;
}
vector<vector<bool>> from_line_to_sdnf(vector<bool>& h_trigers_line, vector<vector<bool>>& data)
{
	int number_of_situation = 0;
	vector<vector<bool>> h_sdnf;
	for (int i = 0; i < data.size(); i++)
	{
		if (h_trigers_line[number_of_situation] == 1) {
			h_sdnf.push_back(summary_for_final_constituent(data[i], false));
		}
		if (h_trigers_line[++number_of_situation] == 1) {
			h_sdnf.push_back(summary_for_final_constituent(data[i], true));
		}
		number_of_situation++;
	}
	return h_sdnf;
}

void task()
{
	vector<vector<bool>> data{ {0,0,0}, {0,0,1}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1} };
	pair<vector<vector<bool>>, vector<vector<bool>>> q_next_and_h_triggers = lines_of_triggers(data);
	truth_table(q_next_and_h_triggers.first, q_next_and_h_triggers.second);
	vector<vector<vector<bool>>> functions_to_be_minimized;
	for (int i = 0; i < q_next_and_h_triggers.second.size(); i++)
	{
		vector<vector<bool>> example = from_line_to_sdnf(q_next_and_h_triggers.second[i], data);
		functions_to_be_minimized.push_back(example);
	}
	cout << "q1* -> a :: q2* -> b :: q3* -> c :: v -> d" << endl << endl;
	for (int i = 0; i < functions_to_be_minimized.size(); i++)
	{
		cout << "h" << i + 1 << "(SDNF) = ";
		SDNF_vector_bool_output(functions_to_be_minimized[i]);
	}
	vector<vector<vector<pair<int, bool>>>> minimized_functions;
	for (int i = 0; i < functions_to_be_minimized.size(); i++)
	{
		minimized_functions.push_back(minimization(functions_to_be_minimized[i]));
	}
	cout << endl;
	for (int i = 0; i < minimized_functions.size(); i++)
	{
		cout << "Minimized h" << i + 1 << "(SDNF) = " << SDNF_vector_pair_output(minimized_functions[i]) << endl;
	}
}

bool Test1()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0}, {0,0,1,0}, {0,1,0,0}, {0,1,1,0}, {1,0,0,0}, {1,0,1,0}, {1,1,0,0}, {1,1,1,0} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!d)";
	if (our_result == real_result)
	{
		cout << "Test1 correct!" << endl;
		return true;
	}
	else cout << "Test1 incorrect!" << endl;
	return false;
}
bool Test2()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,1}, {0,0,1,1}, {0,1,0,1}, {0,1,1,1}, {1,0,0,1}, {1,0,1,1}, {1,1,0,1}, {1,1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(d)";
	if (our_result == real_result)
	{
		cout << "Test2 correct!" << endl;
		return true;
	}
	else cout << "Test2 incorrect!" << endl;
	return false;
}
bool Test3()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0}, {0,0,0,1}, {0,0,1,0}, {0,0,1,1}, {0,1,0,0}, {1,0,1,1}, {1,1,0,0}, {1,1,0,1}, {1,1,1,0}, {1,1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!a*!b)+(b*!c*!d)+(a*c*d)+(a*b)";
	if (our_result == real_result)
	{
		cout << "Test3 correct!" << endl;
		return true;
	}
	else cout << "Test3 incorrect!" << endl;
	return false;
}
bool Test4()
{
	vector<vector<bool>> sdnfprotatype{ {0,1,0,0}, {0,1,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,0,0}, {1,0,0,1}, {1,0,1,0}, {1,0,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!a*b)+(a*!b)";
	if (our_result == real_result)
	{
		cout << "Test4 correct!" << endl;
		return true;
	}
	else cout << "Test4 incorrect!" << endl;
	return false;
}
bool Test5()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0}, {0,1,0,0}, {1,1,0,1}, {1,0,0,1}, {0,0,1,1}, {0,1,1,1}, {1,1,1,0}, {1,0,1,0} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!a*!c*!d)+(a*!c*d)+(!a*c*d)+(a*c*!d)";
	if (our_result == real_result)
	{
		cout << "Test5 correct!" << endl;
		return true;
	}
	else cout << "Test5 incorrect!" << endl;
	return false;
}
bool Test6()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0}, {1,0,0,0}, {0,1,0,1}, {1,1,0,1}, {0,1,1,1}, {1,1,1,1}, {0,0,1,0}, {1,0,1,0} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!b*!d)+(b*d)";
	if (our_result == real_result)
	{
		cout << "Test6 correct!" << endl;
		return true;
	}
	else cout << "Test6 incorrect!" << endl;
	return false;
}
bool Test7()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0,0}, {0,0,1,0,0}, {0,1,0,1,1}, {0,1,0,1,0}, {0,1,1,1,0}, {0,1,1,1,1}, {1,1,0,1,1}, {1,1,0,1,0}, {1,1,1,1,0}, {1,1,1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!a*!b*!d*!e)+(b*d)";
	if (our_result == real_result)
	{
		cout << "Test7 correct!" << endl;
		return true;
	}
	else cout << "Test7 incorrect!" << endl;
	return false;
}
bool Test8()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0,0}, {0,0,1,0,0}, {0,1,0,1,1}, {0,1,0,1,0}, {0,1,1,1,0}, {0,1,1,1,1}, {1,1,0,1,1}, {1,1,0,1,0}, {1,1,1,1,0}, {1,1,1,1,1}, {0,0,0,1,1}, {0,0,0,1,0}, {0,0,1,1,0}, {0,0,1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!a*!b*!e)+(b*d)+(!a*d)";
	if (our_result == real_result)
	{
		cout << "Test8 correct!" << endl;
		return true;
	}
	else cout << "Test8 incorrect!" << endl;
	return false;
}
bool Test9()
{
	vector<vector<bool>> sdnfprotatype{ {0,1,0,0,0}, {0,1,0,0,1}, {1,1,0,0,0}, {1,1,0,0,1}, {0,1,1,0,1}, {0,1,1,0,0}, {1,1,1,0,1}, {1,1,1,0,0} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(b*!d)";
	if (our_result == real_result)
	{
		cout << "Test9 correct!" << endl;
		return true;
	}
	else cout << "Test9 incorrect!" << endl;
	return false;
}
bool Test10()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,1,1}, {0,0,0,1,0}, {0,0,1,1,0}, {0,0,1,1,1}, {1,0,0,1,1}, {1,0,0,1,0}, {1,0,1,1,0}, {1,0,1,1,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!b*d)";
	if (our_result == real_result)
	{
		cout << "Test10 correct!" << endl;
		return true;
	}
	else cout << "Test10 incorrect!" << endl;
	return false;
}
bool Test11()
{
	vector<vector<bool>> sdnfprotatype{ {0,0,0,0,0}, {0,0,0,0,1}, {0,0,1,0,1}, {0,0,1,0,0}, {1,0,0,0,0}, {1,0,0,0,1}, {1,0,1,0,0}, {1,0,1,0,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(!b*!d)";
	if (our_result == real_result)
	{
		cout << "Test11 correct!" << endl;
		return true;
	}
	else cout << "Test11 incorrect!" << endl;
	return false;
}
bool Test12()
{
	vector<vector<bool>> sdnfprotatype{ {0,1,0,0,1}, {0,1,0,1,1}, {1,1,0,0,1}, {1,1,0,1,1}, {0,1,1,1,1}, {0,1,1,0,1}, {1,1,1,1,1}, {1,1,1,0,1} };
	vector<vector<pair<int, bool>>> minimization_result = minimization(sdnfprotatype);
	string our_result = SDNF_vector_pair_output(minimization_result);
	string real_result = "(b*e)";
	if (our_result == real_result)
	{
		cout << "Test12 correct!" << endl;
		return true;
	}
	else cout << "Test12 incorrect!" << endl;
	return false;
}
void tests()
{
	int counter_of_positives = 0;
	counter_of_positives += Test1();
	counter_of_positives += Test2();
	counter_of_positives += Test3();
	counter_of_positives += Test4();
	counter_of_positives += Test5();
	counter_of_positives += Test6();
	counter_of_positives += Test7();
	counter_of_positives += Test8();
	counter_of_positives += Test9();
	counter_of_positives += Test10();
	counter_of_positives += Test11();
	counter_of_positives += Test12();
	if (counter_of_positives == 12) {
		cout << "All tests passed correctly!!" << endl;
	}
}
