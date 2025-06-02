#include <iostream>
#include <cstdlib>  // rand() �Լ��� ����ϱ� ���� ���
#include <ctime>    // time() �Լ��� ����Ͽ� ���� �õ� ����

using namespace std;


// Animal = �⺻ Ŭ���� / �ٸ� ���� Ŭ������ �θ� ����
// makesound() �� move()�� '���� ���� �Լ�' �ݵ�� �ڽ� Ŭ�������� ����!
class Animal {
public:
	// ���� �Լ� : �ڽ� Ŭ�������� �� �Լ��� ������ �� �� �ֵ��� ��.
	virtual void makeSound() const = 0;
	virtual void move() const = 0;

	// �Ҹ��ڵ� �������� ������ �ڽ� Ŭ������ �Ҹ��ڰ� ȣ�� ����
	virtual ~Animal() {}
};


// �ڽ�Ŭ���� Dog, Cat, Cow����
// �� Ŭ�������� makeSound(), move() �Լ����� ������ ��.
class Dog : public Animal {
public:
	void makeSound() const override {
		cout << "�۸�!" << endl;
	}
	void move() const override {
		cout << "�������� �پ��!" << endl;
	}
};

class Cat : public Animal {
public:
	void makeSound() const override {
		cout << "�߿�~" << endl;
	}
	void move() const override {
		cout << "����̰� ��ݻ�� �ɾ��!" << endl;
	}
};

class Cow : public Animal {
public:
	void makeSound() const override {
		cout << "����~" << endl;
	}
	void move() const override {
		cout << "�Ұ� �������� �ɾ��!" << endl;
	}
};


// ZooŬ���������� �������� �����ϰ� ������
class Zoo {
private:
	Animal* animals[10]; // �ִ� 10���� ������ �����ϴ� ������ �迭
	int count = 0;		 // ���� ���� ��(�迭�� �� ���� �ִ���!)
public:
	// Zoo�� ������ �߰��ϴ� �Լ�
	void addAnimal(Animal* animal) {
		if (count < 10) {
			animals[count++] = animal; // ���� �����͸� �迭�� �߰�
		}
		else {
			cout << "�������� ���� á���ϴ�!" << endl;
		}
	}

	// Zoo ���� ��� �������� �ൿ�� �����ϰ� �ϴ� �Լ�
	void performActions() {
		for (int i = 0; i < count; i++) {
			animals[i]->makeSound(); // �� ������ makdSound()�� ȣ��
			animals[i]->move();		 // �� ������ move()�� ȣ��
			cout << endl;
		}
	}

	// Zoo �Ҹ���: ����� ��� ������ ����(�޸� ���� ����)
	~Zoo() {
		for (int i = 0; i < count; i++) {
			delete animals[i]; // new�� ���� ��ü�� delete
		}
		cout << "Zoo�� �Ҹ�Ǹ� ��� ������ �����Ǿ����ϴ�." << endl;
	}
};

// �������� Dog, Cat, Cow �� �ϳ��� �����ؼ� ��ȯ�ϴ� �Լ�
Animal* createRandomAnimal() {
	int randNum = rand() % 3; // 0~2 �� �ϳ��� ���� ����
	if (randNum == 0) {
		return new Dog(); // Dog��ü�� �������� ����
	}
	else if (randNum == 1) {
		return new Cat(); // Cat
	}
	else {
		return new Cow(); // Cow
	}
}

int main() {
	srand(time(0)); // ���� �ð��� ������� ���� �õ� ����
	// ������ �׻� �����س� �� �ð��� �������� �ϸ� ���ʸ��� �޶����� Ư���� �Ź� �ٸ� ���� ���´ٰ� �ϳ׿�..
	Zoo zoo; // ������ ��ü
	
	// �����ϰ� ���� 5������ �����ؼ� �������� �߰�
	for (int i = 0; i < 5;i++) {
		Animal* a = createRandomAnimal(); // ���� ����
		zoo.addAnimal(a);				  // �������� �߰�
	}

	cout << "=== ������ �ൿ ����===" << endl;
	zoo.performActions(); // �������� �ִ� ��� ������ �Ҹ����� ������

	return 0;
}