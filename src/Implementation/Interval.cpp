#include "../Headers/Interval.h"

//Interval constructors
Interval::Interval(int weekday, float start, float end, string type) : weekday(weekday), start(start), end(end), type(std::move(type)) {}
Interval::Interval(const Interval& I) {
    this -> weekday = I.weekday;
    this -> start = I.start;
    this -> end = I.end;
    this -> type = I.type;
}

//Interval getters
int Interval::getWeekDay() const {return weekday;}
float Interval::getStart() const {return start;}
float Interval::getEnd() const {return end;}
string Interval::getType() const {return type;}

//Interval setters
void Interval::setWeekDay(int newWeekDay) {weekday = newWeekDay;}
void Interval::setStart(float newStart) {start = newStart;}
void Interval::setEnd(float newEnd) {end = newEnd;}
void Interval::setType(string newType) {type = std::move(newType);}

bool Interval::operator==(const Interval& I) const {
    if (I.getWeekDay() == weekday) {
        if (I.getStart() <= start) {
            if (I.getEnd() <= end) {
                if (I.getType() == "TP" && type == "TP") {
                    return false;
                }
                else if (I.getType() == "TP" && type == "PL") {
                    return false;
                }
                else if (I.getType() == "PL" && type == "TP") {
                    return false;
                }
                else if (I.getType() == "PL" && type == "PL") {
                    return false;
                }
                else {
                    return true;
                }
            }
            else {
                if (I.getType() == "TP" && type == "TP") {
                    return false;
                }
                else if (I.getType() == "TP" && type == "PL") {
                    return false;
                }
                else if (I.getType() == "PL" && type == "TP") {
                    return false;
                }
                else if (I.getType() == "PL" && type == "PL") {
                    return false;
                }
                else {
                    return true;
                }
            }
        }
        if (I.getStart() >= start) {
            if (I.getEnd() <= end) {
                if (I.getType() == "TP" && type == "TP") {
                    return false;
                }
                else if (I.getType() == "TP" && type == "PL") {
                    return false;
                }
                else if (I.getType() == "PL" && type == "TP") {
                    return false;
                }
                else if (I.getType() == "PL" && type == "PL") {
                    return false;
                }
                else {
                    return true;
                }
            }
            else {
                if (I.getType() == "TP" && type == "TP") {
                    return false;
                }
                else if (I.getType() == "TP" && type == "PL") {
                    return false;
                }
                else if (I.getType() == "PL" && type == "TP") {
                    return false;
                }
                else if (I.getType() == "PL" && type == "PL") {
                    return false;
                }
                else {
                    return true;
                }
            }
        }
    }
    return true;
}
