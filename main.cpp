#include <iostream>
#include <vector>
#include <Windows.h>

class CPU{

public:

	CPU() {
		std::cout << "������� �������������\n";
		std::cin >> producer_;

		std::cout << "������� �����\n";
		std::cin >> socket_;

		std::cout << "������� ���������\n";
		std::cin >> generation_;

		std::cout << "������� �������\n";
		std::cin >> segment_;
		system("cls");



	}

	std::string GetProducer()const {
		return producer_;
	}
	std::string GetSocket()const {
		return socket_;
	}
	int GetSegment()const{
		return segment_;
	}
	int GetGeneration()const {
		return generation_;
	}

	void SetProducer(std::string producer) {
		producer_ = producer;
	}
	void SetSocket(std::string socket) {
		socket_ = socket;
	}
	void SetSegment(int segment) {
		segment_ = segment;
	}
	void SetGeneration(int generation) {
		generation_ = generation;
	}

	void Print()const {
		std::cout << "\n�������������:" << producer_;
		std::cout << "\netr�������: " << segment_;
		std::cout << "\n���������: " << generation_;
		std::cout << "\n�����: " << socket_;
		std::cout << "\n";

	}

	void Collection(CPU &object, std::vector<CPU> &vector) {
		vector.push_back(object);

	}

private:
	std::string producer_;
	std::string socket_;
	int segment_;
	int generation_;

};






int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector <CPU> object;
	CPU ryzen7;
	ryzen7.Collection(ryzen7, object);
	CPU ryzen9;
	ryzen9.Collection(ryzen9, object);
	CPU AMD9;
	AMD9.Collection(AMD9, object);
	CPU AMD7;
	AMD7.Collection(AMD7, object);
	
	for (CPU i : object)
	{
		
		i.Print();
	}




	return 0;
}