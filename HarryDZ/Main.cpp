#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<chrono>



int main() {
	setlocale(LC_ALL, "ru");

	//===========================Коллекция Set====================================

	std::ifstream file("J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt");
	if (!file.is_open()) {
		std::cerr << "Ошибка открытия файла";
		return 1;
	}

	std::set<std::string>uniqueWords_set;
	
	std::string word_set;
	auto start_set = std::chrono::high_resolution_clock::now();
	while (file >> word_set) {
		word_set.erase(std::remove_if(word_set.begin(), word_set.end(), ispunct), word_set.end());
		word_set.erase(std::remove_if(word_set.begin(), word_set.end(), isdigit), word_set.end());
		std::transform(word_set.begin(), word_set.end(), word_set.begin(), ::tolower);
		uniqueWords_set.insert(word_set);
	}
	file.close();
	auto end_set = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_set = end_set - start_set;

	for (const auto w : uniqueWords_set) {
		std::cout << w << std::endl;
	}
	

	//===================================Коллекция vector========================================
	std::cout << "=====================================================================\n";
	std::ifstream file2("J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt");
	if (!file2.is_open()) {
		std::cerr << "Ошибка открытия файла";
		return 1;
	}

	std::vector<std::string>uniqueWords_vec;

	std::string word_vec;
	auto start_vec = std::chrono::high_resolution_clock::now();
	while (file2 >> word_vec) {
		word_vec.erase(std::remove_if(word_vec.begin(), word_vec.end(), ispunct), word_vec.end());
		word_vec.erase(std::remove_if(word_vec.begin(), word_vec.end(), isdigit), word_vec.end());
		std::transform(word_vec.begin(), word_vec.end(), word_vec.begin(), ::tolower);
		if (std::find(uniqueWords_vec.begin(), uniqueWords_vec.end(), word_vec) == uniqueWords_vec.end()) {
			uniqueWords_vec.push_back(word_vec);
		}
	}

	file.close();
	auto end_vec = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration_vec = end_vec - start_vec;

	for (const auto w : uniqueWords_vec) {
		std::cout << w << std::endl;
	}
	std::cout << "Уникальных слов set " << uniqueWords_set.size() << std::endl;
	std::cout << "Время выполнения используя set: " << duration_set.count() << " секунд" << std::endl;

	std::cout << "Уникальных слов vec " << uniqueWords_vec.size() << std::endl;
	std::cout << "Время выполнения используя vector: " << duration_vec.count() << " секунд" << std::endl;
	return 0;
}