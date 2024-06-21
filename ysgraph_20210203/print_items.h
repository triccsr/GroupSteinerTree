#pragma once

// vector

void print_vector_int(std::vector<int>& input_vector) {

	std::cout << "print_vector_int:" << std::endl;
	for (int i = 0; i < input_vector.size(); i++) {
		std::cout << "item: |" << input_vector[i] << "|" << std::endl;
	}

}


void print_vector_double(std::vector<double>& input_vector) {

	std::cout << "print_vector_double:" << std::endl;
	for (int i = 0; i < input_vector.size(); i++) {
		std::cout << "item: |" << input_vector[i] << "|" << std::endl;
	}

}


void print_vector_string(std::vector<std::string>& input_vector) {

	std::cout << "print_vector_string (at most 3e2):" << std::endl;
	std::cout << "size(): " << input_vector.size() << std::endl;
	for (int i = 0; i < input_vector.size() && i < 3e2; i++) {
		std::cout << "item: |" << input_vector[i] << "|" << std::endl;
	}

}









// list 

void print_list_int(std::list<int>& input_list) {

	std::cout << "print_list_int:" << std::endl;
	for (auto i = input_list.begin(); i != input_list.end(); i++) {
		std::cout << "item: |" << *i << "|" << std::endl;
	}
	std::cout << "print_list_int END" << std::endl;
}











// unordered_set

#include <unordered_set>

void print_unordered_set_int(std::unordered_set<int>& input_set) {

	std::cout << "print_unordered_set_int:" << std::endl;
	std::cout << "size(): " << input_set.size() << std::endl;
	for (auto i = input_set.begin(); i != input_set.end(); i++) {
		std::cout << "item: |" << *i << "|" << std::endl;
	}
	std::cout << "print_unordered_set_int END" << std::endl;

}


void print_unordered_set_string(std::unordered_set<std::string>& input_set) {

	std::cout << "print_unordered_set_string:" << std::endl;
	std::cout << "size(): " << input_set.size() << std::endl;
	for (auto i = input_set.begin(); i != input_set.end(); i++) {
		std::cout << "item: |" << *i << "|" << std::endl;
	}
	std::cout << "print_unordered_set_string END" << std::endl;

}








// unordered_map

#include <unordered_map>

void print_unordered_map_string_int(std::unordered_map<std::string, int>& input_map) {

	std::cout << "print_unordered_map_string_int:" << std::endl;
	std::cout << "size(): " << input_map.size() << std::endl;
	for (auto i = input_map.begin(); i != input_map.end(); i++) {
		std::cout << "key: |" << i->first << "|" << " content: |" << i->second << "|" << '\n';
	}
	std::cout << "print_unordered_set_int END" << std::endl;
}


void print_unordered_map_int_string(std::unordered_map<int, std::string>& input_map) {

	std::cout << "print_unordered_map_int_string:" << std::endl;
	std::cout << "size(): " << input_map.size() << std::endl;
	for (auto i = input_map.begin(); i != input_map.end(); i++) {
		std::cout << "key: |" << i->first << "|" << " content: |" << i->second << "|" << '\n';
	}
	std::cout << "print_unordered_map_int_string END" << std::endl;
}

void print_unordered_map_int_int(std::unordered_map<int, int>& input_map) {

	std::cout << "print_unordered_map_int_int:" << std::endl;
	std::cout << "size(): " << input_map.size() << std::endl;
	for (auto i = input_map.begin(); i != input_map.end(); i++) {
		std::cout << "key: |" << i->first << "|" << " content: |" << i->second << "|" << '\n';
	}
	std::cout << "print_unordered_map_int_int END" << std::endl;
}


void print_unordered_map_int_double(std::unordered_map<int, double>& input_map) {

	std::cout << "print_unordered_map_int_double:" << std::endl;
	std::cout << "size(): " << input_map.size() << std::endl;
	for (auto i = input_map.begin(); i != input_map.end(); i++) {
		std::cout << "key: |" << i->first << "|" << " content: |" << i->second << "|" << '\n';
	}
	std::cout << "print_unordered_map_int_double END" << std::endl;
}