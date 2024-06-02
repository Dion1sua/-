#include <iostream>
#include <list>
#include <string>

using namespace std;

class Clock {
public:
    // ������������� ��� ����� �����������
    enum class DisplayStyle { H24, H12 };

private:
    DisplayStyle style;
    int hours;
    int minutes;
    int seconds;

public:
    // ����������� �����
    Clock(DisplayStyle style, int hours, int minutes, int seconds)
        : style(style), hours(hours), minutes(minutes), seconds(seconds) {}

    // ����� ��� ����������� ����
    void showTime() const {
        if (style == DisplayStyle::H24) {
            cout << (hours < 10 ? "0" : "") << hours << ":"
                << (minutes < 10 ? "0" : "") << minutes << ":"
                << (seconds < 10 ? "0" : "") << seconds << " (24-�������� ������)" << endl;
        }
        else {
            int displayHours = hours % 12;
            if (displayHours == 0) displayHours = 12;
            string am_pm = hours < 12 ? "AM" : "PM";
            cout << (displayHours < 10 ? "0" : "") << displayHours << ":"
                << (minutes < 10 ? "0" : "") << minutes << ":"
                << (seconds < 10 ? "0" : "") << seconds << " " << am_pm << " (12-�������� ������)" << endl;
        }
    }

    // ������� ��� ���� (�����������)
    DisplayStyle getStyle() const { return style; }
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    // ������� ��� ���� (�����������)
    void setStyle(DisplayStyle newStyle) { style = newStyle; }
    void setHours(int newHours) { hours = newHours; }
    void setMinutes(int newMinutes) { minutes = newMinutes; }
    void setSeconds(int newSeconds) { seconds = newSeconds; }
};

int main() {
    locale::global(locale("uk_UA.utf8"));

    // ��������� ������ ���������
    list<Clock> clocks;

    // ��������� ��'���� �� ������
    clocks.emplace_back(Clock::DisplayStyle::H24, 14, 30, 45);
    clocks.emplace_back(Clock::DisplayStyle::H12, 9, 15, 30);
    clocks.emplace_back(Clock::DisplayStyle::H24, 23, 59, 59);

    // ��������� ��� ��������� � ������
    cout << "������ ���������:" << endl;
    for (const auto& clock : clocks) {
        clock.showTime();
    }

    // ��������� ������� ��������� � ������
    clocks.pop_front();
    cout << "\nϳ��� ��������� ������� ���������:" << endl;
    for (const auto& clock : clocks) {
        clock.showTime();
    }

    // ��������� ������ ��������� � ����� ������
    clocks.emplace_back(Clock::DisplayStyle::H12, 6, 45, 20);
    cout << "\nϳ��� ��������� ������ ��������� �� ����:" << endl;
    for (const auto& clock : clocks) {
        clock.showTime();
    }

    // ������� ������
    clocks.clear();
    cout << "\nϳ��� ������� ������, ����� ������ ���������: " << clocks.size() << endl;

    return 0;
}
