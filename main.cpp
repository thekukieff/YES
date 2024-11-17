#include <iostream>
#include <vector>
#include <Windows.h>
//namespace пространство имен{
// Представим ситуацию, что вы написали функцию max();
// Но оказывается другой разработчик этого же проекта(или библиотеки, которая подключена к проекту) уже ее написал;
// из-за того что у программы идет описание 2-х одинаковых по названию функций, то она не компилируется (если раскоментировать 33-35 строчки, то будет ошибка);
// но если бы каждый из разработчиков создал свое пространство имен, то ошибок бы не было;
// итак можно сделать вывод, что пространство имен - это область кода который имеет свои переменные и функции;
// 
// пример объявления находится в строке 45;
//  
// В теории существует директива using, которая позволяет ссылаться на любое пространство имен без его имени, но смысл в использовании тогда теряется;
//
// если в когде встретится вот такой синтаксис ::func(), то это просто другой разработчик показывает, что func() находится в глобальном пространстве имен;
// 
// }
// 
//Перечисления enum{
// enum - перечисляемый тип, который служит для объявления символических имен, представляющий целочисленные константы;
// Значение Констант можно не указывать, т.к. если не указать,то первая будет 0, вторая 0+1, третья 0+1+1 и т.д;
// А если указать, то значение первой константы будет x, второй x+1, третья х+1+1 и т.д;
// Использование enum позволяет избегать запоминания всех "магических переменных". Как пример можно вспомнить переменную gender, где любой 1-мальчик 0-девочка;
// В теории можно это запомнить,а если таких возможных значений десятки? Чтобы не запоминать есть enum;
// В switch конструкциях тоже работает;
// 
// 
// 
// 
// 
// }
//


//void max(){}
//
//void max() {}

enum State {//состоние
	OFF,
	ON
};




namespace CPU {//процессоры бывают не только для пк, для ноутов создают отдельные;

	class CPU {

	public:


		CPU() {
			std::cout << "Введите производителя\n";
			std::cin >> producer_;

			std::cout << "Введите сокет\n";
			std::cin >> socket_;

			std::cout << "Введите поколение\n";
			std::cin >> generation_;

			std::cout << "Введите сегмент\n";
			std::cin >> segment_;
			system("cls");



		}
		void Start() {
			state_ = ON;//процессор работает
		}
		void End() {
			state_ = OFF;//комп выключен
		}
		std::string GetProducer()const {
			return producer_;
		}
		std::string GetSocket()const {
			return socket_;
		}
		int GetSegment()const {
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


		void SetState(State state) {
			state_ = state;
		}

		State GetState()const {
			return state_;
		}


		void Print()const {
			std::cout << "\nПроизводитель:" << producer_;
			std::cout << "\netrСегмент: " << segment_;
			std::cout << "\nПоколение: " << generation_;
			std::cout << "\nСокет: " << socket_;
			std::cout << "\n";

		}




		void Collection(CPU& object, std::vector<CPU>& vector) {
			vector.push_back(object);

		}

	private:

		State state_;
		std::string producer_;
		std::string socket_;
		int segment_;
		int generation_;

	};

}

void Check(CPU::CPU procc) {
	if (procc.GetState() == State::ON) {
		std::cout << "Процессор работает\n";
	}
	else if(procc.GetState()==State::OFF){
		std::cout << "Процессор не работает\n";
	}

}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector <CPU::CPU> object;
	CPU::CPU ryzen7;
	//ryzen7.Collection(ryzen7, object);
	//CPU::CPU ryzen9;
	//ryzen9.Collection(ryzen9, object);
	//CPU::CPU AMD9;
	//AMD9.Collection(AMD9, object);
	//CPU::CPU AMD7;
	//AMD7.Collection(AMD7, object);
	

	ryzen7.Start();
	Check(ryzen7);
	ryzen7.End();
	Check(ryzen7);


	for (CPU::CPU i : object)
	{
		
		i.Print();
	}




	return 0;
}
