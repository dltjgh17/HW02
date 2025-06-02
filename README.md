# 🐾 C++ 클래스 & 포인터 입문 정리


## 📌 학습 목표

- C++에서 클래스 구조를 이해한다.
- 접근 제한자(`public`, `private`)의 개념을 안다.
- 포인터와 동적 메모리 할당을 이해한다.
- 가상함수와 다형성의 기초를 학습한다.
- 추상 클래스와 순수 가상 함수의 개념을 실습한다.

---

## 🧱 클래스란?

클래스(Class)는 관련된 변수와 함수를 묶는 사용자 정의 타입입니다.

```cpp
class Dog {
public:
    void bark() {
        cout << "멍멍!" << endl;
    }
};
````

### ✅ 클래스 구성 요소

* **멤버 변수**: 클래스가 가지고 있는 데이터 (예: `name`, `age`)
* **멤버 함수**: 클래스가 수행하는 행동 (예: `makeSound()`)

---

## 🔐 접근 제한자

| 제한자       | 설명              | 외부 접근 |
| --------- | --------------- | ----- |
| `public`  | 클래스 외부에서 접근 가능  | ✅ 가능  |
| `private` | 클래스 내부에서만 접근 가능 | ❌ 불가  |

```cpp
class Cat {
public:
    string name;         // 외부에서 접근 가능
private:
    int age;             // 외부에서는 접근 불가
};
```

---

## 📦 생성자와 소멸자

* **생성자**: 객체가 생성될 때 자동 호출됨 (`클래스 이름과 같음`)
* **소멸자**: 객체가 소멸될 때 자동 호출됨 (`~클래스이름()`)

```cpp
class Animal {
public:
    Animal() { cout << "동물 생성됨" << endl; }
    ~Animal() { cout << "동물 소멸됨" << endl; }
};
```

---

## 🧠 포인터란?

* 변수의 **메모리 주소를 저장하는 변수**
* `*` : 값을 역참조 (포인터가 가리키는 값을 가져옴)
* `&` : 변수의 주소를 가져옴

```cpp
int x = 10;
int* p = &x;

cout << *p; // 10
```

---

## 🔁 동적 메모리 할당 (new & delete)

* `new`: 동적으로 객체 생성 (Heap 영역)
* `delete`: 동적으로 생성한 객체를 해제 (필수)

```cpp
Dog* d = new Dog();  // 동적 생성
d->bark();           // 포인터로 함수 호출
delete d;            // 해제
```

---

## 🧬 가상 함수 & 다형성 (Polymorphism)

### ✅ 기본 구조

```cpp
class Animal {
public:
    virtual void makeSound() const = 0; // 순수 가상 함수
};
```

* `= 0`: 순수 가상 함수 → 이 클래스는 **추상 클래스**가 됨
* 반드시 자식 클래스에서 오버라이딩해야 함

```cpp
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "멍멍!" << endl;
    }
};
```

---

## 🦁 실습: 동물원 예제

### Animal 추상 클래스와 자식 클래스

```cpp
class Animal {
public:
    virtual void makeSound() const = 0;
    virtual void move() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void makeSound() const override { cout << "멍멍!" << endl; }
    void move() const override { cout << "뛰어요!" << endl; }
};

// Cat, Cow도 비슷하게 정의
```

---

## 🏛️ Zoo 클래스

```cpp
class Zoo {
private:
    Animal* animals[10]; // 포인터 배열
    int count = 0;

public:
    void addAnimal(Animal* animal) {
        if (count < 10) animals[count++] = animal;
    }

    void performActions() {
        for (int i = 0; i < count; i++) {
            animals[i]->makeSound();
            animals[i]->move();
        }
    }

    ~Zoo() {
        for (int i = 0; i < count; i++) {
            delete animals[i];
        }
    }
};
```

---

## 🎲 랜덤 동물 생성 함수

```cpp
Animal* createRandomAnimal() {
    int r = rand() % 3;
    if (r == 0) return new Dog();
    else if (r == 1) return new Cat();
    else return new Cow();
}
```

---

## 🚀 main() 예제

```cpp
int main() {
    srand(time(0));
    Zoo zoo;

    for (int i = 0; i < 5; i++) {
        zoo.addAnimal(createRandomAnimal());
    }

    zoo.performActions();
    return 0;
}
```

---

## 🧾 요약 정리

| 개념         | 설명                               |
| ---------- | -------------------------------- |
| 클래스        | 데이터와 행동을 묶은 사용자 정의 타입            |
| 접근 제한자     | public은 외부 접근 가능, private은 내부 전용 |
| 포인터        | 다른 변수의 메모리 주소를 저장                |
| new/delete | 동적 객체 생성/해제                      |
| 가상 함수      | 부모 클래스에서 선언, 자식 클래스에서 재정의        |
| 추상 클래스     | 순수 가상 함수를 포함한 클래스                |
| 다형성        | 부모 포인터로 자식 객체를 자유롭게 사용 가능        |

---

