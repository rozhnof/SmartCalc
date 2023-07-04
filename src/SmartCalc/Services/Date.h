#pragma once

#include <unordered_map>

class Date {

    enum Months {
        JANUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
    };

    std::unordered_map<Months, int> daysInMonth;

    void SetDaysInMonths() {
        daysInMonth.insert(std::make_pair(JANUARY, 31));
        daysInMonth.insert(std::make_pair(MARCH, 31));
        daysInMonth.insert(std::make_pair(APRIL, 30));
        daysInMonth.insert(std::make_pair(MAY, 31));
        daysInMonth.insert(std::make_pair(JUNE, 30));
        daysInMonth.insert(std::make_pair(JULY, 31));
        daysInMonth.insert(std::make_pair(AUGUST, 31));
        daysInMonth.insert(std::make_pair(SEPTEMBER, 30));
        daysInMonth.insert(std::make_pair(OCTOBER, 31));
        daysInMonth.insert(std::make_pair(NOVEMBER, 30));
        daysInMonth.insert(std::make_pair(DECEMBER, 31));

        setDaysInFebruary();
    }

    int _year;
    int _month;
    int _day;

    void setDaysInFebruary() {
        if (isLeepYear()) {
            daysInMonth.insert(std::make_pair(FEBRUARY, 29));
        } else {
            daysInMonth.insert(std::make_pair(FEBRUARY, 28));
        }
    }

    Date(int year, int month, int day) :_year(year), _month(month), _day(day) {
        SetDaysInMonths();
    }

    bool isLeepYear() {
        if (_year % 4 == 0) {
            return true;
        }
        return false;
    }

    int getDaysInYear() {
        int daysCount = 0;

        for (auto it : daysInMonth) {
            daysCount += it.second;
        }

        return daysCount;
    }

    int getDaysToEndYear() {
        int countDays = 0;

        for (int i = _month; i <= DECEMBER; i++) {
            countDays += daysInMonth[static_cast<Months>(i)];
        }

        countDays -= _day;

        return countDays;
    }

    int getDaysToStartYear() {
        int countDays = 0;

        for (int i = _month; i >= JANUARY; i++) {
            countDays += daysInMonth[static_cast<Months>(i)];
        }

        countDays -= (daysInMonth[static_cast<Months>(_month)] - _day);

        return countDays;
    }

    void addDay() {
        _day++;
        checkAdd();
    }

    void addMonths() {
        _month++;
        checkAdd();
    }

    void addYears() {
        _year++;
        checkAdd();
    }

    void checkAdd() {
        if (_day > daysInMonth[static_cast<Months>(_month)]) {
            _day = 1;
            _month++;
        }
        if (_month > DECEMBER) {
            _month = JANUARY;
            _year++;

            setDaysInFebruary();
        }
    }
};

