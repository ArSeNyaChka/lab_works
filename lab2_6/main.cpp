#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <cctype>

// ============================================================================
// ЗАДАНИЕ 1: Валидация пароля
// ============================================================================

class PasswordError : public std::runtime_error {
public:
    explicit PasswordError(const std::string& msg) : std::runtime_error(msg) {}
};

class LengthError : public PasswordError {
public:
    LengthError() : PasswordError("Ошибка: Длина пароля должна быть не менее 9 символов.") {}
};

class RegisterError : public PasswordError {
public:
    RegisterError() : PasswordError("Ошибка: Пароль должен содержать символы как верхнего, так и нижнего регистра.") {}
};

class DigitError : public PasswordError {
public:
    DigitError() : PasswordError("Ошибка: Пароль должен содержать хотя бы одну цифру.") {}
};

class ForbiddenLetterError : public PasswordError {
public:
    ForbiddenLetterError() : PasswordError("Ошибка: Пароль содержит легко путаемые символы (l, I, 1, o, O, 0).") {}
};

std::string get_password() {
    std::string pwd;
    std::cout << "Введите пароль: ";
    std::cin >> pwd;

    if (pwd.length() < 9) {
        throw LengthError();
    }

    if (pwd.find_first_of("lI1oO0") != std::string::npos) {
        throw ForbiddenLetterError();
    }

    bool has_digit = false;
    bool has_lower = false;
    bool has_upper = false;

    for (char c : pwd) {
        if (std::isdigit(static_cast<unsigned char>(c))) has_digit = true;
        if (std::islower(static_cast<unsigned char>(c))) has_lower = true;
        if (std::isupper(static_cast<unsigned char>(c))) has_upper = true;
    }

    if (!has_digit) {
        throw DigitError();
    }

    // Если нет хотя бы одного регистра, значит все буквы (если они есть) одного регистра
    if (!has_lower || !has_upper) {
        throw RegisterError();
    }

    return pwd;
}

// ============================================================================
// ЗАДАНИЕ 2: Игровая система классов
// ============================================================================

// Собственные исключения для игровой логики
class GameError : public std::runtime_error {
public:
    explicit GameError(const std::string& msg) : std::runtime_error(msg) {}
};

class NoWeaponException : public GameError {
public:
    NoWeaponException() : GameError("Ошибка: У персонажа нет оружия.") {}
};

class InvalidHealException : public GameError {
public:
    InvalidHealException() : GameError("Ошибка: Невозможно полечиться на отрицательное значение.") {}
};

// Прямое объявление для использования в Weapon
class BaseCharacter;

class Weapon {
private:
    std::string name;
    int damage;
    double range;

public:
    Weapon(std::string n = "Кулаки", int d = 5, double r = 1.0) 
        : name(std::move(n)), damage(d), range(r) {}

    void hit(const BaseCharacter& actor, BaseCharacter& target) const {
        if (!target.is_alive()) {
            std::cout << "Враг уже повержен.\n";
            return;
        }

        double dx = target.get_x() - actor.get_x();
        double dy = target.get_y() - actor.get_y();
        double distance = std::sqrt(dx * dx + dy * dy);

        if (distance > range) {
            std::cout << "Враг слишком далеко для оружия " << name << ".\n";
        } else {
            std::cout << "Врагу нанесен урон оружием " << name << " в размере " << damage << ".\n";
            target.get_damage(damage);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Weapon& w) {
        os << w.name;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Weapon& w) {
        std::cout << "Введите имя оружия: ";
        is >> w.name;
        std::cout << "Введите наносимый урон: ";
        is >> w.damage;
        std::cout << "Введите радиус действия: ";
        is >> w.range;
        return is;
    }
};

class BaseCharacter {
protected:
    double pos_x;
    double pos_y;
    int hp;

public:
    BaseCharacter(double x, double y, int health) : pos_x(x), pos_y(y), hp(health) {}
    virtual ~BaseCharacter() = default;

    void move(double delta_x, double delta_y) {
        pos_x += delta_x;
        pos_y += delta_y;
    }

    bool is_alive() const {
        return hp > 0;
    }

    virtual void get_damage(int amount) {
        hp -= amount;
    }

    double get_x() const { return pos_x; }
    double get_y() const { return pos_y; }
    int get_hp() const { return hp; }
};

class BaseEnemy : public BaseCharacter {
private:
    Weapon weapon;

public:
    BaseEnemy(double x, double y, Weapon w, int health)
        : BaseCharacter(x, y, health), weapon(std::move(w)) {}

    void hit(BaseCharacter& target) {
        weapon.hit(*this, target);
    }

    friend std::ostream& operator<<(std::ostream& os, const BaseEnemy& e) {
        os << "Враг на позиции (" << e.pos_x << ", " << e.pos_y << ") с оружием " << e.weapon;
        return os;
    }
};

class MainHero : public BaseCharacter {
private:
    std::string name;
    std::vector<Weapon> inventory;
    size_t current_weapon_idx;

public:
    MainHero(double x, double y, std::string n, int health)
        : BaseCharacter(x, y, health), name(std::move(n)), current_weapon_idx(0) {}

    void hit(BaseEnemy& target) {
        if (inventory.empty()) {
            std::cout << "Я безоружен.\n";
            return;
        }
        inventory[current_weapon_idx].hit(*this, target);
    }

    void add_weapon(const Weapon& w) {
        inventory.push_back(w);
        std::cout << "Подобрал " << w << ".\n";
        if (inventory.size() == 1) {
            current_weapon_idx = 0; // Экипируется сразу же
        }
    }

    void next_weapon() {
        if (inventory.empty()) {
            std::cout << "Я безоружен.\n";
        } else if (inventory.size() == 1) {
            std::cout << "У меня только одно оружие.\n";
        } else {
            current_weapon_idx = (current_weapon_idx + 1) % inventory.size();
            std::cout << "Сменил оружие на " << inventory[current_weapon_idx] << ".\n";
        }
    }

    void heal(int amount) {
        if (amount < 0) {
            throw InvalidHealException();
        }
        hp = std::min(hp + amount, 200);
        std::cout << "Полечился, теперь здоровья " << hp << ".\n";
    }

    std::string get_name() const { return name; }
};

// ============================================================================
// ФУНКЦИЯ MAIN: Демонстрация и тестирование
// ============================================================================

void test_password_system() {
    std::cout << "\n--- Тестирование системы паролей ---\n";
    try {
        std::string valid_pwd = get_password();
        std::cout << "Пароль успешно установлен: " << valid_pwd << "\n";
    } catch (const PasswordError& e) {
        std::cerr << e.what() << "\n";
    }
}

void test_game_system() {
    std::cout << "\n--- Тестирование игровой системы ---\n";
    
    // 1. Создание главного героя
    MainHero hero(0.0, 0.0, "Артур", 100);
    std::cout << "Герой " << hero.get_name() << " создан. Здоровье: " << hero.get_hp() << "\n";

    // 2. Создание врагов
    Weapon sword("Ржавый меч", 15, 2.5);
    Weapon bow("Короткий лук", 10, 5.0);
    
    BaseEnemy enemy1(2.0, 0.0, sword, 40);
    BaseEnemy enemy2(6.0, 0.0, bow, 30);

    std::cout << enemy1 << "\n";
    std::cout << enemy2 << "\n";

    // 3. Битва без оружия
    std::cout << "\n[Действие] Герой пытается атаковать врага 1 без оружия:\n";
    hero.hit(enemy1);

    // 4. Подбор оружия
    std::cout << "\n[Действие] Герой подбирает оружие:\n";
    hero.add_weapon(Weapon("Кинжал", 12, 1.5));
    hero.add_weapon(Weapon("Боевой топор", 25, 2.0));
    hero.add_weapon(Weapon("Магический посох", 30, 4.0));

    // 5. Смена оружия
    std::cout << "\n[Действие] Герой меняет оружие:\n";
    hero.next_weapon();
    hero.next_weapon();

    // 6. Атака врага (успешная)
    std::cout << "\n[Действие] Герой атакует врага 1:\n";
    hero.hit(enemy1);
    std::cout << "Здоровье врага 1: " << enemy1.get_hp() << "\n";

    // 7. Атака врага, который слишком далеко
    std::cout << "\n[Действие] Герой пытается атаковать врага 2 (он далеко):\n";
    hero.hit(enemy2);

    // 8. Лечение
    std::cout << "\n[Действие] Герой получает лечение:\n";
    hero.heal(150); // Должно ограничиться 200
    std::cout << "Здоровье героя: " << hero.get_hp() << "\n";

    // 9. Добивание врага
    std::cout << "\n[Действие] Герой подходит и добивает врага 1:\n";
    hero.move(2.0, 0.0); // Теперь дистанция 0
    hero.hit(enemy1);
    hero.hit(enemy1); // Попытка ударить уже поверженного

    // 10. Враг атакует героя
    std::cout << "\n[Действие] Враг 2 атакует героя:\n";
    enemy2.hit(hero);
    std::cout << "Здоровье героя после атаки: " << hero.get_hp() << "\n";

    // 11. Демонстрация исключений
    std::cout << "\n[Действие] Попытка некорректного лечения:\n";
    try {
        hero.heal(-50);
    } catch (const GameError& e) {
        std::cerr << "Перехвачено исключение: " << e.what() << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Для корректного вывода кириллицы в консоли
    
    std::cout << "=== ЗАДАНИЕ 1 ===\n";
    test_password_system();

    std::cout << "\n=== ЗАДАНИЕ 2 ===\n";
    test_game_system();

    return  a 0;
}
