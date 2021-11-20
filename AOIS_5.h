#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void SDNF_vector_bool_output(vector<vector<bool>> sdnfprototype);
string SDNF_vector_pair_output(vector<vector<pair<int, bool>>> sdnfprotatype);
void truth_table(vector<vector<bool>> q_set, vector<vector<bool>> h_set);

vector<pair<int, bool>> from_constituent_to_pair(vector<bool>& constituent);
vector<vector<pair<int, bool>>> from_set_of_constituents_to_implicants(vector<vector<bool>>& sdnfprotatype);
void exceptioned_implicants(vector<vector<pair<int, bool>>>& implicants, vector<int> exception);
bool checker_for_coincidence(vector<pair<int, bool>>& term_one, vector<pair<int, bool>>& term_two, int size);
vector<pair<int, bool>> implicant(vector<pair<int, bool>>& term_one, vector<pair<int, bool>>& term_two);
void gluing(vector<vector<pair<int, bool>>>& current_sdnf, int size);

bool checker_for_implicant_and_constituent(vector<bool>& constituent, vector<pair<int, bool>>& implicant);
pair<vector<vector<bool>>, vector<int>> table_of_crosses(vector<vector<bool>>& sdnfprototype, vector<vector<pair<int, bool>>>& implicants);
void one_line_deleting(vector<vector<bool>>& table, int line, int& current_amount_of_cleaning_crosses);
bool table_checker(vector<vector<bool>> table);
void creator_for_set_of_exceptions(map<int, bool>visited, vector<vector<bool>> table, int number_of_cleaning_line, vector<int>& main_line_for_result, vector<int>current_line_for_result, int& main_amount_of_crosses, int current_amount_of_crosses);
vector<int> set_of_exceptions(vector<vector<bool>> table, int number_of_start_implicant, map<int, bool> visited);
vector<int> result_exeption(vector<vector<bool>> table, vector<int> numbers_of_correct_implicants);
void exceptioned_implicants(vector<vector<pair<int, bool>>>& implicants, vector<int> exception);
vector<vector<pair<int, bool>>> minimization(vector<vector<bool>>& sdnfprotatype);

vector<bool> next_trigger_signals(vector<bool> constituent, bool v);
vector<bool> compare_input_and_output(vector<bool> input_trigger, vector<bool> output_trigger);
void copy_to_truth_table_lines(vector<bool>& example, vector<vector<bool>>& storage);
pair<vector<vector<bool>>, vector<vector<bool>>> lines_of_triggers(vector<vector<bool>>& data);
vector<bool> summary_for_final_constituent(vector<bool> term, bool v);
vector<vector<bool>> from_line_to_sdnf(vector<bool>& h_trigers_line, vector<vector<bool>>& data);

void task();

bool Test1();
bool Test2();
bool Test3();
bool Test4();
bool Test5();
bool Test6();
bool Test7();
bool Test8();
bool Test9();
bool Test10();
bool Test11();
bool Test12();
void tests();
