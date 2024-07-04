#include "../Headers/Schedule.h"

//Schedule constructors
Schedule::Schedule(UC& UCClass, vector<Interval> intervals) : UCClass(UCClass), intervals(std::move(intervals)) {}
Schedule::Schedule(const Schedule &S, const UC& ucClass) : UCClass(ucClass) {
    this -> intervals = S.intervals;
}

//Schedule getters
string Schedule::getCodeUC() const {return UCClass.getcodeUC();}
string Schedule::getClass() const {return UCClass.getClass();}
vector<Interval> Schedule::getIntervals() {return intervals;}

//Schedule setters
void Schedule::setCodeUC(string newCodeUC) const {getCodeUC() = std::move(newCodeUC);}
void Schedule::setClass(string newClass) const {getClass() = std::move(newClass);}
void Schedule::setInterval(const vector<Interval> &newIntervals) {intervals = newIntervals;}

void Schedule::addInterval(Interval& I) {intervals.push_back(I);}

bool Schedule::operator==(Schedule& S) const {
    return S.getCodeUC() == getCodeUC() && S.getClass() == getClass();
}
