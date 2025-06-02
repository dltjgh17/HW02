#include <iostream>
#include <cstdlib>  // rand() 함수를 사용하기 위한 헤더
#include <ctime>    // time() 함수를 사용하여 랜덤 시드 설정

using namespace std;


// Animal = 기본 클래스 / 다른 동물 클래스의 부모 역할
// makesound() 와 move()는 '순수 가상 함수' 반드시 자식 클래스에서 구현!
class Animal {
public:
	// 가상 함수 : 자식 클래스에서 이 함수를 재정의 할 수 있도록 함.
	virtual void makeSound() const = 0;
	virtual void move() const = 0;

	// 소멸자도 가상으로 만들어야 자식 클래스의 소멸자가 호출 가능
	virtual ~Animal() {}
};


// 자식클래스 Dog, Cat, Cow선언
// 각 클래스들은 makeSound(), move() 함수들을 재정의 함.
class Dog : public Animal {
public:
	void makeSound() const override {
		cout << "멍멍!" << endl;
	}
	void move() const override {
		cout << "강아지가 뛰어요!" << endl;
	}
};

class Cat : public Animal {
public:
	void makeSound() const override {
		cout << "야옹~" << endl;
	}
	void move() const override {
		cout << "고양이가 살금살금 걸어요!" << endl;
	}
};

class Cow : public Animal {
public:
	void makeSound() const override {
		cout << "음메~" << endl;
	}
	void move() const override {
		cout << "소가 느릿느릿 걸어요!" << endl;
	}
};


// Zoo클래스에서는 동물들을 저장하고 관리함
class Zoo {
private:
	Animal* animals[10]; // 최대 10마리 동물을 저장하는 포인터 배열
	int count = 0;		 // 현재 동물 수(배열에 몇 마리 있는지!)
public:
	// Zoo에 동물을 추가하는 함수
	void addAnimal(Animal* animal) {
		if (count < 10) {
			animals[count++] = animal; // 동물 포인터를 배열에 추가
		}
		else {
			cout << "동물원이 가득 찼습니다!" << endl;
		}
	}

	// Zoo 안의 모든 동물들이 행동을 수행하게 하는 함수
	void performActions() {
		for (int i = 0; i < count; i++) {
			animals[i]->makeSound(); // 각 동물의 makdSound()를 호출
			animals[i]->move();		 // 각 동물의 move()를 호출
			cout << endl;
		}
	}

	// Zoo 소멸자: 저장된 모든 동물을 삭제(메모리 누수 방지)
	~Zoo() {
		for (int i = 0; i < count; i++) {
			delete animals[i]; // new로 만든 객체를 delete
		}
		cout << "Zoo가 소멸되며 모든 동물이 삭제되었습니다." << endl;
	}
};

// 랜덤으로 Dog, Cat, Cow 중 하나를 생성해서 반환하는 함수
Animal* createRandomAnimal() {
	int randNum = rand() % 3; // 0~2 중 하나의 숫자 생성
	if (randNum == 0) {
		return new Dog(); // Dog객체를 동적으로 생성
	}
	else if (randNum == 1) {
		return new Cat(); // Cat
	}
	else {
		return new Cow(); // Cow
	}
}

int main() {
	srand(time(0)); // 현재 시간을 기반으로 난수 시드 설정
	// 난수를 항상 생성해낼 때 시간을 기준으로 하면 매초마다 달라지는 특성상 매번 다른 수가 나온다고 하네요..
	Zoo zoo; // 동물원 객체
	
	// 랜덤하게 동물 5마리를 생성해서 동물원에 추가
	for (int i = 0; i < 5;i++) {
		Animal* a = createRandomAnimal(); // 동물 생성
		zoo.addAnimal(a);				  // 동물원에 추가
	}

	cout << "=== 동물원 행동 시작===" << endl;
	zoo.performActions(); // 동물원에 있는 모든 동물이 소리내고 움직임

	return 0;
}