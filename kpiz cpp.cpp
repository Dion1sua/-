#include <iostream>
#include <list>
#include <string>

using namespace std;

class Clock {
public:
    // Перерахування для стилю відображення
    enum class DisplayStyle { H24, H12 };

private:
    DisplayStyle style;
    int hours;
    int minutes;
    int seconds;

public:
    // Конструктор класу
    Clock(DisplayStyle style, int hours, int minutes, int seconds)
        : style(style), hours(hours), minutes(minutes), seconds(seconds) {}

    // Метод для відображення часу
    void showTime() const {
        if (style == DisplayStyle::H24) {
            cout << (hours < 10 ? "0" : "") << hours << ":"
                << (minutes < 10 ? "0" : "") << minutes << ":"
                << (seconds < 10 ? "0" : "") << seconds << " (24-годинний формат)" << endl;
        }
        else {
            int displayHours = hours % 12;
            if (displayHours == 0) displayHours = 12;
            string am_pm = hours < 12 ? "AM" : "PM";
            cout << (displayHours < 10 ? "0" : "") << displayHours << ":"
                << (minutes < 10 ? "0" : "") << minutes << ":"
                << (seconds < 10 ? "0" : "") << seconds << " " << am_pm << " (12-годинний формат)" << endl;
        }
    }

    // Геттери для полів (опціонально)
    DisplayStyle getStyle() const { return style; }
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    // Сеттери для полів (опціонально)
    void setStyle(DisplayStyle newStyle) { style = newStyle; }
    void setHours(int newHours) { hours = newHours; }
    void setMinutes(int newMinutes) { minutes = newMinutes; }
    void setSeconds(int newSeconds) { seconds = newSeconds; }
};

int main() {
    locale::global(locale("uk_UA.utf8"));

    // Створення списку годинників
    list<Clock> clocks;

    // Додавання об'єктів до списку
    clocks.emplace_back(Clock::DisplayStyle::H24, 14, 30, 45);
    clocks.emplace_back(Clock::DisplayStyle::H12, 9, 15, 30);
    clocks.emplace_back(Clock::DisplayStyle::H24, 23, 59, 59);

    // Виведення всіх годинників у списку
    cout << "Список годинників:" << endl;
    for (const auto& clock : clocks) {
        clock.showTime();
    }

    // Видалення першого годинника зі списку
    clocks.pop_front();
    cout << "\nПісля видалення першого годинника:" << endl;
    for (const auto& clock : clocks) {
        clock.showTime();
    }

    // Додавання нового годинника в кінець списку
    clocks.emplace_back(Clock::DisplayStyle::H12, 6, 45, 20);
    cout << "\nПісля додавання нового годинника до кінця:" << endl;
    for (const auto& clock : clocks) {
        clock.showTime();
    }

    // Очистка списку
    clocks.clear();
    cout << "\nПісля очистки списку, розмір списку годинників: " << clocks.size() << endl;

    return 0;
}
